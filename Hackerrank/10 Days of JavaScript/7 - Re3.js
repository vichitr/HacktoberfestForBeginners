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

function regexVar() {
    /* Matches ALL occurrences of numbers in a string. */
    return /(\d)+/g;
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const re = regexVar();
    const s = readLine();

    const r = s.match(re);

    for (const e of r) {
        console.log(e);
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
