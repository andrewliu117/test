var http = require("http")

http.createServer(function(req, res) {
	res.writeHead(200, {'Content-Type':'text/html'});
	res.write('<h1>Node.js</h1>');
	res.write('<p>Hello world! lhj</p>');
	res.end();
}).listen(8888);

console.log("HTTP server is started at port 8888:");
