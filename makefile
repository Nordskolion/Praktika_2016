all: andreyPraktika.o NormalizeDocum.o
	g++ andreyPraktika.o NormalizeDocum.o  -std=c++11 -o out
	rm *.o 

andreyPraktika.o: ./andreyPraktika.cpp
	g++ -c -std=c++11 ./andreyPraktika.cpp

NormalizeDocum.o: ./NormalizeDocum.cpp
	g++ -c -std=c++11 ./NormalizeDocum.cpp 