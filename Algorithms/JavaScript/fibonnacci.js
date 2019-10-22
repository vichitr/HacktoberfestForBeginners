// Fibonacci is a series in which number at any given position is sum of two previous numbers: 1,1,2,3,5,8,13,21,34...

function fibonacci (position) {
    if(position < 2) return 1;
    else return fibonacci(position - 1) + fibonacci(position - 2);
}


console.log(fibonacci(6))   // 13
console.log(fibonacci(5))   // 8
console.log(fibonacci(4))   // 5
console.log(fibonacci(3))   // 3
console.log(fibonacci(2))   // 2
console.log(fibonacci(1))   // 1
console.log(fibonacci(0))   // 1

