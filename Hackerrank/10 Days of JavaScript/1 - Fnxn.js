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

function factorial(n) {
    if (n < 0) {
        throw "Input to 'factorial()' must be non-negative";
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const n = +(readLine());

    console.log(factorial(n));
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
