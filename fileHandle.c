#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
char const* const fileName = "pid.txt";
double * readPID()
{
    static double PID[3];
    //read any text file from currect directory


    FILE* file = fopen(fileName, "r"); 

    char line[500];
    int i =0;
    while (fgets(line, sizeof(line), file)) {
        PID[i] = atof(line);
        i++;
    }
    fclose(file);
    return PID;
}
void savePID (double P,double I,double D)
{
    FILE * fp;
    /* open the file for writing*/
    fp = fopen (fileName,"w");
    
    /* write 10 lines of text into the file stream*/
    fprintf (fp, "%f\n",P );
    fprintf (fp, "%f\n",I );
    fprintf (fp, "%f\n",D );
    
    
    /* close the file*/  
    fclose (fp);
    
}




int main(int argc, char *argv[])
{
    
    if ( argc==2 &&strcmp(argv[1],"-r")==0)
    {
        double *PID = readPID();
        printf("%f\n",PID[0]);
        printf("%f\n",PID[1]);
        printf("%f\n",PID[2]);
    }
    if ( argc==2 &&strcmp(argv[1],"-w")==0)
    {
        savePID(2.1,2.2,2.3);
    }
    
    return 0;
}

