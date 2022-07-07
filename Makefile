CC=ccache clang++
CFLAGS=-O3 -Os
LFLAGS=`wx-config --libs`
IFLAGS=`wx-config --cflags`
WARNS=-Wall -Werror


help:
	# Options are;
	#   help:     Display this information.
	#   compile:  Compile program into an executable.
	#   test:     Run main executable.
	#   strip:    Strip main executable.


compile:
	$(CC) $(CFLAGS) $(WARNS) -o bin/Calculator src/*.cpp $(LFLAGS) $(IFLAGS)


test:
	bin/Calculator


strip:
	strip bin/Calculator
