#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int pipe_fd[2];
	pid_t pid;

	if (pipe(pipe_fd) == -1) {
		perror("pipe");
		return 1;
	}

	pid = fork();
	if (pid < 0) {
		perror("fork");
		return 1;
	}

	if (pid == 0) {
		int write_message[1];

		close(pipe_fd[0]);

		printf("Enter an integer: ");
		if (scanf("%d", &write_message[0]) != 1) {
			fprintf(stderr, "Invalid input.\n");
			close(pipe_fd[1]);
			return 1;
		}

		if (write(pipe_fd[1], write_message, sizeof(write_message)) != sizeof(write_message)) {
			perror("write");
			close(pipe_fd[1]);
			return 1;
		}

		close(pipe_fd[1]);
		return 0;
	}

	{
		int read_message[1];

		close(pipe_fd[1]);

		if (read(pipe_fd[0], read_message, sizeof(read_message)) != sizeof(read_message)) {
			perror("read");
			close(pipe_fd[0]);
			wait(NULL);
			return 1;
		}

		close(pipe_fd[0]);

		printf("Square of %d is %d\n", read_message[0], read_message[0] * read_message[0]);
		wait(NULL);
	}

	return 0;
}
