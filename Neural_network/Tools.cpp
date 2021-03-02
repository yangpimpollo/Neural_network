#include "Tools.h"

    Tools::Tools() {
        srand((unsigned)time(0));
    }

    double Tools::random() {
        return (rand() % 100) / 100.0;
    }

	double **Tools::Transpose(double** matrix, int row, int col){
        double** matrixT = new double*[col];
        for (int i = 0; i < col; i++) {
            matrixT[i] = new double[row];
        }

        for (int j = 0; j < row; j++) {
            for (int i = 0; i < col; i++) {
                matrixT[i][j] = matrix[j][i];
            }
        }
        return matrixT;
	}

    double *Tools::z_calulate(double inputs[], double** w, double b[], int inputsNum, int neuronNum) {
        double *z = new double[neuronNum];

        for (int i = 0; i < neuronNum; i++){
            z[i] = Hadamard(inputsNum, inputs, w[i], b[i]);
        }
        return z;
    }

    double Tools::Hadamard(int length, double matrixA[], double matrixB[], double bias) {
        double singleZ = 0;
        for (int i = 0; i < length; i++) {
            singleZ += matrixA[i] * matrixB[i];
        }
        singleZ += bias;
        return singleZ;
    }

    double *Tools::sigmoid(double z[], int neuronNum) {
        double *sigmoid = new double[neuronNum];
        for (int i = 0; i < neuronNum; i++) {
            sigmoid[i] = 1 / (1 + exp(-z[i]));
        }
        return sigmoid;
    }

    double* Tools::sigmoid_Derivative(double a[], int neuronNum) {
        double *sigmoid_Derivative = new double[neuronNum];
        for (int i = 0; i < neuronNum; i++) {
            sigmoid_Derivative[i] = a[i] * (1 - a[i]);
        }
        return sigmoid_Derivative;
    }