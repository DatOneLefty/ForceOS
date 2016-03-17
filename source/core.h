#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RSET "\033[0m"
int CORE_CHECK() {
 return 0;   
}

int CORE_CTRL(int type, int code) {
if (type == 0) { //System Controller
	if (code == 0) {
printf( KWHT"[  " KGRN "  " KWHT "  ] stop\r");
exit(00);
printf( KWHT"[  " KGRN "OK" KWHT "  ] stop\n");
	}
	if (code == 1) {
printf( KWHT"[  " KGRN "  " KWHT "  ] halt\r");
		haltcrypt();
		exit(01);
        printf( KWHT"[  " KGRN "OK" KWHT "  ] halt\n");
	}
}

if (type == 1) { //COMMAND CONTROL
	;
}
}
/*
Force Co Error Systems

100		success
200		system error
300		internet error
400		CORE error
500		boot error

*/
int CORE_CODE(int code) {
										//100 SYS
if (code == 100) { 								// success
	printf("\n");
}
else if (code == 101) {								// partial
	printf("CORE: warn: partial data recieved\n");
}
else if (code == 102) {								// no data
	printf("CORE: warn: no data\n");
}
										// 200 ERR

else if (code == 200) {								// general
	printf("CORE: warn: system error\n");
}
else if (code == 201) {								// force quit
	printf("CORE: fatal: process foribly quit\n");
	CORE_CTRL(0, 1);
}
else if (code == 202) {								// system force quit
	printf("CORE: fatal: system process stopped\n");
	CORE_CTRL(0, 1);
}
else if (code == 203) {								// process stopped by user
	printf("CORE: warn: stopped by user\n");
}
else if (code == 204) {								// CORE stop process
	printf("CORE: warn: stopped by CORE\n");
}
else if (code == 205) {
	printf("CORE: command not found\n");					//not found
}
else if (code == 206) {
	printf("CORE: Program stopped by self\n");				//stop self
}
else if (code == 207) {
	printf("CORE: Program stopped by user\n");				//stop user
}
										// 300 ERR
else if (code == 300) {
	printf("CORE: warn: internet error\n");				//CORE panic
}
else if (code == 301) {
	printf("CORE: warn: no connection\n");				//no connection
}
else if (code == 302) {
	printf("CORE: warn: log in required\n");				//log in
}
else if (code == 303) {
	printf("CORE: warn: interrupted connection\n");			//interrupted
}
										//400 	CORE
else if (code == 400) {
	printf("CORE: fatal: CORE error\n");				//CORE error
	CORE_CTRL(0, 1);
}
else if (code == 401) {
	printf("CORE: fatal: CORE panic\n");				//panic
	CORE_CTRL(0, 1);
}
else if (code == 402) {
	printf("CORE: fatal: CORE interrupted\n");				//CORE interupted
	CORE_CTRL(0, 0);
}
										//500 ERR
else if (code == 500) {
	printf("CORE: fatal: boot disk not found\n");				//boot no disk
	CORE_CTRL(0, 1);
}
else if (code == 501) {
	printf("CORE: Booting to BIOS\n");					//bios
	CORE_CTRL(0, 0);
}
else if (code == 502) {
	printf("CORE: fatal: boot canceled\n");				//boot canceled
	CORE_CTRL(0, 1);
}
else if (code == 503) {
	printf("CORE: fatal: shut down\n");					//boot stop
	CORE_CTRL(0, 0);
}
else {
	printf("ERROR CODE NOT VALID!\n");
	CORE_CTRL(0, 1);
}
}

int CORE_CMD_APP() {
char an[100];
char path[100] = "./apps/";
printf("APP NAME>* ");
scanf("%s" , an);
strcat(path, an);
system(path);
}
int CORE_SYS_PASS(int id) {
if (id == 0) {
	printf("CORE: program gracefully exited");
	exit(0);
}
}
