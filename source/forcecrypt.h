int aescrypt() {
char buf[1024];
	char pt1[1024];
	printf("ENTER ENCRYPTION PASSCODE: ");
	scanf("%s", pt1);
	printf(KRED "--DECRYPTING--\n");
	system("touch data/data.fdf");
	system("touch data/cmd_history.fdf");
	snprintf(buf, sizeof(buf), "aescrypt -d -p %s data/data.fdf.aes", pt1);
	system(buf);
	snprintf(buf, sizeof(buf), "aescrypt -d -p %s data/cmd_history.fdf.aes", pt1);
	system(buf);
	system("rm data/data.fdf.aes");
	system("rm data/cmd_history.fdf.aes");
	printf(RSET "--END--");
printf( KWHT"[  " KGRN "OK" KWHT "  ] decryption successful \n");
	sleep(1);
}

int aescryptd() {
char buf[1024];
	char pt2[1024];
	printf("ENTER PASSCODE FOR ENCRYPTION: ");
	scanf("%s", pt2);
	printf(KRED "--ENCRYPTING--\n");
	snprintf(buf, sizeof(buf), "aescrypt -e -p %s data/data.fdf", pt2);
	system(buf);
	snprintf(buf, sizeof(buf), "aescrypt -e -p %s data/cmd_history.fdf", pt2);
	system(buf);
	system("rm data/data.fdf");
	system("rm data/cmd_history.fdf");
	printf(RSET "--END--\n");
    printf( KWHT"[  " KGRN "OK" KWHT "  ] encryption successful \n");
	sleep(1);
	
}

int haltcrypt() {
char buf[1024];
	char pt2[1024] = "xxhaltxx";
	snprintf(buf, sizeof(buf), "aescrypt -e -p %s data/data.fdf", pt2);
	system(buf);
	snprintf(buf, sizeof(buf), "aescrypt -e -p %s data/cmd_history.fdf", pt2);
	system(buf);
	system("rm data/data.fdf");
	system("rm data/cmd_history.fdf");
	printf("HALTED! Encryption passcode set to xxhaltxx\n" RSET);
	sleep(1);
}
