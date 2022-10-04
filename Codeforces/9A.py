#include <iostream>
#include <string>

using namespace std;

int main()
{
    int Y, W;
    cin >> Y >> W;

    const string probability[7] = {"", "1/1", "5/6", "2/3", "1/2", "1/3", "1/6"};
    int D = max(Y, W);
    cout << probability[D] << endl;
    return 0;
}
