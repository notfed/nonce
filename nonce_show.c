#include "buffer.h"
#include "nonce.h"
#include "fmt.h"
void nonce_show(const char *nonce)
{
	unsigned int i;
	unsigned int len;
	unsigned char buf[40];
	buffer_put(buffer_1,"{",1);
	for(i=0;i<NONCE_BYTES;i++)
	{
	  if(i!=0) buffer_put(buffer_1,",",1);
	  len = fmt_xlong(buf,(unsigned char)nonce[i]);
	  if(len==1) buffer_put(buffer_1,"0",1);
	  buffer_put(buffer_1,buf,len);
	}
	buffer_put(buffer_1,"}\n",2);
	buffer_flush(buffer_1);
}
