#!/usr/bin/node

const request = require('request');

function luke (obj, i) {
  return new Promise((resolve, reject) => {
    request(obj.characters[i], (err, res, body) => {
      if (err) {
        reject(err);
        return console.log(err);
      }
      resolve(JSON.parse(body).name);
    })
  });
};

function obiwan () {
  const request = require('request');

  const myArgs = process.argv.slice(2, 3);
  const options = {
    url: 'https://swapi-api.hbtn.io/api/films/' + myArgs,
    method: 'GET'
  };

  if (Number.isInteger(parseInt(myArgs, 10))) {
    request(options, async (err, res, body) => {
      if (err) {
        return console.log(err);
      }
      const obj = JSON.parse(body);
      //console.log(obj);
      for (let i = 0; i < obj.characters.length; i++) {
        let character = await luke(obj, i);
        console.log(character);
      }
    });
  }
}

obiwan();
