#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int array[n][n];

    for(int i = 0; i<n ; i++) {
        for(int j = 0; j<n ; j++) {
            cin >> array[i][j];
        }
    }

    int temp;
    int innerFlag, flag = 1;

    for(int i = 0; i<n ; i++) {
        for(int j = 0; j<n ; j++) {

            if(array[i][j] != 1) {

                innerFlag = 0;
                //Loop through col
                for(int k = 0; k < n; k++) {

                    if(k == j) {
                        continue;
                    }

                    temp = array[i][j] - array[i][k];

                    //Loop through row
                    for(int l = 0; l < n ; l++) {

                        if(l == i) {
                            continue;
                        }

                        if(temp == array[l][j]) {
                            //cout << array[i][j] << " Sum : " << temp << "+" << array[i][k] << "\n";
                            innerFlag = 1;
                            break;
                        }
                        else {
                            continue;
                        }
                    } 

                    if(innerFlag == 1) {
                        break;
                    } 

                }

                if (innerFlag == 1) {
                    flag &= 1;
                }
                else {
                    flag &= 0;
                }
                
            }
            else {
                flag &= 1;
                continue;
            }
        }
    }

    if(flag == 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}