#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"mymath.h"
#define pi 3.14159265359

int sgn(int x) {
	if(x < 0) {
		return -1;
	}else if(x > 0) {
		return 1;
	}
	return 0;	
}

int betrag(int x) {
	if(x >= 0) {
		return x;
	}
	return -x;
}

int ggT(int a, int b) {
	while(a != 0 && b != 0) {			
		if (a > b) {
			a = a-b;
		}else {
			b = b-a;
		}
	}
	return (a == 0) ? b: a;
}

int ggTRek(int a, int b) {
	if (a == 0) {
		return b;
	}else if (b == 0) {
		return a;
	}else if (a>b){
		return ggT(a-b, b);
	}else {
		return ggT(a, b-a);
	}
}

int schaltJahr(int jahr) {
	if (jahr < 0) {
		return 0;
	}	
	
	if (jahr % 4 == 0) {
		if(jahr % 100 == 0) {
			if (jahr % 400 == 0) {
				return 1;
			}
			return 0;
		}
		return 1;
	}
	return 0;
}

int agypMult(int x, int y) {
	int k = 0;
	if (x == 0) {
		return 0;
	}
	while(x > 1) {
		if (x % 2 != 0) {
			x -= 1;
			k += y;
		}else {
			x /= 2;
			y *= 2;
		}
	}
	return k + y;
}

double power(double x, int n) {
	double p = 1;
	double x_placeholder = x;
	
	while (n > 0) {
		if (n % 2 == 1) {
			p *= x_placeholder;			
		}
		x_placeholder*=x_placeholder;
		n = (int) n/2; 
	}
	return p;
}

double naiv_power(double x, long n) {
	double p = 1;
	for (int i = 1; i <= n; i++) {
		p*=x;
	}
	return p;
}

int fak(int n) {
	if (n == 0){
		return 1;
	}
	return fak(n-1)*n;
}

double expo(int x) {
	double sum = 0;
	for (int i = 0;i < 1000000; i++) {
		sum += power(x, i)/fak(i);
	}
	return sum;
}

int prim(int c) {
	double root;
	for (int i = 2; i<10000;i++) {
		root = sqrt((double) c);
		if (i - root > 0) {
			return 1;
		}else if(c % i == 0){
			return 0;
		}
	}
	return 0;
}

double myln(double x) {
	double log = 0;
	double t = (x - 1.0) / (x + 1.0);
	for (int i = 0;i < 100; i++) {
		log += power(t, (2.0 * i + 1.0)) / (2.0 * i +1.0);
	}
	log*=2;
	return log;
}

double mylog(double a, double x) {
	return myln(x) / myln(a);
} 

double myroot(double n, double x) {
	return power(x, 1/n);
}

double get3rdSide(double a, double b, double w) {
	double h = 0;
	double diff = 0;
	double c = 0;
	double radiant = ((2*pi)/360)*w; 
	
	if (w == 90) {
			return a*a + b*b;
	}
	
	h = sin(radiant)*a;
	diff = sqrt(a*a - h*h);
	c = sqrt((b-diff)*(b-diff) + h*h);	 
	return c;
}

int fibonacci(int n) {
	if (n == 1) {
		return 1;
	}else if (n == 0) {
		return 0;
	}else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

double abc(double a, double b, double c) {
	int x1 = 0;
	int x2 = 0;
	
	x1 = (-b + sqrt(b*b - 4*a*c))/2*a;

	x2 = (-b - sqrt(b*b - 4*a*c))/2*a;
	
	return x1>x2 ? x1:x2;
}
