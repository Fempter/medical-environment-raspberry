#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

#include "jsoncpp/dist/jsoncpp.cpp"
#include "jsoncpp/dist/json/json.h"
#include "jsoncpp/dist/json/json-forwards.h"

using namespace std;

typedef float real;
#define MY_FLOAT_PRECISION 6
#define MY_DOUBLE_PRECISION 16
#define MY_PRECISION MY_FLOAT_PRECISION

#define DYNAMIC(b, a, r, c) real ** b = new real *[r];for(int i=0;i<r;i++){b[i]=new real[c];for(int j=0;j<c;j++)b[i][j]=a[i][j];};
#define FREE(b, r) for(int i=0;i<r;i++) free(b[i]); free(b);

#define PRINT_FUNC(a) cout<<a<<endl;
#define printFunc(a) cout<<a<<endl;
#define testFunction(a) \
PRINT_FUNC(a);\
printFunc(a);\
PRINT_FUNC(a);


#define printStaticArray(name, array, rows, cols) \
DYNAMIC(d##array, array, rows, cols);\
printArray(name, d##array, rows, cols);\
FREE(d##array, rows);

void printArray(const char *measure, real **arr, int rows, int cols)
{
    cout << "Hello";
    int i,j;
    
    cout << endl;
    
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
    
    if (measure == "ECG")
    {
        int i,j;
        
        Json::Value ECG;
        Json::Value time(Json::arrayValue);
        Json::Value values(Json::arrayValue);
        
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < 1; j++)
            {
                time.append(Json::Value(arr[i][j]));
            }
        }
        
        for (i = 0; i < rows; i++)
        {
            for (j = 1; j < 2; j++)
            {
                values.append(Json::Value(arr[i][j]));
            }
        }
        
        ECG["time"] = time;
        ECG["values"] = values;
        cout << ECG << endl;
        
    }
    
    if (measure == "GSR")
    {
        int i,j;
        
        Json::Value GSR;
        Json::Value time(Json::arrayValue);
        Json::Value skin_conductance(Json::arrayValue);
        Json::Value skin_resistance(Json::arrayValue);
        Json::Value skin_conductance_voltage(Json::arrayValue);
        
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < 1; j++)
            {
                time.append(Json::Value(arr[i][j]));
            }
        }
        
        for (i = 0; i < rows; i++)
        {
            for (j = 1; j < 2; j++)
            {
                skin_conductance.append(Json::Value(arr[i][j]));
            }
        }
        
        for (i = 0; i < rows; i++)
        {
            for (j = 2; j < 3; j++)
            {
                skin_resistance.append(Json::Value(arr[i][j]));
            }
        }
        
        for (i = 0; i < rows; i++)
        {
            for (j = 3; j < 4; j++)
            {
                skin_conductance_voltage.append(Json::Value(arr[i][j]));
            }
        }
        
        GSR["time"] = time;
        GSR["skin_conductance"] = skin_conductance;
        GSR["skin_resistance"] = skin_resistance;
        GSR["skin_conductance_voltage"] = skin_conductance_voltage;
        cout << GSR << endl;
    }
    
    if (measure == "PULSOXIMETER")
    {
        int i,j;
        
        Json::Value PULSOXIMETER;
        Json::Value time(Json::arrayValue);
        Json::Value bpm(Json::arrayValue);
        Json::Value oxygen_saturation(Json::arrayValue);
        
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < 1; j++)
            {
                time.append(Json::Value(arr[i][j]));
            }
        }
        
        for (i = 0; i < rows; i++)
        {
            for (j = 1; j < 2; j++)
            {
                bpm.append(Json::Value(arr[i][j]));
            }
        }
        
        for (i = 0; i < rows; i++)
        {
            for (j = 2; j < 3; j++)
            {
                oxygen_saturation.append(Json::Value(arr[i][j]));
            }
        }
        
        PULSOXIMETER["bpm"] = bpm;
        PULSOXIMETER["oxygen_saturation"] = oxygen_saturation;
        cout << PULSOXIMETER << endl;
    }
    
    if (measure == "AIRFLOW")
    {
        int i,j;
        
        Json::Value AIRFLOW;
        Json::Value time(Json::arrayValue);
        Json::Value air_flow_wave(Json::arrayValue);
        
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < 1; j++)
            {
                time.append(Json::Value(arr[i][j]));
            }
        }
        
        for (i = 0; i < rows; i++)
        {
            for (j = 1; j < 2; j++)
            {
                air_flow_wave.append(Json::Value(arr[i][j]));
            }
        }
    
        AIRFLOW["time"] = time;
        AIRFLOW["air_flow_wave"] = air_flow_wave;
        cout << AIRFLOW << endl;
    }
    
    if (measure == "TEMPERATURE")
    {
        int i,j;
        
        Json::Value TEMPERATURE;
        Json::Value time(Json::arrayValue);
        Json::Value temperature(Json::arrayValue);
        
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < 1; j++)
            {
                time.append(Json::Value(arr[i][j]));
            }
        }
        
        for (i = 0; i < rows; i++)
        {
            for (j = 1; j < 2; j++)
            {
                temperature.append(Json::Value(arr[i][j]));
            }
        }
        
        TEMPERATURE["time"] = time;
        TEMPERATURE["temperature"] = temperature;
        cout << TEMPERATURE << endl;
    }

}
