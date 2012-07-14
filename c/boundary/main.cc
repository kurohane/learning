#include <stdio.h>

typedef struct {
	char a;
} test1;

typedef struct {
	short b;
	char a;
	char c;
} test2;

typedef struct {
	char a;
	/* pading 1byte */ 
	short b;
	char c;
} test3;

typedef struct {
	short a;
} test4;

typedef struct {
	long a;
} test5;

typedef struct {
	long a;
	short b;
	short c;
} test6;

typedef struct {
	short a;
	long b;
	short c;
} test7;

typedef struct {
	short a;
	short b;
	long c;
} test8;

int main(int ac, char **av) {
	printf("test1 %d char\n", sizeof(test1));
	printf("test2 %d short+char+char\n", sizeof(test2));
	printf("test3 %d char+short+char\n", sizeof(test3));
	printf("test4 %d short\n", sizeof(test4));
	printf("test5 %d long\n", sizeof(test5));
	printf("test6 %d long+short+short\n", sizeof(test6));
	printf("test7 %d short+long+short\n", sizeof(test7));
	printf("test8 %d short+short+long\n", sizeof(test8));

	return 0;
}
