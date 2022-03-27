CC=ccache clang++
CFLAGS=-O3 -Os -Wall
LFLAGS=`wx-config --libs`
IFLAGS=`wx-config --cflags`


help:
	# Options are;
	#   help:  Display this information.
	#   main:  Make main executable.
	#   test:  Run main executable.
	#   strip: Strip main executable.


main:
	$(CC) $(CFLAGS) -o bin/Calculator src/*.cpp $(LFLAGS) $(IFLAGS)


test:
	bin/Calculator


strip:
	strip bin/Calculator
