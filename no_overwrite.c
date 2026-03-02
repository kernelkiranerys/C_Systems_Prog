#include <stdio.h>

int main(void) {
	FILE *fp = fopen("test.txt", "wx");
	
	if (fp == NULL) {
		perror("fopen");
		return 1;
	}

	fputs("File created successfully.\n", fp);
	fclose(fp);
	
	return 0;
}
