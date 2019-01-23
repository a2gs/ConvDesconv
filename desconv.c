/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 * Read a dumped file (generated from conv) from stdin and convert to binary values.
 *
 * Public Domain
 *
 */

/* desconv.c
 * Read a dumped file (generated from conv) from stdin and convert to binary values.
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
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fi = 0;
	char c[5] = {0};
	uint8_t ic = 0;

	if(argc != 2){
		printf("Usage:\n");
		printf("\tcat [FILE_DUMPED_BY_CONV] | %s [NEW_OUTPUT_FILE_CREATED]\n", argv[0]);
		return(-1);
	}

	fi = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fi == -1){
		printf("Error open file [%s]: [%s].\n", argv[1], strerror(errno));
		return(-1);
	}

	for(; read(STDIN_FILENO, &c[2], 2) == 2;){
		c[0] = '0';
		c[1] = 'x';
		c[4] = '\0';

		ic = (int)strtoul(c, NULL, 16);

		if((errno == ERANGE && (ic == LONG_MAX || ic == LONG_MIN)) || (ic != 0 && ic == 0)){
			printf("Erro de conversao no valor: [%d][%s]\n", ic, c);
			return(-1);
		}

		/* TODO: Write a big buffer for a once */
		if(write(fi, &ic, 1) != 1){
			printf("Erro writting to file [%s]: [%s].\n", argv[1], strerror(errno));
			break;
		}
	}

	return(0);
}
