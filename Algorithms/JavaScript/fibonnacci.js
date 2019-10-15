function fibonacci (num, cache) {
    cache = cache || {};
   if (cache[num]) return cache[num];
   if (num <= 1) return 1;
   return cache[num] = fibonacci(num - 1, cache) + fibonacci(num - 2, cache); 
}


console.log(fibonacci(6))   // 13
console.log(fibonacci(5))   // 8
console.log(fibonacci(4))   // 5
console.log(fibonacci(3))   // 3
console.log(fibonacci(2))   // 2
console.log(fibonacci(1))   // 1
console.log(fibonacci(0))   // 1

