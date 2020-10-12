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

function getLetter(s) {
    const aSet = new Set(['a', 'e', 'i', 'o', 'u']);
    const bSet = new Set(['b', 'c', 'd', 'f', 'g']);
    const cSet = new Set(['h', 'j', 'k', 'l', 'm']);
    const dSet = new Set(['n', 'p', 'q', 'r', 's',
                          't', 'v', 'w', 'x', 'y', 'z']);

    let letter;
    const firstChar = s.charAt(0);
    switch (true) {
        case aSet.has(firstChar):
            letter = 'A';
            break;
        case bSet.has(firstChar):
            letter = 'B';
            break;
        case cSet.has(firstChar):
            letter = 'C';
            break;
        case dSet.has(firstChar):
            letter = 'D';
            break;
        default:
            throw "Unexpected first character"
    }
    return letter;
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const s = readLine();

    console.log(getLetter(s));
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
