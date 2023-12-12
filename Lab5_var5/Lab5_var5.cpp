#include "main.h"


int main() {

	double pi = acos(-1.0);
	double E1 = 1e-4;
	double E2 = 1e-5;
	double a1 = 0;
	double b1 = 1.234;
	double a2 = 0;
	double b2 = pi/2;
	double c = 0;
	double d = pi/4;

	cout << "Trapezoid's method: " << endl;
	cout << setprecision(8) << Trapezoid(a1, b1, E1,func1) << endl;
	cout << "Simson's method: " << endl;
	cout << setprecision(8) << Simpson(a1, b1, E2,func1) << endl;

	int N, M;
	cout << "enter N and M:" << endl;
	cin >> N;
	cin >> M;

	cout << "Simpson's cubature method: " << endl;
	cout << setprecision(8) << Simpson_Kub(a2, b2, c, d, func2,N,M) << endl;

	return 0;
}