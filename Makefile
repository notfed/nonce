CC=cc
nonce.a : makelib nonce_next.o nonce_show.o nonce_separate.o nonce_create.o 
	./makelib nonce.a nonce_next.o nonce_show.o nonce_separate.o nonce_create.o 
nonce_next.o : nonce_next.c
	$(CC) -c nonce_next.c
nonce_show.o : nonce_show.c
	$(CC) -c nonce_show.c
nonce_separate.o : nonce_separate.c
	$(CC) -c nonce_separate.c
nonce_create.o : nonce_create.c
	$(CC) -c nonce_create.c
