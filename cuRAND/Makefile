INC := -I${CUDA_HOME}/include
# TASK: add cuFFT library into LIB variable
LIB := -L${CUDA_HOME}/lib64 -lcudart -lcuda -lcufft -lcurand

GCC = g++
NVCC = ${CUDA_HOME}/bin/nvcc

NVCCFLAGS = -O3 -arch=sm_35 --ptxas-options=-v -Xcompiler -Wextra -lineinfo

GCC_OPTS =-O3 -Wall -Wextra $(INC)

EXCFILE = cuRAND_normal


all: clean compile

compile: Makefile
	$(NVCC) -o $(EXCFILE) randgen.cu $(LIB) $(NVCCFLAGS) 

clean:	
	rm -f *.o $(ANALYZE)


