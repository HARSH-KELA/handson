#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_info;
    if (stat(argv[1], &file_info) == -1) {
        perror("Error getting file information");
        return 1;
    }

    if (S_ISREG(file_info.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("Directory\n");
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }

    return 0;
}

