#include "open.h"
#include "error.h"
#include "strerr.h"
int nonce_next(const char *filepath)
{
	int fd;
	fd=open_write(filepath);
	if(fd==-1) strerr_die1sys(errno,"trynonce: error");
}
