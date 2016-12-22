/***********************************************************************************************

* 								Drona Aviation

***********************************************************************************************/



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

	matB[0][0] = matA[0][0];

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


/*_______________ Quat to Rotation_______________________________ */
float** Quat2Rot(const float *quat){
	float rotMat[3][3];
	rotMat[0][0] = quat[0]^2 - quat[1]^2 - quat[2]^2 + quat[3]^2 ; 
	rotMat[0][1] = 2*(quat[0]*quat[1] + quat[2]*quat[3]);  
	rotMat[0][2] = 2*(quat[0]*quat[2] - quat[1]*quat[3]);  
 
	rotMat[1][0] = 2*(quat[1]*quat[0] - quat[2]*quat[3]);   
	rotMat[1][1] = -quat[0]^2 + quat[1]^2 - quat[2]^2 + quat[3]^2 ; 
	rotMat[1][2] = 2*(quat[1]*quat[2] + quat[0]*quat[3]);   

	rotMat[2][0] = 2*(quat[2]*quat[0] + quat[1]*quat[3]);   
	rotMat[2][1] = 2*(quat[2]*quat[1] - quat[0]*quat[3]);   
	rotMat[2][2] = -quat[0]^2 - quat[1]^2 + quat[2]^2 + quat[3]^2 ;

  	return rotMat; 

}


/*________________ Rotation to Euler Angles_____________________*/
float* Rot2Euler(const float **rotMat){
	float eulerAngles[3];
	
	float sinth; = -rotMat[2][0];
	if (sinth > 1) {
		sth = 1;
	} 
	else if (sinth < -1) {
		sth = -1;
	}

	float theta = asin(sinth);
	float costh = sqrt(1 - sinth * sinth);

	float phi, psi;

	if (costh < 1.0e-6){
		phi = atan2(rotMat[0][1], rotMat[1][1]);
		psi = 0;
	} 
	else {
		phi = atan2(rotMat[2][1], rotMat[2][2]);
   		psi = atan2(rotMat[1][0], rotMat[0][0]);
	}
	
	eulerAngles[0] = phi; 	// [-pi, pi]
	eulerAngles[1] = theta; // [-pi/2, pi/2]
	eulerAngles[2] = psi; 	// [-pi/2, pi/2]
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

/*Quaternion Multiplication */
void QuatMultiply(const float ipVec1, const float ipVec2, float *opVec){
  opVec[0] = ipVec1[0]*ipVec2[0] - ipVec1[1]*ipVec2[1] - ipVec1[2]*ipVec2[2] - ipVec1[3]*ipVec2[3];
  opVec[1] = ipVec1[0]*ipVec2[1] + ipVec2[0]*ipVec1[1] + ipVec1[2]*ipVec2[3] - ipVec2[2]*ipVec1[3];
  opVec[2] = ipVec1[0]*ipVec2[2] + ipVec2[0]*ipVec1[2] - ipVec1[1]*ipVec2[3] + ipVec2[1]*ipVec1[3];
  opVec[3] = ipVec1[0]*ipVec2[3] + ipVec2[0]*ipVec1[3] + ipVec1[1]*ipVec2[2] - ipVec2[1]*ipVec1[2];
}

/* Euler Integration Quaternion */
void IntegrateEuler(
void KFpredict(float *gyroScope){
  float identityMat[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
  
} 
