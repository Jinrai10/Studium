#include  <stdio.h>

long func1(int x) {
	int y = 3*3*3;
	long c = 1;
	
	for (int i = 1; i <= y; i++) {
		printf("%ld_%i\n", c, i);
		c = c*x;	
	}

	return c;
}

int f(int n) {
	int y = 0;	
	if (n % 2==0) {
		return n/2;
	}else {
		return (n+1)/2;
	}
}

int  main(int argc , char **argv) {
	
	int x = 2;

	printf("%ld\n", func1(x));

	printf("%i\n", f(x));	
	
	return  0;

}


