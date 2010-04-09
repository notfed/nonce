#include "strerr.h"
#include "nonce.h"
static const char sepmasks[8] = 
{ 0xFF, /* 11111111 0 */
  0xBF, /* 10111111 1 */
  0x9F, /* 10011111 2 */
  0x8F, /* 10001111 3 */
  0x87, /* 10000111 4 */
  0x83, /* 10000011 5 */
  0x81, /* 10000001 6 */
  0x80, /* 10000000 7 */
};
static int numbits(unsigned int num)
{
  register unsigned int c;
  register unsigned int n;
  c = 0;
  n = num-1;
  while(n) { ++c; n/=2; }
  return c;
}
void nonce_separate(char *nonce, int nserv, int serv)
{
        int c;

	if(nserv<1 || nserv>127)
	{ strerr_die1x(111,"trynonce: error: from 1 to 127 servers!"); }
	if(serv<0 || serv>(nserv-1)) 
	{ strerr_die1x(111,"trynonce: error: server num too high!"); }

	c = numbits(nserv);
	nonce[0] &= sepmasks[c]; 
	nonce[0] |= 0x80;
	nonce[0] += serv << (7-c);
}
