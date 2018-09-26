#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int args, char ** argv) {
	
	char buffer[256];
	char buffer1[256];
	int enthalten = 0;
	
	FILE * fd = fopen(argv[1], "r");
	FILE * fg = fopen(argv[2], "w+");
	
	if (fd == NULL || fg == NULL) {
		exit(0);
	}
	while(fgets(buffer, 255, fd) != NULL) {
		enthalten = 0;
		printf("%s", buffer);
		while(enthalten == 0) {
			if (fgets(buffer1, 255, fg) != NULL) {
				if (strcmp(buffer, buffer1) == 0) {
					enthalten = 1;
				}			
			}else {
				break;
			}
		}
		if(enthalten == 0) fprintf(fg, "%s", buffer); 
	}
	fclose(fd);
	fclose(fg);
	
	return 0;
}
