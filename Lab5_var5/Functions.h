#pragma once
#include <iostream>
#include <cmath>
using namespace std;

double func1(double x) {
	return ((sin(x) * sin(x)) / pow((1 + x * x * x), (1 / 2)));
}

double func2(const double& x, const double& y) {
	return sin(x + y);
}

