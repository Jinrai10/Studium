#include<stdlib.h>
#include<stdio.h>

int mystrlen(char * __str) {
	int n;
	for (n = 0; __str[n] !='\0'; n++);
	return n;
}

int myatoi(char * __str) {
	int dec = 0;
	int len = mystrlen(__str);
	for(int i=0; i<len; i++){
		dec = dec * 10 + ( __str[i] - '0' );
	}
	return dec;
}

int mystrncpy(char * __str, char * __dest, int len) {
	int lendest = mystrlen(__dest);
	if (len > lendest) len = lendest; 
	for (int i = 0; i<len;i++) {
		__dest[i] = __str[i];
	}		

	return 0;
}

int mystrcmp(char * __str, char * __str2) {
	int len = mystrlen(__str);
	if (len != mystrlen(__str2)) return 0;
	for (int i = 0;i<len;i++) {
		if (__str[i] != __str2[i]) {
			return 0;
		} 
	}	
	
	return 1;
}

char * mystrcat(char * __str, char * __str2) {
	int len1 = mystrlen(__str);
	int len2 = mystrlen(__str2);
	int lencombined = len1 + len2;
	char combined[lencombined];
	for (int i = 0;i < len1; i++){
		combined[i] = __str[i];
	}
	for (int i = 0 ;i < len2; i++){
		combined[i+len1] = __str2[i];
	}
		
	return combined;
}
