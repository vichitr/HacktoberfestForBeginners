/*Decrypting caesar cipher with frecuency analysis the principle of the fecuency analysis is knowing which is the most used letter on a a text given
after 'e' er the most common letter on the english language*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  char sentence[30];
  int count = 1;

  cout << "Write a message: ";
  cin.getline(sentence, 30);

  for(int i = 1; i < sentence[i]; i++)
  {
    for(int j = i + 1; j < sentence[i]; j++)
    {
      if(sentence[i] == sentence[j]){
          count++;
          sentence[j] = 0;
      }
    }
    cout << sentence[i] << " appeared: " << count << " Times" << endl;
    count = 1;
  }
}

/*Knowing the most common letter on our message we can now count many spaces there are
between e and the most common letter, this number is possibly the key.*/