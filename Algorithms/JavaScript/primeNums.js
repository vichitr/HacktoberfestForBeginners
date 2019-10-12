
function test_prime(n) {

  if (n===1) {

   return;

  }

  console.log(2);

  if(n > 2) {

      for(let x = 3; x <= n; x++) {

        let z = 0;

        for(let y = 2; y < x; y++) {

          if(x % y === 0) {

            z++;

            break;

          }

        }

      if (z === 0) {

      console.log(x);

      }

    }

  }

}

test_prime(100)
