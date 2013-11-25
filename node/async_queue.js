var async = require('async')

// create a queue object with concurrency 2

try {
var q = async.queue(function (task, callback) {
    //console.log('hello ' + task.name);
    callback(null, task.name);
}, 2);


// assign a callback
q.drain = function() {
    console.log('all items have been processed');
}

// add some items to the queue

q.push({name: 'foo'}, function (err, name) {
    console.log('finished processing ' + name);
});
q.push({name: 'bar'}, function (err, name) {
    console.log('finished processing ' + name);
});

// add some items to the queue (batch-wise)

q.push([{name: 'baz'},{name: 'bay'},{name: 'bax'}], function (err, name) {
    console.log('finished processing ' + name);
    q.push([{name: '123'},{name: '456'},{name: '789'}], function (err, name) {
        console.log('finished processing ' + name);
    });
});

// add some items to the front of the queue

q.unshift({name: 'bar1'}, function (err, name) {
    console.log('finished processing ' + name);
});

} catch (e) {
    console.error(e.stack)
} finally {
    console.log("this is finally") }
