process.stdout.write('please input some number:')
process.stdin.resume();
process.stdin.on('data', function(data) {
    process.stdout.write('read from console: ' + data.toString());
});
