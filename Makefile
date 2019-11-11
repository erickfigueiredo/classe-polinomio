All: polinomio.o main.o
	g++ polinomio.o main.o -g -o exec


polinomio.o: polinomio.cpp polinomio.h
	g++ polinomio.cpp -g -c

main.o: main.cpp polinomio.h
	g++ main.cpp -g -c