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
 * Finds the second largest value in the array, in one pass.
 * If the array only has one distinct element, returns that element.
 */
function getSecondLargest(nums) {
    let largest = Number.MIN_VALUE;
    let secondLargest = Number.MIN_VALUE;

    for (let num of nums) {
        if (num > largest) {
            secondLargest = largest
            largest = num;
        } else if (num > secondLargest && num < largest) {
            secondLargest = num;
        }
    }

    if (secondLargest == Number.MIN_VALUE) {
        return largest; // only one distinct element
    } else {
        return secondLargest;
    }
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const n = +(readLine());
    const nums = readLine().split(' ').map(Number);

    console.log(getSecondLargest(nums));
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
