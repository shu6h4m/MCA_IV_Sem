#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void monteCarlo(int N, int K){
	// This Function is used to find estimated value of PI using Monte Carlo algorithm.
	double x, y;
	double d;
	int pCircle = 0;
	int pSquare = 0;

	int i = 0;


	#pragma omp parallel firstprivate(x, y, d, i) reduction(+ : pCircle, pSquare) num_threads(K){
		// Parallel calculation of random points lying inside a circle

		
		srand((int) time(NULL));	// Initializes random points with a seed.

		for (i = 0; i < N; i++) 
		{
			x = (double) drand48();
			y = (double) drand48();
			d = ((x * x) + (y * y));
			if (d <= 1) 
			{
				pCircle++;
			}
			pSquare++;
		}
	}
	double pi = 4.0 * ((double) pCircle / (double)(pSquare));
	printf("Final Estimation of Pi = %f\n", pi);
}

// Driver Code
int main(){
	//Driver code.
	int N = 100000;
	int K = 8;
	monteCarlo(N, K);
}

