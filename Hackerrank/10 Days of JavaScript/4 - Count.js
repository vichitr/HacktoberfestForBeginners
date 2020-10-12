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
 * Returns a count of the total number of objects 'o' satisfying o.x == o.y.
 */
function getCount(objects) {
    let count = 0;
    for (let o of objects) {
        if (o.x == o.y) {
            count++;
        }
    }
    return count;
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
function main() {
    const n = +(readLine());
    let objects = [];
    
    for (let i = 0; i < n; i++) {
        const [a, b] = readLine().split(' ');
        
        objects.push({x: +(a), y: +(b)});
    }
    
    console.log(getCount(objects));
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */