trynonce : trynonce.o nonce_next.o nonce_show.o nonce_create.o seek.a strerr.a buffer.a str.a byte.a error.a open.a fmt.a
	cc -o trynonce trynonce.o nonce_next.o nonce_show.o nonce_create.o seek.a strerr.a buffer.a str.a byte.a error.a open.a fmt.a
trynonce.o : trynonce.c 
	cc -c trynonce.c
nonce_next.o : nonce_next.c
	cc -c nonce_next.c
nonce_show.o : nonce_show.c
	cc -c nonce_show.c
nonce_create.o : nonce_create.c
	cc -c nonce_create.c
