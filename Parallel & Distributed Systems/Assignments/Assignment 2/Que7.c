#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 5     //Size of arrays whose elements will be added together.
#define NUM_THREADS 5    //Number of threads to use for vector addition.

int main (int argc, char *argv[])
{
	int * a;
	int * b;
	int * c;    
	int n = ARRAY_SIZE;                     
	int n_per_thread;                       
	int total_threads = NUM_THREADS;    
	int i;       // loop index    
	// allocate space for the arrays    
	a = (int *) malloc(sizeof(int)*n);    
	b = (int *) malloc(sizeof(int)*n);    
	c = (int *) malloc(sizeof(int)*n);    
	for(i=0; i<n; i++)        
	{           
		a[i] = i;           
		b[i] = i;        
	}
	omp_set_num_threads(total_threads);
	
	n_per_thread = n/total_threads;
	
	#pragma omp parallel for shared(a, b, c) private(i) schedule(static, n_per_thread)
	for(i=0; i<n; i++)
	{    
		c[i] = a[i]+b[i];    
		printf(" Thread %d works on element%d\n", omp_get_thread_num(), i);        
	}    
	printf("\n\n");
	printf(" i\ta[i] + b[i]   =\tc[i]\n");    
	printf("\n");    
	for(i=0; i<n; i++)        
	{    
		printf(" %d\t%d\t%d\t%d\n", i, a[i], b[i], c[i]);        
	}    
	// cleaning up memory    
	free(a);    
	free(b);    
	free(c);
	return 0;
}
