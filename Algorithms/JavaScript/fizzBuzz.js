function fizzbuzz(num) {
    for(let i=1; i<=num; i++) {
        if(i%3 === 0 && i%5 === 0) {
            console.log("FizzBuzz");
        } else if(i%3 === 0) {
            console.log("Fizz");
        } else if(i%5 === 0) {
            console.log("Buzz");
        } else {
            console.log(i);
        }
    }
}

fizzbuzz(20);
fizzbuzz(30);
fizzbuzz(40);
fizzbuzz(50);
