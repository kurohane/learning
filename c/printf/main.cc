#include <stdio.h>

int main(int ac, char **av) {
	printf("%%d   [%d]\n", 18);
	printf("%%2d  [%2d]\n", 18);
	printf("%%8d  [%8d]\n", 18);
	printf("%%08d [%08d]\n", 18);
	printf("%%x   [%x]\n", 18);

	printf("%c  %%c \'0\' + 4\n", '0' + 4);
	printf("%d %%d \'0\'\n", '0');
	printf("%c  %%c 48 + 4\n", 48 + 4);
	printf("[%8s]\n", "piyo");

	return 0;
}
