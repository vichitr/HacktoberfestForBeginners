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

function main() {
    const PI = Math.PI;
    const r = parseFloat(readLine());

    console.log(PI * (r ** 2));
    console.log(2 * PI * r);

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
    try {
        // Attempt to redefine the value of constant variable PI
        PI = 0;
        // Attempt to print the value of PI
        console.log(PI);
    } catch(error) {
        console.error("You correctly declared 'PI' as a constant.");
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
