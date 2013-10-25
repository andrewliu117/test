
/**
 * Module dependencies.
 */

var express = require('express');
var routes = require('./routes');
var user = require('./routes/user');
var http = require('http');
var path = require('path');

var app = express();

var users = {'abc':'wahaha', '123':'yes it is'}

// all environments
app.set('port', process.env.PORT || 3000);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');
app.use(express.favicon());
app.use(express.logger('dev'));
app.use(express.bodyParser());
app.use(express.methodOverride());
app.use(app.router);
app.use(express.static(path.join(__dirname, 'public')));

// development only
if ('development' == app.get('env')) {
  app.use(express.errorHandler());
}

app.get('/', routes.index);
app.get('/users', user.list);
app.get('/hello', routes.hello);
app.get('/user/:username', function (req, res, next) {
    if (users[req.params.username]) {
        next();
    } else {
        next(new Error(req.params.username + ' does not exist'));
    }
});

app.get('/user/:username', function (req, res) {
    res.send('Done');
});
app.get('/user/:username', function (req, res, next) {
    res.send('user: ' + req.params.username);
    next();
});

http.createServer(app).listen(app.get('port'), function(){
  console.log('Express server listening on port ' + app.get('port'));
});
