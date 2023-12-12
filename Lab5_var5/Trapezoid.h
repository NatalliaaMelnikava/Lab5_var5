#pragma once
#include <iostream>

double Trapezoid(double a, double b, const double E, double func1(double)) {

	int N = 2;
	double h = (b - a) / N;
	double sum = 0;
	double I1 = func1(a) + func1(b);
	double I2, X_n;

	do {
		I2 = I1;
		N *= 2;
		h = (b - a) / N;
		X_n = a;
		sum = 0;
		for (int i = 0; i < N - 1; i++) {
			X_n += h;
			sum += func1(X_n);
		}
		I1 = (h / 2) * (func1(a) + 2 * sum + func1(b));
	} while (fabs(I1 - I2) >= 3 * E);

	return I1;
}
