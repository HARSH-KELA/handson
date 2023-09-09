#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
int fd;
 pid_t pid;
 char buffer[50];
 fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
 if (fd == -1) {
 perror("Failed to open file");
 exit(1);
 }
 pid = fork();
if (pid == -1) {
  perror("Fork failed");
  exit(1);
   }
  if (pid == 0) {
  snprintf(buffer, sizeof(buffer), "Child process (PID %d) writing to file.\n", getpid());
  write(fd, buffer, strlen(buffer));
 sleep(5);
    } else {
  snprintf(buffer, sizeof(buffer), "Parent process (PID %d) writing to file.\n", getpid());
   write(fd, buffer, strlen(buffer));
    sleep(2);
    }
    close(fd);
    printf("File contents:\n");
    char file_content[100];
    fd = open("output.txt", O_RDONLY);
    
    if (fd == -1) {
        perror("Failed to open file for reading");
        exit(1);
    }

    ssize_t bytes_read = read(fd, file_content, sizeof(file_content));
    
    if (bytes_read == -1) {
        perror("Read failed");
        exit(1);
    }
    file_content[bytes_read] = '\0';
    printf("%s", file_content);
    close(fd);

    return 0;
}

