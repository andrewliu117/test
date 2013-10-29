
/*
 * GET home page.
 */

var crypto = require('crypto')

var User = require('./user');
//exports.index = function(req, res){
//  res.render('index', { title: 'Express' });
//};
//
//exports.user = function(req, res){
//};
//
//exports.post = function(req, res){
//};
//
//exports.reg = function(req, res){
//};
//
//exports.doReg = function(req, res){
//};
//
//exports.login = function(req, res){
//};
//
//exports.doLogin = function(req, res){
//};
//
//exports.logout = function(req, res){
//};

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

	app.post('/reg', function(req, res) {
		if (req.body['password-repeat'] != req.body['password']) {
			req.session.error = '两次输入的口令不一致';
			return res.redirect('/reg');
		}

		var md5 = crypto.createHash('md5');
		var password = md5.update(req.body.password).digest('bash64');

		var newUser = new User({
			name: req.body.username,
			password: password,
		});

		User.get(newUser.name, function(err, user) {
			if (user)
				err = 'Username already exists 用户已经存在!';
			if (err) {
				req.session.error = err;
				return res.redirect('/reg');
			}

			newUser.save(function(err) {
				if (err) {
					req.session.error = err;
					return res.redirect('/reg');
				}
				req.session.user = newUser;
				req.session.success = '注册成功';
				res.redirect('/');
			});
		});
	});

	app.get('/login', function(req, res) {
		res.render('login',{
			title:'用户登入',
		});
	});

	app.post('/login', function(req, res) {
		var md5 = crypto.createHash('md5');
		var password = md5.update(req.body.password).digest('bash64');

		User.get(req.body.username, function(err, user) {
			if (!user) {
				req.session.error = '用户不存在';
				return res.redirect('/login');
			}
			if (user.password != password) {
				req.session.error = '用户口令错误';
			}

			req.session.user = user;
			req.session.success = '登入成功';
			res.redirect('/');
		});
	});

	app.get('/logout', function(req,res){
		req.session.user = null;
		req.session.success = '登出成功';
		res.redirect('/');
	})
};

