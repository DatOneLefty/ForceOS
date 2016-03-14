/*
This file contains the command entery system

 is used when any success at the end of a program happens
*/

int cmdline() {
    
    
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

printf( KWHT"[  " KGRN "OK" KWHT "  ] *Shell \n");
    
for(;;) {
for(;;) {

   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("%s>* ", cwd);
} else {
printf("No Dir>* ");
}

	scanf("%s", maxlen);
	CORE_CMDRUNNER(maxlen);
	
	
    
	if (strcmp(maxlen, "halt") == 0) {
    printf( KWHT"[  " KGRN "OK" KWHT "  ] halt system\n");
	printf(KRED "The system will HALT NOW!\n");
	exit(02);
	}
        
	if (strcmp(maxlen, "stop") == 0) {
	bstop();
	
	CORE_CTRL(0, 0);
	}
	break;

}
}
}
