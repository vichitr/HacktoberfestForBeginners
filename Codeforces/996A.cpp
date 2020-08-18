// Codeforces 2020
// Pedro Vinicius Medeiros De Cerqueira 25.04.2020
// Hit the Lottery : Problem 996A


#include <bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  int dollar_bills = 0;
  
  while (n > 0)
  {
    if (n >= 100) {
      dollar_bills += n / 100;
      n = n % 100;
    } else if (n >= 20) {
      dollar_bills += n / 20;
      n = n % 20;
    } else if (n >= 10) {
      dollar_bills += n / 10;
      n = n % 10;
    } else if (n >= 5) {
      dollar_bills += n / 5;
      n = n % 5;
    } else if (n < 5) {
      dollar_bills += n;
      n -= n;
    }
  }
 

  cout << dollar_bills << endl;
}