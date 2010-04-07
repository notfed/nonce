#include "open.h"
#include "nonce.h"
#include "error.h"
#include "strerr.h"
static const char zerononce[NONCE_BYTES] = {0};
void nonce_create(const char *filepath)
{
	int fd;
	int i;
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
