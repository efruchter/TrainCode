all: main-app

run: all
	./main-app

main-app: main.o
	g++ main.o -o main-app -lsfml-graphics -lsfml-window -lsfml-system

main.o:
	g++ -c main.cpp

clean:
	rm *.o main-app
