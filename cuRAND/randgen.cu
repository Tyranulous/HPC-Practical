#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <curand.h>

#define CUDA_CALL(x) do { if((x)!=cudaSuccess) {\
	printf("Error at %s:%d\n", __FILE__,__LINE__);\
	return EXIT_FAILURE;}} while(0)

#define CURAND_CALL(x) do { if((x)!=CURAND_STATUS_SUCCESS) { \
	printf("Error");\
	return EXIT_FAILURE;}} while(0)

int main(void)
{
	
	size_t n = 100;
	size_t i;
	curandGenerator_t gen;
	float *d_data, *h_data;
	float mean, stddev;

//Set mean and standard deviation
	mean = 0.0;
	stddev = 1.0;

// Allocate n floats on host
	
	h_data = (float *)malloc(n*sizeof(h_data));
	

// Allocate n floats on device

	CUDA_CALL(cudaMalloc((void **)&d_data, n*sizeof(d_data)));

//Create random number generator
	CURAND_CALL(curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_DEFAULT));

//Set seed
	CURAND_CALL(curandSetPseudoRandomGeneratorSeed(gen, 1234ULL));

//Generate n normally distributed values
	CURAND_CALL(curandGenerateNormal(gen, d_data, n, mean, stddev));

//Copy generated numbers to host
	CUDA_CALL(cudaMemcpy(h_data, d_data,n * sizeof(float), cudaMemcpyDeviceToHost));

//Print results
	for (i = 0; i < n; i++)
	{
		printf("%1.4f ", h_data[i]);
		printf("\n");
 	}

//Cleanup
	CURAND_CALL(curandDestroyGenerator(gen));
	CUDA_CALL(cudaFree(d_data));
	free(h_data);
	return EXIT_SUCCESS;
}

