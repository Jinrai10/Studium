#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int uniq(char * a, char * b) {
	char buffer[256];
	char buffer1[256];
	int enthalten = 0;
	
	FILE * fd = fopen(a, "r");
	FILE * fg = fopen(b, "a+");
	fclose(fg);
	if (fd == NULL || fg == NULL) {
		exit(0);
	}
	while(fgets(buffer, 255, fd) != NULL) {	
		fg = fopen(b, "r+");
	
		enthalten = 0;
		while(enthalten == 0 && fgets(buffer1, 255, fg) != NULL) {
			if (strcmp(buffer, buffer1) == 0) enthalten = 1;
		}
		if(enthalten == 0) {
			fprintf(fg, "%s", buffer);
			printf("%s", buffer);
		}
		fclose(fg);
	}
	fclose(fd);
	
	return 0;
}

int main(int args, char ** argv) {
	uniq(argv[1], argv[2]);
}
