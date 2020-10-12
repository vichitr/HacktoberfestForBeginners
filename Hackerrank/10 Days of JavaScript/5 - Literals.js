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

/*
 * Determine the original side lengths and return an array:
 * - The first element is the length of the shorter side
 * - The second element is the length of the longer side
 *
 * Parameters:
 *   strings: The tagged template literal's array of strings.
 *   values: An array of: [area, perimeter].
 */
function sides(strings, ...values) {
    const A = values[0];
    const P = values[1];
    const s1 = (P + (P ** 2 - (16 * A)) ** 0.5) / 4;
    const s2 = A / s1;
    return [s1, s2].sort();
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    let s1 = +(readLine());
    let s2 = +(readLine());

    [s1, s2] = [s1, s2].sort();

    const [x, y] = sides`The area is: ${s1 * s2}.\nThe perimeter is: ${2 * (s1 + s2)}.`;

    console.log((s1 === x) ? s1 : -1);
    console.log((s2 === y) ? s2 : -1);
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
