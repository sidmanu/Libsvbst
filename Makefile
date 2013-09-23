###########################################################
# This code is written by Vishy Hesh & Siddharth Manu
###########################################################


targets: libsvbst.so
OBJS := bst.o

CCFLAGS = -g  -Wall

libsvbst.so: bst.o
	gcc -shared -Wl,-soname,libsvbst.so -o libsvbst.so $(OBJS)
	cp libsvbst.so /usr/lib/libsvbst.so
	ldconfig

bst.o: bst.h 
	gcc -fPIC -c bst.c 

clean:
	rm -rf *.o *.so  *.out  test

####################TESTAPP###############################h

test: test.o
	gcc -lsvbst -I. -fPIC -o test test.c
	
