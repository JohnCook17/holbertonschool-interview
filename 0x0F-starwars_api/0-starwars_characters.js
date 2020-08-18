#!/usr/bin/node

const request = require('request');

const myArgs = process.argv.slice(2, 3);
const options = {
  url: 'https://swapi-api.hbtn.io/api/films/' + myArgs,
  method: 'GET'
};

if (Number.isInteger(parseInt(myArgs, 10))) {
  request(options, (err, res, body) => {
    if (err) {
      return console.log(err);
    }
    const obj = JSON.parse(body);
    for (let i = 0; i < obj.characters.length; i++) {
      request(obj.characters[i], (err, res, body) => {
        if (err) {
          return console.log(err);
        }
        console.log(JSON.parse(body).name);
      });
    }
  });
}
