#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid, pid1, pid2, pid3;

	pid = fork();
	pid1 = fork();
	pid2 = fork();

	if (pid < 0 || pid1 < 0 || pid2 < 0) {
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if (pid == 0 && pid1 == 0 && pid2 == 0) {
		pid3 = getpid();
		printf("child: pid = %d\n", pid);
		printf("child: pid1 = %d\n", pid1);
		printf("child: pid2 = %d\n", pid2);
		printf("child: pid3 = %d\n\n", pid3);
	}
	else {
		pid3 = getpid();
		printf("parent: pid = %d\n", pid);
		printf("parent: pid1 = %d\n", pid1);
		printf("parent: pid2 = %d\n", pid2);
		printf("parent: pid3 = %d\n\n", pid3);
		wait(NULL);
	}

	return 0;
}