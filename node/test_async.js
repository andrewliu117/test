var async = require('async')

var a = function (callback){
    setTimeout(function(){
        callback(null, 'one');
    }, 200);
}
    
var b = function(callback){
    setTimeout(function(){
        callback(null, 'two');
    }, 100);
}

async.parallel([a, b],
// optional callback
//function(err, results){
//    console.log(results);
//    // the results array will equal ['one','two'] even though
//    // the second function had a shorter timeout.
//});
function(err){
    console.log('no err!');
    // the results array will equal ['one','two'] even though
    // the second function had a shorter timeout.
});

var a = {}
a.fuck = 3;
console.log(a);

a.dis = {val: 3, err:'this is an err', ok: null}
console.log(a);

