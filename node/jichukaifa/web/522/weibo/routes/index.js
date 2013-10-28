
/*
 * GET home page.
 */

exports.index = function(req, res){
  res.render('index', { title: 'Express' });
};

exports.user = function(req, res){
};

exports.post = function(req, res){
};

exports.reg = function(req, res){
};

exports.doReg = function(req, res){
};

exports.login = function(req, res){
};

exports.doLogin = function(req, res){
};

exports.logout = function(req, res){
};

module.exports = function(app) {
    app.get('/', function(req, res) {
        res.render('index', {
            title: '首页'
        });
    });

    app.get('/reg', function(req, res){
        res.render('reg', {
            title:'用户注册'
        });
    });
};

