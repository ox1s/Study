const path = require('path');

console.log('Склеить участки пути', path.join(__dirname, 'second'));
console.log('Получить абсолютный путь', path.resolve(__dirname, 'second'));
const fullPath = path.resolve(__dirname, 'second.js');
console.log('Парсинг пути', path.parse(fullPath));
console.log('разделитель в ОС' , path.sep);
console.log('Проверка на то, что путь является абсолютным', path.isAbsolute(fullPath));
console.log('Название файла',path.basename(fullPath));
console.log('расширение файла',path.extname(fullPath));


// -------------------

const siteURL = 'https://localhost:3000/users?id=5123';

const url = new URL(siteURL);

console.log('Парсинг URL', url);