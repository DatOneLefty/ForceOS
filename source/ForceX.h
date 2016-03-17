/*
ForceX StarShell

Like Linux, there is a command entery system, which runs through the StarShell

To do:

[ ] External execution
[ ] returning
[ ] cleanup
[X] ForceX System
*/


int CMD_INIT() { 							//initialized command entery system
    
    
printf( KWHT"[  " KGRN "  " KWHT "  ] clear\r");
if (system("clear")) {
printf( KWHT"[" KRED "FAILED" KWHT "] clear\n");
} else { 
printf( KWHT"[  " KGRN "OK" KWHT "  ] clear\n");
} 
    
printf( KWHT"[  " KGRN "  " KWHT "  ] core connection\r");
if (CORE_CHECK()) {
     printf( KWHT"[" KRED "FAILED" KWHT "] core connetion\n");
} else { 
printf( KWHT"[  " KGRN "OK" KWHT "  ] core connection\n");
}
    
     
printf( KWHT"[  " KGRN "OK" KWHT "  ] print color\n");
     
printf( KWHT"[  " KGRN "OK" KWHT "  ] cmd limit var\n");
char maxlen[5012];
    
printf( KWHT"[  " KGRN "OK" KWHT "  ] cwd var\n");
char cwd[100];
  
printf( KWHT"[  " KGRN "OK" KWHT "  ] dir\n");
char dir[1024];
    
printf( KWHT"[  " KGRN "OK" KWHT "  ] nextfunction\n");
int nextf;

printf( KWHT"[  " KGRN "OK" KWHT "  ] nextfunction\n");
int cmdlimiter = 0;

printf( KWHT"[  " KGRN "OK" KWHT "  ] ForceXStarShell \n");
    

for (;;) {
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("%s>* ", cwd);
} else {
printf("No Dir>* ");
}

	scanf("%s", maxlen);
	FORCEX_EXECUTION(maxlen);
	
	
    
	if (strcmp(maxlen, "halt") == 0) {
    printf( KWHT"[  " KGRN "OK" KWHT "  ] halt system\n");
	printf(KRED "The system will HALT NOW!\n");
	exit(02);
	}
        
	if (strcmp(maxlen, "stop") == 0) {
	bstop();
	
	CORE_CTRL(0, 0);
	}

}
}
int FORCEX_EXECUTION(char * str) {							//Return of commands
int nextf;
  const char s[2] = " ";
   char * cmd;
   
   /* get the first token */
   cmd = strtok(str, s);
   
   /* walk through other tokens */
   while( cmd != NULL ) 
   {
   	if ( nextf == 1 ) {

	if(chdir(cmd) == -1) {
        printf("Directory %s not found\n", cmd);
        } else {
        printf("[>>]\n");
        }

	nextf = 0;
	}
	else if ( nextf == 2) {

	if(fopen(cmd, "w") == -1) {
        printf("Error making file %s", cmd);
        } else {
        printf("[>>]\n");
        }

	}
	else if ( nextf == 3) {
        if(mkdir(cmd) == -1) {
	printf("Error making directory %s", cmd);
	} else {
	printf("[>>]");
	}
	}
	else if (strcmp(cmd, "help") == 0) {
	printf("HELP\n");
	printf("CD [DIR]\n");
	printf("HALT\n");
	printf("STOP");
	printf("TIME\n");
	printf("INFO\n");
	printf("MKFILE [NAME]\n");
	printf("MKDIR [NAME]\n");
	}
	else if (strcmp(cmd, "time") == 0) {
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	printf ( "Current System Time: %s", asctime (timeinfo) );
	}
	else if (strcmp(cmd, "info") == 0) {
	printf("Force OS:\n");
	printf("Created By DatOneLefty\n");
	printf("Copyright 2016 Force Co.\n");
	printf("Version Alpha\n");
	printf("OS Type: Force\n");
	printf("OS Name: Force OS\n");
	printf("Codename: Cryptic Catfish\n");
	printf("Compatablity: UNIX\n");
	printf("Force CO. is not responsible for any damage done to your computer when using this software\n");
	}
	else if (strcmp(cmd, "cd") == 0) {
	nextf = 1;
	}
	else if (strcmp(cmd, "mkfile") == 0) {
	nextf = 2;
	}
	else if (strcmp(cmd, "mkdir") == 0) {
	nextf = 3;
	}
	else if (strcmp(cmd, "ls") == 0) {
	system("ls");
	}
	else {
	CORE_CODE(205);
	}
      cmd = strtok(NULL, s);
   }
}


