#!/usr/bin/node

let request = require('request');

let myArgs = process.argv.slice(2, 3);
const options = {
  url: 'https://swapi-api.hbtn.io/api/films/' + myArgs,
  method: 'GET'
};

request(options, (err, res, body) => {
  if (err) {
    return console.log(err);
  }
  let obj = JSON.parse(body);
  for (let i = 0; i < obj.characters.length; i++) {
    request(obj.characters[i], (err, res, body) => {
      if (err) {
        return console.log(err);
      }
      console.log(JSON.parse(body).name);
    });
  }
});
