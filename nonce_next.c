#include "open.h"
#include "byte.h"
#include "error.h"
#include "strerr.h"
#include "nonce.h"
#include "seek.h"
/* nonce12 version (12-byte counter) */
void nonce_next(const char *filepath, char *nonce)
{
	int fd;
	int i;
	int j;
	char tmpnonce[NONCE_BYTES];
	byte_zero(tmpnonce,NONCE_BYTES);
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
	for(j=0;j<NONCE_BYTES;j++)
	{
	  if((++tmpnonce[j])!=0) break;
	}
	if(seek_begin(fd)==-1) 
	  strerr_die1sys(111,"trynonce: error rewinding nonce: ");
	while((i=write(fd,tmpnonce,NONCE_BYTES))==-1) {
	  if(errno==error_intr || errno==error_again) 
	  { sleep(1); continue; }
	  else 
	  { strerr_die1sys(111,"trynonce: error writing nonce: "); }
	} 
	byte_copy(nonce,NONCE_BYTES,tmpnonce);
	close(fd);
}
