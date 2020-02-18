cipher: main.o VCipher.o executive.o
	g++ -std=c++11 -g -Wall main.o executive.o VCipher.o -o cipher

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

VCipher.o: VCipher.h
	g++ -std=c++11 -g -Wall -c VCipher.cpp

executive.o: executive.h
	g++ -std=c++11 -g -Wall -c executive.cpp 

clean:
	rm *.o cipher
