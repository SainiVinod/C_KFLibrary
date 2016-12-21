void MatrixSum(const float **ipMat1, const float **ipMat2, const int8_t row, const int8_t col, float **opMat){
  for (int8_t i = 0; i < row; i++{
    for (int8_t j = 0; j < col; j++{
      opMat[i][j] = ipMat1[i][j] + ipMat2[i][j];
    }
  }
} 
