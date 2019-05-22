#include <iostream>
#include <string>
#include <stdio.h>
// #include <unistd.h>
#include <math.h>
#include <stdarg.h>
#include <assert.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
// #include "gnuplot.cxx"

using namespace std;



float * GenerateFunction();
float ComputeFunction(int N, float X, float *p);

int main() {
	float compute, X; 
	float *p;
	int N; 
	cout << "Please input the degree of the function you wish to compute (N < 100): "; 
	cin >> N; 
	cout << "\n Please input value of X you wish to compute: ";
	cin >> X; 
	p = GenerateFunction();
	compute = ComputeFunction(N, X, p); 
	cout << "\n \n \n The computed value is then: "; 
	cout << compute; 


	cin.get();
	cin.get();
	return EXIT_SUCCESS;
}

float * GenerateFunction()
{
	static float f[100];
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(-50, 50); // define the range
	float A, B; 
	
	for (int i = 0; i < 100; ++i) {
		A = distr(eng);
		B = (distr(eng)* 1.0) / (100);
		f[i] = A + B;  
		
	}
   return f; 

}

float ComputeFunction(int N, float X, float *p)
{
	int j; 
	float total = p[0], temp;
	cout << "Your generated function is: \n";
	cout << p[0] << " + ";
	for (j = 1; j < N; j++) {
		total = total + p[j]*pow(X, j ); 
		cout << p[j] << "X^" << j << " + "; 
	}
	total = total + p[j] * pow(X, j);
	cout << p[j] << "X^" << j;
	return total; 
}
