/*
#ifndef GPS
#define GPS
#define PI 3.141592653589793238
#define earthradius  6371000
#include <Math.h>
#include <String.h>
#include <stdlib.h>
extern char gps_READING[100];

//void setGPSModule(char * gps);
void GPS_READ();
void GPS_output_format() ;
float to_degree(float raw_degree);
float toRad(float angle);
float harversine(float LongAinRad, float LatAinRad, float LongBinRad, float LatBinRad);
float obtainDistance(float LongA, float LatA, float LongB, float LatB);


#endif


*/