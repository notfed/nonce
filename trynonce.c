#include "buffer.h"
#include "nonce.h"
int main(int argc, char *argv[])
{
	char nonce[12];
	if(!argv[1]) argv[1]="nonce";
	nonce_next(argv[1],nonce);
	nonce_show(nonce);
	return 0;
}
