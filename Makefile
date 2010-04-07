trynonce : trynonce.o nonce.o strerr.a buffer.a str.a byte.a error.a open.a
	cc -o trynonce trynonce.o nonce.o strerr.a buffer.a str.a byte.a error.a open.a
trynonce.o : trynonce.c buffer.h
	cc -c trynonce.c
nonce.o : nonce.c open.h error.h strerr.h
	cc -c nonce.c
