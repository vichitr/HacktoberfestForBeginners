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
    /* Matches a string that starts with 'Mr.', 'Mrs.', 'Ms.', 'Dr.', or 'Er.',
     * followed by one or more letters. */
    return /^(?:Mr|Mrs|Ms|Dr|Er)\.[a-zA-Z]+$/;
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const re = regexVar();
    const s = readLine();

    console.log(!!s.match(re));
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
