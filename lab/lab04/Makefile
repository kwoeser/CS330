#
# CIS330: Lab 4
#
# Makefile to build libraries and test applications.
#

CC=gcc
AR=ar

CFLAGS=-g -O2 -I./include -L./lib -fPIC 
LIBS=-llab4 -lm

all: lab4 lab4_dyn

obj:
	mkdir -p obj

lib:
	mkdir -p lib

obj/stats.o: src/stats.c include/stats.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

obj/ohno.o: src/ohno.c include/ohno.h obj
	$(CC) $(CFLAGS) -c -o $@ $<

lib/liblab4.a: obj/stats.o obj/ohno.o lib
	$(AR) rc lib/liblab4.a obj/stats.o obj/ohno.o



lib/liblab4.so: obj/stats.o obj/ohno.o lib
	# gcc cc
	$(CC) -shared -o lib/liblab4.so obj/stats.o obj/ohno.o

lab4: src/lab4.c lib/liblab4.a
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

# modify enovirment variable
test:
	export LD_LIBRARY_PATH=test

lab4_dyn: src/lab4.c lib/liblab4.so 
	#echo $LD_LIBRARY_PATH
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
	
	
	
clean:
	rm lab4 lab4_dyn lib/liblab4.a lib/liblab4.so obj/ohno.o obj/stats.o
	rmdir obj
	rmdir lib

