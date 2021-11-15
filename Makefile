build:
	gcc -o build $(mariadb_config --cflags) ./sql.c $(mariadb_config --libs) -g -lwiringPi -lpthread -lm
run:
	./build