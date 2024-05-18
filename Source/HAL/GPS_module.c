/*

#include "../../Headers/HAL/GPS_module.h"
#include "../../Headers/MCAL/UART.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>






char gps_READING[100] = {0};
int len =9;
int Read_Done=0;
float previous_latit= 0.524744689;
float	previous_longit=0.545923114;
float currLatit ,directed_currLatit,currLatitdegree,currLatitradian;
float currLong,directed_currLong,currLongdgree,currLongradian,total_distance;
float angle ;	

//float coordinates[2][20]; 	
char* pointer;
int flag;
int valid;
int N;
int K;
int counter;


  void GPS_output_format() {
	  flag=0;
	  valid=0;
	   N=0;
	   K=0;
   counter=0;

    pointer = strtok(gps_READING, ",");
    while (pointer != NULL){
 
      if(counter==2&&strcmp(pointer,"A")==0){ 
			       flag=1;
			      valid =1;
   		 }
			if(valid==1){
			if (counter==3){
       currLatit=stringToFloat(pointer);	     // similar to atof
			}
			
			  if (counter==4&&strcmp(pointer, "N") == 0) {
				     directed_currLatit=+currLatit;		
					   
              //coordinates[0][N] = directed_currLatit ;    
              //  N++;					
          }
				else if (counter==4&&strcmp(pointer, "S") == 0) {
					directed_currLatit=-currLatit;
					
					//coordinates[0][N] = directed_currLatit ;    
             //   N++;
				}
				
			 if(counter==5){
			 currLong = stringToFloat(pointer);         //similar to atof
			 }
			 
				  if (counter==6&&strcmp(pointer, "E") == 0) {
            directed_currLong=currLong;	
						// coordinates[1][K] = directed_currLong;
               //K++;
						
		      } else  if (counter==6&&strcmp(pointer, "W") == 0) {
            directed_currLong=-directed_currLong;
					//	coordinates[1][K] = directed_currLong;
              // K++;					
					}	
			}
			counter++;
		    pointer = strtok(NULL, ",");  //next token
			}
		
			
		 sendCoordinatesUART0( directed_currLatit,  directed_currLong);

//         for (int i = 0; i < N; i++) {
//            sendCoordinatesUART0(coordinates[0][i], coordinates[1][i]);
//          }		
	}
	
	


void GPS_READ(){
	int flag=0;
	int i;
	 //char *pointer;
	char c0,c1,c2,c3,c4,c5;
	
	int numOfGPSElements = 0;
	char character;
	c0 = charIn2();  //$
	c1 = charIn2();  //G 
	c2 = charIn2();  //P
	c3 = charIn2();  //R
	c4 = charIn2();  //M
	c5 = charIn2();  //C
	i = 6;

	if (c0 == '$'&&c1 == 'G'&&c2 =='P'&&c3 =='R'&&c4 =='M'&&c5=='C') {
		gps_READING[0] = c0;
		gps_READING[1] = c1;
		gps_READING[2] = c2;
		gps_READING[3] = c3;
		gps_READING[4] = c4;
		gps_READING[5] = c5;

	
	  do{ 	character = charIn2();
		    	gps_READING[i] = character;
		      i++;
		    } while (character != '*');
	     
				flag=1;
		   gps_READING[i] = '\0'; 
			//	UART0_outString(gps_READING);
    Read_Done=1;  
	}
	
}


///-----------------------------calculating distance---------------------------------//

	  float to_degree(float raw_degree) {  // gps output to degrees
    int dd = (int)(raw_degree / 100);
    float mm = raw_degree - (dd * 100);
    float degree = dd + (mm / 60);
    return  degree;}
		 
		
			float toRad(float angle)
			{
				return ((angle * PI) / 180);
			}

			float harversine(float LongAinRad, float LatAinRad, float LongBinRad, float LatBinRad)
			{

					float x=pow(sin((LatBinRad-LatAinRad)/2),2);
					float y=pow(sin((LongBinRad-LongAinRad)/2),2);
					float a=x+y*cos(LatAinRad)*cos(LatBinRad);
					float c = 2*atan2(sqrt(a),sqrt(1-a));
					return earthradius*c;
			}
			
			float obtainDistance(float LongA, float LatA, float LongB, float LatB)
				{

					float LatAinRad=toRad(to_degree(LatA));
					float LatBinRad=toRad(to_degree(LatB));
					float LongAinRad=toRad(to_degree(LongA));
					float LongBinRad=toRad(to_degree(LongB));
					
					
					return harversine(LongAinRad,LatAinRad,LongBinRad,LatBinRad);
			}



*/