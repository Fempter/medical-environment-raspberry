#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

#include "eHealth.h"

#include "instrumentarium_projekt/json.cpp"

using namespace std;

int cont = 0;
void rp(){
	cont ++;
	if (cont == 50){
		eHealth.readPulsioximeter();
		cont = 0;
}
}

void setup() {
	eHealth.initPulsioximeter();
	attachInterrupt(6, rp, RISING);
}
int main (int argc, char *argv[]) {

	int n, i, time;
	char* name;
	
    name = argv[1];
    time = atoi(argv[2]);
  	 
	n = time * 1000;
	
	float ECG[n][2];
	float GSR[n/1000][4];
	float PULSOXIMETER[n/500][3];
	float AIRFLOW[n/50][2];
	float TEMPERATURE[n/2000][2];

	for(i = 1 ; i <= n ; i++) {

		ECG[i][0] = i / 1000.0;
		ECG[i][1] = eHealth.getECG();
		//printf("%f, %f\n", ECG[i][0], ECG[i][1]);

		if (i % 1000 == 0) {
			GSR[i/1000][0] = i / 1000.0;
			GSR[i/1000][1] = eHealth.getSkinConductance();
			GSR[i/1000][2] = eHealth.getSkinResistance();
			GSR[i/1000][3] = eHealth.getSkinConductanceVoltage();
			//printf("%f, %f, %f, %f\n", GSR[i/1000][0], GSR[i/1000][1], GSR[i/1000][2], GSR[i/1000][3]);
		}

		if (i % 500 == 0) {
			//eHealth.initPulsioximeter();
			//attachInterrupt(6, readPulsioximeter, RISING);
			setup();
			PULSOXIMETER[i/500][0] = i / 1000.0;
			PULSOXIMETER[i/500][1] = eHealth.getBPM();
			PULSOXIMETER[i/500][2] = eHealth.getOxygenSaturation();
			printf("%f, %f, %f\n", PULSOXIMETER[i/500][0], PULSOXIMETER[i/500][1], PULSOXIMETER[i/500][2]);
		}

		if (i % 50 == 0) {
			int air = eHealth.getAirFlow();
			AIRFLOW[i/50][0] = i / 1000.0;
			AIRFLOW[i/50][1] = air; //eHealth.airFlowWave(air);
			//printf("%f, %f\n", AIRFLOW[i/50][0], AIRFLOW[i/50][1]);
		}

		if (i % 2000 == 0) {
			TEMPERATURE[i/2000][0] = i / 1000.0;
			TEMPERATURE[i/2000][1] = eHealth.getTemperature();
			//printf("%f, %f\n", TEMPERATURE[i/2000][0], TEMPERATURE[i/2000][1]);
		}

		delay(1);

	}

	cout<<"OK 1"<<endl;
 	//printStaticArray("ECG", ECG, n, 2);
	printStaticArray("PULSOXIMETER", PULSOXIMETER, n/500, 3);
	//printStaticArray("TEMP", TEMPERATURE, n/2000, 2);
	cout<<"OK 2"<<endl;
	return 0;
}
