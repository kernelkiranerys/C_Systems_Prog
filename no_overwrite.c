#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	const char *path = "demo_no_overwrite.txt";

	if (argc > 1) {
		path = argv[1];
	}

	errno = 0;
	FILE *fp = fopen(path, "wx");
	if (fp == NULL) {
		fprintf(stderr, "Failed to create '%s' with mode 'wx'.\n", path);
		perror("fopen");
		return EXIT_FAILURE;
	}

	fputs("Created without overwriting an existing file.\n", fp);

	if (fclose(fp) != 0) {
		perror("fclose");
		return EXIT_FAILURE;
	}

	printf("Created '%s' successfully.\n", path);
	return EXIT_SUCCESS;
}
