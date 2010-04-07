trynonce : trynonce.o
	cc -o trynonce trynonce.o buffer.a
trynonce.o : trynonce.c
	cc -c trynonce.c
