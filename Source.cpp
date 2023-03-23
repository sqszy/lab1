#include <iostream>
#include <cmath>
# include <iomanip>
using namespace std;

//Функция первой кривой y = 3x - x^2
double krivaya1(double x) {
	return 3 * x - pow(x, 2);
}

//Функция второй кривой y = -x
double krivaya2(double x) { 
	return -x;
}

//Функция нахождения точки пересечения двух линий между собой
double peresechenie(double (line)(double), double (line2)(double), double& point1) {
	int count = 0;
	double point, inaccuracy = 0.0001;
	for (int i = -10; count < 2; ++i) {
		double j = -10.0 + 0.0001 * i;
		if (abs(line(j) - line2(j)) < inaccuracy) {
				if (count == 0) {
					point1 = j;
				}
				++count;
				point = j;
			}
		}
	return point;
}

//Перегруженная функция нахождения точки пересечения уравнения линии с осью абсцисс
void peresechenie(double (*line)(double)) {
	int count = 0;
	for (double i = -10.0; i < 10.0; ++i) {
		if (line(i) == 0) {
			++count;
			cout << "Point: " << count << " = " << i << "\n";
		}
	}
	if (count == 0){
		cout << "No points" << endl;
	}
}


//Функция численного интегрирования
double numericalint(double point1, double point2, double (*line)(double), double (*line2)(double)) {
	double result1 = 0.0;
	double result2 = 0.0;
	double step = 0.0001;
	for (double i = point1; i < point2; i += step) {
		result1 = result1 + (*line)(i) * step;
	}
	for (double j = point1; j < point2; j += step) {
		result2 = result2 + (*line2)(j) * step;
	}
	return abs(result1 - result2);
}


int main(){
	double point1, point2;
	point2 = peresechenie(krivaya1, krivaya2, point1);
	cout << "Points of intersection of two lines between each other: " << point1 << " " << point2 << endl;
	cout << "The points of intersection with the abscissa axis (1st equation): " << endl;
	peresechenie(krivaya1);
	cout << "The points of intersection with the abscissa axis (2nd equation): " << endl;
	peresechenie(krivaya2);
	cout << "The area between the two lines of the equation = " << numericalint(point1, point2, krivaya1, krivaya2) << endl;
}