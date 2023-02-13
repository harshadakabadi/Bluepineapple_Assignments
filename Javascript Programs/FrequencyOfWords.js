var fs = require('fs');
var contents = fs.readFileSync('textfile.txt', 'utf8');
var words = contents.split(" ");
var wordCounts = {};

for (var i = 0; i < words.length; i++) {
  var word = words[i].toLowerCase();
  if (wordCounts[word] === undefined) {
    wordCounts[word] = 1;
  } else {
    wordCounts[word]++;
  }
}

console.log(wordCounts);

