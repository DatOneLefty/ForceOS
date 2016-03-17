int GET_FILE(char * addr) {
char com[5012];
printf("Changing Directory...\n");
chdir("Downloads");
printf("DOWNLOADING!!! DO NOT HALT THE PROGRAM NOW!\n");
snprintf(com, sizeof(com), "wget %s", addr);
if(system(com) == -1) {
printf("Error!\n");
} else {
printf("Download Successful! Check the Downloads Directory!\n");
}
}

int GET_UPDATE() {
char com[5012];
printf("Changing Directory...\n");
chdir("Downloads");
printf("DOWNLOADING!!! DO NOT HALT THE PROGRAM NOW!\n");
system("wget https://github.com/DatOneLefty/ForceOS/archive/master.zip");
system("unzip master.zip");
system("cp -fR ForceOS-master/* ../../ForceOS");
}
