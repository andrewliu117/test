var cluster = require('cluster')
var os = require('os')
var http = require('http')

var numCPUs = os.cpus().length;

var workers = {};
if (cluster.isMaster) {
    cluster.on('death', function(worker) {
        delete workers[worker.pid];
        worker = cluster.fork();
        workers[worker.pid] = worker;
    });

    for (var i=0; i < numCPUs; i++) {
        var worker = cluster.fork();
        workers[worker.pid] = worker;
    }
} else {
    var app = require('./app');
    http.createServer(app).listen(app.get('port'), function(){
        console.log('Express server listening on port ' + app.get('port'));
    });
}

process.on('SIGTERM', function() {
    for (var pid in workers) {
        process.kill(pid);
    }
    process.exit();
});

