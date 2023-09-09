#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);

    printf("Using execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);

    printf("Using execle:\n");
    char* envp[] = { "PATH=/bin", NULL };
    execle("/bin/ls", "ls", "-Rl", NULL, envp);

    printf("Using execv:\n");
    char* argv[] = { "ls", "-Rl", NULL };
    execv("/bin/ls", argv);

    printf("Using execvp:\n");
    execvp("ls", argv);

    perror("exec");
    return 1;
}

