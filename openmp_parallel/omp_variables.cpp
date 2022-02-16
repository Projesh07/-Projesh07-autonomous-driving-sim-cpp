#include <stdio.h>
#include <omp.h>
#include <iostream>
/***
private variable have to initialied inside parallel region, otherwise it get a dumpy value, inside a parallel
region a private variable value does not change from outside initialization.Example int i = 10(outside)
inside parallel region value is, i = 100; when i print value i outside parallel region it will print 10;
share variable always have the same data.firstprivate results in bringing in values from the outside context
into the parallel region while lastprivate transfers values from the parallel region to the outside context.
*/
int i = 1;
int j = 2;
int f(int p)
{
	p = 10;
	printf("printing local variable %d ,%d ,%d \n ", i, j, p); /* (1) */ //output:1,2,10

	return 0;
}

int variable_main(void)
{
	int k = 3;
	int l = 4;
	int o = 7;
	int p = 8;

	printf("Default number of T= %d\n", omp_get_num_threads());

	// set thread only in sequential region
	omp_set_num_threads(4);

#pragma omp parallel shared(j) private(i, o) firstprivate(k)
	{
		printf("Changed number of T= %d\n", omp_get_num_threads());
		printf("Now executing T= %d\n", omp_get_thread_num());
		int m = 5;
		i = i + 1;
		f(p);
		printf("%d ,%d ,%d ,%d ,%d ,%d ,%d \n ", i, j, k, l, m, o, p); /* (2) */ //output: 6 ,2 ,3 ,4 ,5 ,6782624 ,8
	}
	printf("%d", i);
}