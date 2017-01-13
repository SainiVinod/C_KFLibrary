#include <stdio.h>
#include <math.h>
#include "matlib.h"
#include "quatlib.h"

void MatLibtest(void){
		printf("Matrix Library Test \n");
    float arr1[3][3]  = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    float arr2[3][3]  = {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    float multiCheck[3][3]   = {{0}};
    float additionCheck[3][3];
    float transposeCheck[3][3];
    float normCheck[3][3];
    float matInverse[3][3];
    unsigned int sizearr1[2] = {3,3};
    unsigned int sizearr2[2] = {3,3};
    printf("Matrix A \n");
    print((float *)arr1, 3, 3);
    printf("Matrix B \n");
    print((float *)arr2, 3, 3);
    MatMultiplication( (float *)arr1, sizearr1, (float *)arr2, sizearr2, (float *)multiCheck);
    printf("Matrix A*B \n");
    print((float *)multiCheck, 3, 3);
    
    float det = MatDet3by3((float *)multiCheck);
    printf("Determinant of Matrix A*B %f \n", det);
    
    MatAddition( (float *)arr1, sizearr1, (float *)arr2, (float *)additionCheck);
    printf("Addition of Matrix A and B \n");
    print((float *)additionCheck, 3, 3);
    
    MatTranspose((float *)arr1, sizearr1, (float *)transposeCheck); 
    printf("Transpose of Matrix A \n");
    print((float *)transposeCheck, 3, 3);  
    
    MatInv3by3((float *)arr2, (float *)matInverse);
    printf("Inverse of Matrix B \n");
    print((float *)matInverse, 3, 3);  
    
    
    float arr3[2][2] 	=	{{2,3},{4,2}};
    float invMat2by2[2][2];
    printf("Matrix C is \n");
    print((float *)arr3, 2, 2);
    printf("Determinant of Matrix C is %f \n", MatDet2by2((float *) arr3));
    MatInv2by2((float *) arr3, (float *) invMat2by2);
    printf("Inverse of Matrix C \n");
    print((float *)invMat2by2, 2, 2);
    
    float scalarMulti[3][3];
    float scalar = 2.0;
    MatScalarMult((float *)arr1, sizearr1, scalar, (float *)scalarMulti);
    printf("Scalar Multiplication of %f and Matrix A is \n" , scalar);
    print((float *)scalarMulti, 3, 3);
    
    
    printf("Normalized Matrix B is \n");
    NormalizeMatrix((float *)arr2, sizearr2, (float *) normCheck);
    print((float *)normCheck, 3, 3);
    
    float omegaVec[3][1] = {{1},{2},{3}};
    float omegaVecT[1][3] = {{1 , 2, 3}};
    
    float omegaSkew[3][3];
    
    printf("Vector \n");
    print((float *)omegaVec, 3, 1);
    printf("Vector \n");
    print((float *)omegaVecT, 1, 3);
    crossSkew((float *) omegaVec, (float *) omegaSkew);
    printf("SkewMatrix \n");
    print((float *)omegaSkew, 3, 3);
    crossSkew((float *) omegaVecT, (float *) omegaSkew);
    printf("SkewMatrix \n");
    print((float *)omegaSkew, 3, 3);
    
    float rotMat[3][3]  = {{1,0,0},{0,1,0},{0,0,1}};
    float accVec[3]     = {1,2,3};   
    unsigned int sizerotMat[2] = {3,3};
    unsigned int sizeaccVec[2] = {3,1};
    float op[3][1];
    MatMultiplication( (float *)rotMat, sizerotMat, (float *)accVec, sizeaccVec, (float *)op);
    printf("Rotation Matrix \n");
    print((float *) rotMat, 3, 3);
    printf("Vector \n");
    print((float *) accVec, 1, 3); 
    printf("Matrix Array Multiplcation \n");
    print((float *)op, 3,1);    
    
    float xVec[1][2] = {{1,1}};
    float xVecnorm[1][2];
    float yVec[2][1] = {{1},{1}};
    float xyelem[1][1];
    unsigned int xSize[2] = {1,2};
    unsigned int ySize[2] = {2,1};
    MatMultiplication( (float *)xVec, xSize, (float *)yVec, ySize, (float *)xyelem);
		print((float *)xVec, 1, 2);
		print((float *)yVec, 2, 1);
		printf("%f \n",(xyelem[0][0]+2.0));
		
		NormalizeMatrix((float *)xVec, xSize, (float *)xVecnorm);
		printf("Normalized Vector");
		print((float *)xVecnorm, 2, 1);
}

void QuatLibtest(void){
	 	printf("Quat Library Test \n");
	 	
	 	printf("Quat2Rot Test:\n");
		//to do: write test functions

		printf("Rot2Euler Test:\n");
		//to do: write test functions
		float rotMat[3][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
		float eulerAngles[3];
		Rot2Euler((float*) rotMat, (float*) eulerAngles);
		printf("Rotation Matrix is \n");
		print((float *)rotMat, 3, 3);
		printf("Euler Angles are: \n");
		print((float *)eulerAngles, 3, 1);
				
		printf("QuatMultiply Test:\n");
		//to do: write test functions	 	
		
		printf("Euler2Quat Test:\n");
		//to do: write test functions
		
	 	printf("Rodrigues Test:\n");
		//to do: write test functions

	 	printf("IntegrateEuler Test:\n");
		//to do: write test functions

}

void Array2DTest(float *arr){
	float x = *arr+ *(arr+1) + *(arr+2) + *(arr+3);
	printf("X is = %f ", x);
}
 
int main()
{
 		MatLibtest();
 		QuatLibtest();
 		//float x[2][2] = {{1,1},{1,1}};   
 		//Array2DTest( (float *) x);
    getchar();
    return 0;
}
