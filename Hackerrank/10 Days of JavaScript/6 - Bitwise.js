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
 * See the Discussion tab on HackerRank for some explanations of this solution.
 */
function getMaxLessThanK(n, k) {
    return (((k - 1) | k) <= n) ? (k - 1) : (k - 2);
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const q = +(readLine());

    for (let i = 0; i < q; i++) {
        const [n, k] = readLine().split(' ').map(Number);

        console.log(getMaxLessThanK(n, k));
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
