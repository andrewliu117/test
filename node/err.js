var fs = require('fs');

err = "haha\n"
console.log(err.trim())
var errobj = new Error(err);

console.log(errobj)
console.log(errobj.message)

var find = true
if (!find) {
    console.log("!find")
}

console.log(process.env.HOME)

var os = require("os");
console.log(os.hostname())

var home = process.env.HOME;

//fs.stat(home, function (err, stats) {
//    console.log(stats)
//    console.log(parseInt(stats.mode.toString(8), 10))
//    console.log(parseInt ((stats.mode & parseInt ("777", 8)).toString(8)))
//    console.log((stats.mode & parseInt ("777", 8)).toString(8))
//});

//var checkPermission = function (file, mask, cb){
//    fs.stat (file, function (error, stats){
//        if (error){
//            cb (error, false);
//        }else{
//            cb (null, !!(mask & parseInt ((stats.mode & parseInt ("777", 8)).toString (8)[0])));
//        }
//    });
//};


var a = [1, 2, 3, 4, 5]

console.log(a.length);

var total = 0;

a.forEach(function (val) {
    console.log(val);
    total += val
})

console.log(total)

for (obj in a) {
    console.log('----')
    console.log(obj)
}


var b = {
    f:'abc',
    d:{k:'1', m:'3'},
    e:{l:'3', x:'7'}
}

for (val in b) {
    console.log(b[val])
}

var str = '%editor'
console.log(str[0])
console.log(str)
console.log(str.substr(1))

var astr;
var bstr;
astr = bstr = str;
console.log(astr)
console.log(bstr)

setTimeout(function () {
    console.log("timeout");
}, 1000);
