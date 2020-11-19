#!/usr/bin/node

const request = require('request');

const MovieNum = process.argv.slice(2, 3);

// console.log(MovieNum);

const film = {
  url: 'https://swapi-api.hbtn.io/api/films/'.concat(MovieNum),
  method: 'GET'
};

// console.log(film)

function printThis (body) {
  return new Promise((resolve) => {
    resolve(console.log(JSON.parse(body).name));
  });
}

request(film, async function (err, res, body) {
  if (err) { return console.log(err); }
  const characters = JSON.parse(body).characters;

  // console.log(characters);

  for (const i in characters) {
    await new Promise((resolve) => request(characters[i], async function (err, res, body) {
      if (err) { return console.log(err); }
      const wait = await printThis(body);
      resolve(wait);
    }));
  }
});
