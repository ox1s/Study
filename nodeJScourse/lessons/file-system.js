const fs = require('fs');
const path = require('path');

// fs.mkdirSync(path.resolve(__dirname, 'dir1', 'dir2', 'dir3'), {recursive: true});

/* console.log('Start');

fs.mkdir(path.resolve(__dirname, 'dir'), (err) => {
    if(err) {
        console.log(err);
        return;
    }
   
    console.log('Создан');
});

console.log('End'); */

fs.rmdir(path.resolve(__dirname, 'dir'), {recursive: true}, (err) => {
    if(err) {
        throw err;
    }
    console.log('Удален');
})