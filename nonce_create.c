#include "open.h"
#include "nonce.h"
#include "error.h"
#include "strerr.h"
#include "byte.h"
void nonce_create(const char *filepath)
{
	int fd;
	int i;
	char zerononce[NONCE_BYTES];
	byte_zero(zerononce,NONCE_BYTES);
        while((fd=open_excl(filepath))==-1) {
          if(errno==error_intr || errno==error_again)
          { sleep(1); continue; }
          else
          { strerr_die1sys(111,"trynonce: error creating nonce: "); }
	}
	while((i=write(fd,zerononce,NONCE_BYTES))==-1) {
	  if(errno==error_intr || errno==error_again)
          { sleep(1); continue; }
          else
          { strerr_die1sys(111,"trynonce: error creating nonce: "); }
	}
	close(fd);
}
