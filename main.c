#include "stdlib.h"
#include "stdio.h"
#include "string.h"


void main(char argc, char *argv[])
{
	FILE * fn;
	FILE * out;
	char pole[200];

	if (argc != 2){
		printf("nic nebude\n");
		exit(1);
	}

	fn = fopen(argv[1],"w");
	out = popen("git log", "r");

	if (fn == NULL)
	{
		printf("hash file doesn't exists");
		exit(1);
	}

	if (out == NULL)
	{
		printf("no program output");
		exit(1);
	}

	fgets(pole,sizeof(pole)-1, out);
	printf("%s\n",pole);
	int i = strlen(pole);
	pole[i-1] = 0;

	fprintf(fn,"#define BOARD_NAME \"%s\" \n",pole);

	fclose(fn);
}
