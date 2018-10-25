#include "eHealth.h"

int main (int argc, char *argv[]) {
	int time, i, n;
	
	char* name;
	
	
	name = argv[1];
	time = atoi(argv[2]);
	n = time * 1000; 
	float T[n][2];
	for(i = 1; i <= n; i++){
		T[i][0] = i / 1000.0;
		T[i][1] = eHealth.getECG();
		delay(1);
		//printf("%f, %f\n", T[i][0], T[i][1]);
	}

	int UID, PID;
	UID = 1;
	scanf("%d", &PID);
	
	return 0;
}
