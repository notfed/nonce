#include "buffer.h"
#include "nonce.h"
int main(int argc, char *argv[])
{
	char nonce[12];
	nonce_next("mynonce",nonce);
	nonce_show(nonce);
	return 0;
}
