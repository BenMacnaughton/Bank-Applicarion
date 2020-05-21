
polyapp: polyapp.o poly.o utils.o
	gcc -o polyapp polyapp.o poly.o utils.o

polyapp.o: polyapp.c
	gcc -c polyapp.c

poly.o: poly.c
	gcc -c poly.c

utils.o: utils.c
	gcc -c utils.c

clean:
	rm *.o polyapp
