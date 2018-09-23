#include<stdio.h>
#include<time.h>
#include"Header/mymath.h"

int main(){
	clock_t start, end;
    double cpu_time_used;
     
    start = clock();
    printf("%lf\n", mylog(2., 16.));
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", cpu_time_used);
    printf("%i\n", ggTRek(15, 50));
	return 0;
}
