# The first rule is executed when the
# command make is typed in the local folder:
all: prog
# executable deps and command to buil1d it:
prog: matrix.o unity.o basic-test-suite.o
	gcc matrix.o basic-test-suite.o unity.o -o prog
# matrix.o deps and command to build it:
matrix.o: matrix.c matrix.h
	gcc -c matrix.c -o matrix.o
basic-test-suite.o: basic-test-suite.c matrix.h unity.h
	gcc -c basic-test-suite.c -o basic-test-suite.o
unity.o: unity.h unity.c unity_internals.h
	gcc -c unity.c -o unity.o


# Special rule to remove all build files
clean:
	rm -rf *.o prog