#pragma once
#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

class Tools {
	private:
	public:
		Tools();
		double random();
		double **Transpose(double** matrix, int row, int col);
		double *z_calulate(double inputs[], double** w, double b[], int inputsNum, int neuronNum);
		double Hadamard(int length, double matrixA[], double matrixB[], double bias);
		double *sigmoid(double z[], int neuronNum);
		double *sigmoid_Derivative(double a[], int neuronNum);

};

#endif

