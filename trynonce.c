#include "buffer.h"
#include "nonce.h"
int main(int argc, char *argv[])
{
	char nonce[12];
	buffer_putsflush(buffer_1,"{");
	nonce_next("mynonce",nonce);
	nonce_show(nonce);
	buffer_putsflush(buffer_1,"}\n");
	return 0;
}
