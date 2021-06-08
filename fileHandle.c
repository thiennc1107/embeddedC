#include <stdio.h>
#include <stdlib.h> 

double * readPID()
{
static double PID[3];
//read any text file from currect directory
char const* const fileName = "pid.txt";

FILE* file = fopen(fileName, "r"); 

if(!file){
printf("\n Unable to open : %s ", fileName);
return -1;
}
char line[500];
int i =0;
while (fgets(line, sizeof(line), file)) {
    PID[i] = atof(line);
    i++;
}
fclose(file);
return PID;
}


