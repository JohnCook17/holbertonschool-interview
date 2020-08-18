#!/usr/bin/node

var request = require('request');

var myArgs = process.argv.slice(2, 3);
const options = {
  url: 'https://swapi-api.hbtn.io/api/films/' + myArgs,
  method: 'GET'
};

request(options, (err, res, body) => {
  if (err) {
    return console.log(err);
  }
  var obj = JSON.parse(body);
  for (var i = 0; i < obj.characters.length; i++) {
    request(obj.characters[i], (err, res, body) => {
      if (err) {
        return console.log(err);
      }
      console.log(JSON.parse(body).name);
    });
  }
});
