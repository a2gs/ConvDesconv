/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * Dump a file to HEX ASCII characteres to stdout
 *
 * MIT License
 *
 */

/* conv.c
 * Dump a file to HEX ASCII characteres to stdout
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 03/01/2013 | Creation
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fi = 0;
	unsigned char c = 0;
	
	if(argc != 2){
		printf("Usage:\n");
		printf("\t%s file_in > [FILE_DUMPED_BY_CONV]\n", argv[0]);
		return(-1);
	}
	
	fi = open(argv[1], O_RDONLY);
	if(fi == -1){
		printf("Erro open file [%s]: [%s].\n", argv[1], strerror(errno));
		return(-1);
	}
	
	/* TODO: Read a big buffer for a once */
	for(; read(fi, &c, 1) == 1;)
		printf("%02X", c);
	
	close(fi);
	
	return(0);
}
