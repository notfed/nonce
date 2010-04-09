#ifndef NONCE_H
#define NONCE_H
#define NONCE_BYTES 12
void nonce_create(const char *filepath);
void nonce_next(const char *filepath, char *nonce);
void nonce_separate(char *nonce, int nserv,int serv);
void nonce_show(const char *nonce);
#endif
