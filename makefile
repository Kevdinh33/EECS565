cipher: main.o VCipher.o
	g++ -std=c++11 -g -Wall main.o VCipher.o -o cipher

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

VCipher.o: VCipher.h
	g++ -std=c++11 -g -Wall -c VCipher.cpp

clean:
	rm *.o cipher
