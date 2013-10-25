function dosomething(args, callback) {
    console.log("abc");
    callback();
}

dosomething('a', function onEnd() {
    console.log('computing');
});
