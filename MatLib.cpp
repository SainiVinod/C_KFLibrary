/****************************************************************************
* 								Drona Aviation

*****************************************************************************/


#include <stdint.h>

#include <math.h>



#include "matrix.h"



/* 3 X 3 matrix mutiplication, mat A and B as inputs and C = A X B */

void MatMul3by3(const float **matA, const float **matB, float **matC){

	matC[0][0] = matA[0][0]*matB[0][0] + matA[0][1]*matB[1][0] + matA[0][2]*matB[2][0];

	matC[0][1] = matA[0][0]*matB[0][1] + matA[0][1]*matB[1][1] + matA[0][2]*matB[2][1];

	matC[0][2] = matA[0][0]*matB[0][2] + matA[0][1]*matB[1][2] + matA[0][2]*matB[2][2];

	matC[1][0] = matA[1][0]*matB[0][0] + matA[1][1]*matB[1][0] + matA[1][2]*matB[2][0];

	matC[1][1] = matA[1][0]*matB[0][1] + matA[1][1]*matB[1][1] + matA[1][2]*matB[2][1];

	matC[1][2] = matA[1][0]*matB[0][2] + matA[1][1]*matB[1][2] + matA[1][2]*matB[2][2];

	matC[2][0] = matA[2][0]*matB[0][0] + matA[2][1]*matB[1][0] + matA[2][2]*matB[2][0];

	matC[2][1] = matA[2][0]*matB[0][1] + matA[2][1]*matB[1][1] + matA[2][2]*matB[2][1];

	matC[2][2] = matA[2][0]*matB[0][2] + matA[2][1]*matB[1][2] + matA[2][2]*matB[2][2];

}

/* Matrix Multiplication */
MatMultiplication(const float *matA, const unsigned int *sizeA, const float *matB, const unsigned int *sizeB, float *matC){
	for (unsigned int i1 = 0 ; i1< sizeA[0]; i1++){
		for (unsigned int j2 = 0; j2 < sizeB[1]; j2++){
			for (unsigned int j1 = 0; j1 < sizeA[1] ; j1++){
				for (unsigned int i2 = 0 ; i2 < sizeB[0] ; i2++){
					matC[i1][j2] += matA[i1][j1]*matB[i2][j2];
				}
			}			
		}
	}
}

/* Determinant of mat A */

float MatDet3by3(const float **matA) {

	

  return matA[0][0] * (matA[1][1] * matA[2][2] - matA[1][2] * matA[2][1]) -

         matA[0][1] * (matA[1][0] * matA[2][2] - matA[1][2] * matA[2][0]) +

         matA[0][2] * (matA[1][0] * matA[2][1] - matA[1][1] * matA[2][0]);

}



/* 3 X 3 matrix addition, mat A and B as inputs and C = A + B */

void MatAdd3by3(const float **matA, const float **matB, float **matC){

	matC[0][0] = matA[0][0] + matB[0][0];

	matC[0][1] = matA[0][1] + matB[0][1];

	matC[0][2] = matA[0][2] + matB[0][2];

	matC[1][0] = matA[1][0] + matB[1][0];

	matC[1][1] = matA[1][1] + matB[1][1];

	matC[1][2] = matA[1][2] + matB[1][2];

	matC[2][0] = matA[2][0] + matB[2][0];

	matC[2][1] = matA[2][1] + matB[2][1];

	matC[2][2] = matA[2][2] + matB[2][2];

}



/* Transpose of 3X3 mat A */

void MatTrans3by3(const float **matA, float **matB){

	matB[0][0] = matA[0][0];

	matB[0][1] = matA[1][0];

	matB[0][2] = matA[2][0];

	matB[1][0] = matA[0][1];

	matB[1][1] = matA[1][1];

	matB[1][2] = matA[2][1];

	matB[2][0] = matA[0][2];

	matB[2][1] = matA[1][2];

	matB[2][2] = matA[2][2];

}



/* 3 X 3 matrix inverse */

void MatInv3by3(const float **matA, float **matB){

	float det = MatDet3by3(matA);

	

	matB[0][0] = (-matA[2][1] * matA[1][2] + matA[1][1] * matA[2][2]) / det;

	matB[0][1] = (-matA[0][1] * matA[2][2] + matA[0][2] * matA[2][1]) / det;

	matB[0][2] = (matA[0][1] * matA[1][2] - matA[0][2] * matA[1][1]) / det;



	matB[1][0] = (matA[2][0] * matA[1][2] - matA[1][0] * matA[2][2]) / det;

	matB[1][1] = (-matA[2][0] * matA[0][2] + matA[0][0] * matA[2][2])/ det;

	matB[1][2] = (matA[1][0] * matA[0][2] - matA[0][0] * matA[1][2]) / det;



	matB[2][0] = (-matA[2][0] * matA[1][1] + matA[1][0] * matA[2][1]) / det;

	matB[2][1] = (matA[2][0] * matA[0][1] - matA[0][0] * matA[2][1]) / det;

	matB[2][2] = (-matA[1][0] * matA[0][1] + matA[0][0] * matA[1][1]) / det;

	

}



/* 2 X 2 matrix multiplication */

void MatMul2by2(const float **matA, const float **matB, float **matC){

	matC[0][0] = matA[0][0]*matB[0][0] + matA[0][1]*matB[1][0] ;

	matC[0][1] = matA[0][0]*matB[0][1] + matA[0][1]*matB[1][1] ;

	matC[1][0] = matA[1][0]*matB[0][0] + matA[1][1]*matB[1][0] ;

	matC[1][1] = matA[1][0]*matB[0][1] + matA[1][1]*matB[1][1] ;

	matC[2][0] = matA[2][0]*matB[0][0] + matA[2][1]*matB[1][0] ;

	matC[2][1] = matA[2][0]*matB[0][1] + matA[2][1]*matB[1][1] ;

}





/* 2 X 2 matrix determinant */

float MatDet2by2(const float **matA) {

	

  return (matA[0][0] * matA[1][1] - matA[0][1] * matA[1][0]);

}



/* 2 X 2 matrix addition, mat A and B as inputs and C = A + B */

void MatAdd2by2(const float **matA, const float **matB, float **matC){

	matC[0][0] = matA[0][0] + matB[0][0];

	matC[0][1] = matA[0][1] + matB[0][1];

	matC[1][0] = matA[1][0] + matB[1][0];

	matC[1][1] = matA[1][1] + matB[1][1];

}



/* Transpose of 2 X 2 mat A */

void MatTrans2by2(const float **matA, float **matB){


	matB[0][1] = matA[1][0];

	matB[1][0] = matA[0][1];

	matB[1][1] = matA[1][1];

}



/* 2X2 matrix inverse */

void MatInv2by2(const float **matA, float **matB){

	float det_inv = 1.0/ MatDet2by2(matA);

	MatScalarMult(matA, 2, 2, det_inv, matB);

	matB[0][1] = -matB[0][1];

	matB[1][0] = -matB[1][0]; 

}



/* Matrix multiplied by scalar */

void MatScalarMult(const float **matA, const unsigned int row, const unsigned int col,const float scalar, float **matB){

	for(unsigned int itr_row = 0; itr_row < row; itr_row++){

		for(unsigned int itr_col = 0; itr_col < col; itr_col++) {

			matB[itr_row][itr_col] = matA[itr_row][itr_col]*scalar; 

		}

	}

}



/*Sum of two Matrices*/
void MatrixSum(const float **ipMat1, const float **ipMat2, const int8_t row, const int8_t col, float **opMat){
  for (int8_t i = 0; i < row; i++{
    for (int8_t j = 0; j < col; j++{
      opMat[i][j] = ipMat1[i][j] + ipMat2[i][j];
    }
  }
}



/*Normalize Vector */
void NormArray(float *vec, const int8_t size){
  float sum = 0.0;
  for (uint8_t i = 0; i < size, i++){
    sum += pow(vec[i],2);
  }   
  sum = pow(sum,0.5);

  for (uint8_t i = 0; i < size; i++){
    vec[i] /= sum;
  }
}


/*Calculate Cross Skew Matrix */
float** crossSkew(const float *vec){
  float skewMat[3][3];
  skewMat[0][0] = 0;
  skewMat[0][1] = -vec[2];
  skewMat[0][2] = vec[1];

  skewMat[1][0] = vec[2];
  skewMat[1][1] = 0;
  skewMat[1][2] = -vec[0];

  skewMat[2][0] = -vec[1];
  skewMat[2][1] = vec[0];
  skewMat[2][2] = 0;

  return skewMat;
}

