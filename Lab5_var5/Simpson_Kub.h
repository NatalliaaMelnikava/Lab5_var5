#pragma once
#include <iostream>
#include <vector>
using namespace std;

double Simpson_Kub(const double& a, const double& b, const double& c, const double& d, double func2(const double&, const double&), const double& N , const double& M) {

	double h_x = (b - a) / (2 * N);
	double h_y = (d - c) / (2 * M);

	double sum = 0;
	double I = 0;
	double X_i = a;
	double Y_i = c;

	vector<double>X;
	vector<double>Y;

	do {
		X.push_back(X_i);
		X_i += h_x;
	} while (X_i <= b);

	do {
		Y.push_back(Y_i);
		Y_i += h_y;
	} while (Y_i <= d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += func2(X[2 * i], Y[2 * j]) + 4 * func2(X[2 * i + 1], Y[2 * j]) +
				func2(X[2 * i + 2], Y[2 * j]) + 4 * func2(X[2 * i], Y[2 * j + 1]) +
				16 * func2(X[2 * i + 1], Y[2 * j + 1]) + 4 * func2(X[2 * i + 2], Y[2 * j + 1])
				+ func2(X[2 * i], Y[2 * j + 2]) + 4 * func2(X[2 * i + 1], Y[2 * j + 2])
				+ func2(X[2 * i + 2], Y[2 * j + 2]);
		}
	}
	I += sum;
	I *= ((h_x * h_y) / 9);

	return I;
}
