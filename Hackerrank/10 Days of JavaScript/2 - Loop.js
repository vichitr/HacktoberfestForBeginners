/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });

    main();
});

function readLine() {
    return inputString[currentLine++];
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

function isVowel(ch) {
    ch = ch.toLowerCase();
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

function vowelsAndConsonants(s) {
    let vowels = [];
    let consonants = [];

    for (let ch of s) {
        if (isVowel(ch)) {
            vowels.push(ch);
        } else {
            consonants.push(ch);
        }
    }

    console.log(vowels.join('\n'));
    console.log(consonants.join('\n'));
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const s = readLine();

    vowelsAndConsonants(s);
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
