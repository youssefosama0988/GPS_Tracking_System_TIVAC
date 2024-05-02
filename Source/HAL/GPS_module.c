#include "../../Headers/HAL/GPS_module.h"
#include "../../Headers/MCAL/UART.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


char logElements[12][20];
char * pointer; 
//char message[]="$GPRMC, 203522.00, A, 5109.0262308, S, 11401.8407342, E, 0.004, 133. 4, 130522, 0.0, E, D*2B";
char log_name[]="$GPRMC, ";
char recievedChar[100];  
int correct =0;
char c0,c1,c2,c3,c4,c5,c6;

static int x=0;


int GPS_read(char *GPS_module)
{ 
    int flag = 1;
    c0 = charIn2(); //$
    if (c0 == log_name[0]) 
    {   
        c1 = charIn2();  //G
        if (c1 == log_name[1])
        {
            c2 = charIn2();  //p
            if (c2 == log_name[2])
            {
                c3 = charIn2();   //R
                if (c3 == log_name[3])
                {
                    c4 = charIn2();    //M
                    if (c4 == log_name[4])
                    {
                        c5 = charIn2();     //C
                        if (c5 == log_name[5])
                        {
                            c6 = charIn2();
                            if (c6 == log_name[6]) //,
                            {
                                int i = 0;
                                do
                                { 
                                    GPS_module[i] = charIn2(); 
                                    i++;
                                } while (charIn2()!= '*');
                                flag=1;
                              
                            }
                            else
                            {
                                flag = 0;
                            }
                        }
                        else
                        {
                            flag = 0;
                        }
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                else
                {
                    flag = 0;
                }
            }
            else
            {
                flag = 0;
            }
        }
        else
        {
            flag = 0;
        }
    }
    else
    {
        flag = 0;
    }

    return flag;
}


void GPS_output_format(){
	char numOfGPSElements=0;
do{
pointer=strtok(GPS_module,",");

strcpy(logElements[numOfGPSElements],GPS_module);
	pointer=strtok(NULL,",");
	numOfGPSElements++;
}while(pointer!=NULL);

//then we will get the current long and lat :)

// here we check the validity of the string formated gps_module
if(strcmp(logElements[0],"A")==0)
{


// to get the current long:)
if(strcmp(logElements[3],"N")==0)
	currLong=atof(logElements[2]);
else if(strcmp(logElements[3],"S")==0)
 currLong=-atof(logElements[2]);

 //to get the current latitude:)
if(strcmp(logElements[5],"E")==0)
	currLatit=atof(logElements[4]);
else if(strcmp(logElements[5],"W")==0)
 currLatit=-atof(logElements[4]);


}


}


