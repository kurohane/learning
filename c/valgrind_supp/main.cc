#include <stdio.h>

int main(int ac, char **av) {
	FILE *fp = fopen(av[1], "r");
	if (fp) {
		char buff[0x100];
		while (fgets(buff, sizeof(buff), fp)) {
			if (buff[0] == '=') continue;
			printf("%s", buff);
		}
		fclose(fp);
	}
	return 0;
}

