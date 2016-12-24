
/*_______________ Quat to Rotation */
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


/*Quaternion Multiplication */
void QuatMultiply(const float ipVec1, const float ipVec2, float *opVec){
  opVec[0] = ipVec1[0]*ipVec2[0] - ipVec1[1]*ipVec2[1] - ipVec1[2]*ipVec2[2] - ipVec1[3]*ipVec2[3];
 
 opVec[1] = ipVec1[0]*ipVec2[1] + ipVec2[0]*ipVec1[1] + ipVec1[2]*ipVec2[3] - ipVec2[2]*ipVec1[3];

  opVec[2] = ipVec1[0]*ipVec2[2] + ipVec2[0]*ipVec1[2] - ipVec1[1]*ipVec2[3] + ipVec2[1]*ipVec1[3];

  opVec[3] = ipVec1[0]*ipVec2[3] + ipVec2[0]*ipVec1[3] + ipVec1[1]*ipVec2[2] - ipVec2[1]*ipVec1[2];

}

/* Euler Integration Quaternion */
void IntegrateEuler(t
void KFpredict(float *gyroScope){
  float identityMat[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
  
} 


