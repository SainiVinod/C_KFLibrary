#include <stdio.h>
void print(float *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++){
      for (j = 0; j < n; j++)
        printf("%f ", *((arr+i*n) + j));
      printf("\n");
    }	

}

/* Matrix Multiplication */
void MatMultiplication(const float *matA, const unsigned int sizeA[], const float *matB, const unsigned int sizeB[], float *matC){
	unsigned int i1, j1, j2;
	for (i1 = 0 ; i1< sizeA[0]; i1++){
		for (j2 = 0; j2 < sizeB[1]; j2++){
			for (j1 = 0; j1 < sizeA[1] ; j1++){
					//printf("%d %d %d %d = %d %d \n", i1, j1, j1, j2, i1, j2);
					*((matC+i1*sizeB[1]) + j2) += (*((matA+i1*sizeA[1]) + j1)) * (*((matB+j1*sizeB[1]) + j2));
					//matC[i1][j2] += matA[i1][j1]*matB[i2][j2];
			}			
		}
	}
}
 
int main()
{
    float arr1[4][3]  = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    float arr2[3][4]  = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    float arr3[4][4]   = {{0}};
    unsigned int sizearr1[2] = {4,3};
    unsigned int sizearr2[2] = {3,4};
    print((float *)arr1, 4, 3);
    MatMultiplication( (float *)arr1, sizearr1, (float *)arr2, sizearr2, (float *)arr3);
    print((float *)arr3, 4, 4);
    return 0;
}
