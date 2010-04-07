#ifndef NONCE_H
#define NONCE_H
#define NONCE_BYTES 12
#define RAND_BYTES 4
void nonce_create(const char *filepath);
void nonce_next(const char *filepath, char *nonce);
void nonce_show(const char *nonce);
#endif
