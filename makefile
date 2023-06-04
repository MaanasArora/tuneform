main:
	g++ -g -o main.o src/main.cpp src/core/* -I src/core/ -I deps/libsndfile-1.2.0/include -I deps/fftw-3.3.10/api -lsndfile -lfftw3 -lm