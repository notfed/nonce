trynonce : trynonce.o
	cc -o trynonce trynonce.o buffer.a str.a byte.a error.a
trynonce.o : trynonce.c
	cc -c trynonce.c
