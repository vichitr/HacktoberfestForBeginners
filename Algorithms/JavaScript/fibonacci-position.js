function fibonacci(position) {
    if(position < 3) return 1;
    else {
        return fibonacci(position - 1) + fibonacci(position - 2);
    }
}

console.log(fibonacci(1)); // 1
console.log(fibonacci(2)); // 1
console.log(fibonacci(3)); // 2
console.log(fibonacci(4)); // 3
console.log(fibonacci(5)); // 5
console.log(fibonacci(6)); // 8
console.log(fibonacci(7)); // 13
