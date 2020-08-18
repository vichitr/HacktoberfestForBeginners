#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		std::cout << std::hex << std::left << std::showbase << std::nouppercase << (long long)A << std::endl;

		std::cout << std::right << setw(15) << setfill('_') << std::showpos << std::fixed << std::setprecision(2);
		std::cout << B << std::endl;

		std::cout << std::scientific << std::uppercase << std::noshowpos << std::setprecision(9) << C << std::endl;
		/* Enter your code here */

	}
	return 0;

}