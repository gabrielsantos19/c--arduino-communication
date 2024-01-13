all: main

main: objects/serial.o objects/unix.o objects/list_ports_linux.o main.cpp
	g++ -Wall -o $@ main.cpp objects/*.o -I serial/include

objects/serial.o: serial/src/serial.cc
	g++ -Wall -o $@ -c serial/src/serial.cc -I serial/include

objects/unix.o: serial/src/impl/unix.cc
	g++ -Wall -o $@ -c serial/src/impl/unix.cc -I serial/include

objects/list_ports_linux.o: serial/src/impl/list_ports/list_ports_linux.cc
	g++ -Wall -o $@ -c serial/src/impl/list_ports/list_ports_linux.cc -I serial/include

clean:
	rm main objects/*.o