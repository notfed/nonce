#include "buffer.h"
#include "nonce.h"
static unsigned int fmt_xlong(register char* s,register unsigned long u)
{
  register unsigned int len; register unsigned long q; register char c;
  len = 1; q = u;
  while (q > 15) { ++len; q /= 16; }
  if (s) {
    s += len;
    do { c = '0' + (u & 15); if (c > '0' + 9) c += 'a' - '0' - 10;
    *--s = c; u /= 16; } while(u);
  }
  return len;
}
void nonce_show(const char *nonce)
{
	unsigned int i;
	unsigned int len;
	unsigned char buf[40];
	for(i=0;i<NONCE_BYTES;i++)
	{
	  len = fmt_xlong(buf,(unsigned char)nonce[i]);
	  if(len==1) buffer_put(buffer_1,"0",1);
	  buffer_put(buffer_1,buf,len);
	  buffer_put(buffer_1,",",1);
	}
	buffer_flush(buffer_1);
}
