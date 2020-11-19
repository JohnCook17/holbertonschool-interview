#!/usr/bin/node

const request = require('request'); 

const movie_num = console.log(process.argv[2]);

console.log(movie_num);

const characters = {
    url: 'https://swapi-api.hbtn.io/api/films/' + movie_num
};

request(characters, function(err, res, body){
    let json = JSON.parse(body);
    console.log(json);
});
