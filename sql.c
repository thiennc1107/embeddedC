#include <mysql.h>
#include <stdio.h>
#include <stdlib.h> 
#include<unistd.h>
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;
char *server = "localhost";
char *user = "thiennc";
char *password = "11072001";
char *database = "embedded";
double * getPID(void)
{
    
    conn = mysql_init(NULL);
    mysql_real_connect(conn,server,user,password,database,0,NULL,0);
    char data[10];
    static double PID[3];
    mysql_query(conn, "SELECT * FROM `pid` where 1");
    res = mysql_store_result(conn); 
    while (row = mysql_fetch_row(res)) 
	{ 
	    sprintf(data,row[0]);
        PID[0] = atof(data);
        sprintf(data,row[1]);
        PID[1] = atof(data);
        sprintf(data,row[2]);
        PID[2] = atof(data);
	}  
    mysql_close(conn);   
    return PID;   
    
}
void upLoad(double error,double speed,double angle)
{
    conn = mysql_init(NULL);
    mysql_real_connect(conn,server,user,password,database,0,NULL,0);
    char cmd[200];
    sprintf(cmd,"UPDATE `status` SET `error`=%f,`speed`=%f,`angle`=%f WHERE 1",error,speed,angle);
    mysql_query(conn,cmd);
    mysql_close(conn);

}






