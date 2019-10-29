const leastCommonMultiple = (a,b) => {
  let x = a;
  let y = b
  while(x !== y) {
     if(x>y){
       x = x - y;
     }
    else {
      y = y - x;
    }
  }
  return (a * b) / x;
}

//examples
// leastCommonMultiple(2,3);
// leastCommonMultiple(192,348);