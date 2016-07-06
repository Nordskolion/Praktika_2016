all: main.o NormalizeDocum.o
	g++ main.o NormalizeDocum.o  -std=c++11 -o out
	rm *.o 

main.o: ./main.cpp
	g++ -c -std=c++11 ./main.cpp

NormalizeDocum.o: ./NormalizeDocum.cpp
	g++ -c -std=c++11 ./NormalizeDocum.cpp 