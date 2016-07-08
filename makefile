all: main.o NormalizeDocum.o ClassifyDocum.o
	clear
	g++ main.o NormalizeDocum.o ClassifyDocum.o  -std=c++11 -o out
	rm *.o 

main.o: ./main.cpp
	g++ -c -std=c++11 ./main.cpp

NormalizeDocum.o: ./NormalizeDocum.cpp
	g++ -c -std=c++11 ./NormalizeDocum.cpp

ClassifyDocum.o: ./ClassifyDocum.cpp
	g++ -c -std=c++11 ./ClassifyDocum.cpp
