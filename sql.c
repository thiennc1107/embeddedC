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

void upLoad(double quality)
{
    conn = mysql_init(NULL);
    mysql_real_connect(conn,server,user,password,database,0,NULL,0);
    char cmd[200];
    sprintf(cmd,"UPDATE `status` SET `error`=%f WHERE 1",quality);
    mysql_query(conn,cmd);
    mysql_close(conn);

}







