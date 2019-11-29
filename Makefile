All: polinomio.o main.o
	g++ polinomio.o main.o -o exec 

polinomio.o: polinomio.cpp polinomio.h 
	g++ polinomio.cpp -c 

main.o: main.cpp polinomio.h 
	g++ main.cpp -c 