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

function greeting(message) {
    console.log('Hello, World!');
    console.log(message);
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const parameterVariable = readLine();

    greeting(parameterVariable);
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
