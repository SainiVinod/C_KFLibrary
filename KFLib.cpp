void MatrixSum(const float **ipMat1, const float **ipMat2, const int8_t row, const int8_t col, float **opMat){
  for (int8_t i = 0; i < row; i++{
    for (int8_t j = 0; j < col; j++{
      opMat[i][j] = ipMat1[i][j] + ipMat2[i][j];
    }
  }
}


void NormArray(const float *vec, const int8_t size){
  float sum = 0.0;
  for (uint8_t i = 0; i < size, i++){
    sum += pow(vec[i],2);
  }   
  sum = pow(sum,0.5);

  for (uint8_t i = 0; i < size; i++){
    vec[i] /= sum;
  }
}

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

void IntegrateEuler(
void KFpredict(float *gyroScope){
  float identityMat[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
  
} 
