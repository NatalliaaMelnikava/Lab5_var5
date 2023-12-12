#pragma once
#include <cmath>


double Simpson(double a, double b, double E, double func1(double)) {

	int N = 2;
	double h = (b-a) /N;
	double I1 = func1(a) + func1(b);
	double I2;
	double X_i = a;
	double sum_Nech = 0;
	double sum_Ch = 0;

	do {
		I2 = I1;
		N *= 2;
		h = (b - a) /N;
		X_i = a + h;
		sum_Nech = 0;
		sum_Ch = 0;

		for (int i = 0; i < N; i++) {
			if ((i % 2) == 0) {
				sum_Ch += func1(X_i);
			}
			else {
				sum_Nech += func1(X_i);
			}
			X_i += h;
		}

		I1 = (h / 3) * (func1(a) + 4 * sum_Nech + 2 * sum_Ch + func1(b));
	} while (fabs(I1 - I2) > 15 * E);

	return I1;
}