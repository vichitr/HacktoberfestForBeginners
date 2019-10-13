#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double A, B, C, d1, delta, R1, R2;
    cout << "Enter A, B and C: ";
    cin >> A >> B >> C;

    d1 = pow(B, 2) - (4 * A * C);
    delta = sqrt(d1);
    R1 = (-B + delta) / (2 * A);
    R2 = (-B - delta) / (2 * A);

    if (A == 0 || d1 < 0) {
        cout << "Impossivel calcular" << endl;
    } else {
        cout << fixed << setprecision(5);
        cout << "R1 = " << R1 << endl;
        cout << fixed << setprecision(5);
        cout << "R2 = " << R2 << endl;
    }

    return 0;
}
