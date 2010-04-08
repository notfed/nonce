#include "open.h"
#include "byte.h"
#include "error.h"
#include "strerr.h"
#include "nonce.h"
#include "seek.h"
#include "taia.h"
void nonce_next(const char *filepath, char *nonce)
{
	int fd;
	int i;
	int j;
        struct taia oldtemps;
        struct taia nowtemps;
        struct taia onenanosecond;
        char tmpnonce[NONCE_BYTES];
        byte_zero(tmpnonce,NONCE_BYTES);
        byte_zero((char*)&onenanosecond,sizeof(onenanosecond));
        onenanosecond.nano = 1;

	/* 12 Nonce Bytes */

	while((fd=open_rw(filepath))==-1) {
	  if(errno==error_intr || errno==error_again) 
	  { sleep(1); continue; }
	  else if(errno==error_noent)
	  { nonce_create(filepath); continue; }
	  else 
	  { strerr_die1sys(111,"trynonce: error opening nonce: "); }
	}
	while((i=read(fd,tmpnonce,NONCE_BYTES))==-1) {
	  if(errno==error_intr || errno==error_again) 
	  { sleep(1); continue; }
	  else 
	  { strerr_die1sys(111,"trynonce: error reading nonce: "); }
	} 
	if(i!=NONCE_BYTES) {
	  strerr_die1x(111,"trynonce: error: short nonce");
	}

        taia_now(&nowtemps);
        taia_unpack(tmpnonce,&oldtemps);
        if(taia_less(&nowtemps,&oldtemps))
            nowtemps = oldtemps;
        taia_add(&nowtemps,&nowtemps,&onenanosecond);
        taia_pack(&tmpnonce,&nowtemps);

	if(seek_begin(fd)==-1) 
	  strerr_die1sys(111,"trynonce: error rewinding nonce: ");
	while((i=write(fd,tmpnonce,NONCE_BYTES))==-1) {
	  if(errno==error_intr || errno==error_again) 
	  { sleep(1); continue; }
	  else 
	  { strerr_die1sys(111,"trynonce: error writing nonce: "); }
	} 
	close(fd);
	byte_copy(nonce,NONCE_BYTES,tmpnonce);
}
