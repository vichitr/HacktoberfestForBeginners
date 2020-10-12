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

/**
 * Doubles all even numbers in the array, and triples all odd numbers.
 */
function modifyArray(nums) {
    return nums.map(n => (n % 2 == 0) ? (n * 2) : (n * 3));
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const n = +(readLine());
    const a = readLine().split(' ').map(Number);

    console.log(modifyArray(a).toString().split(',').join(' '));
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
