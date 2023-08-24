#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
int main(int argc,char *argv[])
{
if(argc!=2)
{
fprintf(stderr,"usage: %s <filename>\n",argv[0]);
return -1;
}
char *filename=argv[1];
struct stat filestat;
if(stat(filename,&filestat)==-1)
{
perror("error getting file status");
return 1;
}
printf("file : %s\n",filename);
printf("inode:%lu\n",filestat.st_ino);
printf("hard links:%lu\n",filestat.st_nlink);
printf("uid : %u\n",filestat.st_uid);
printf("gid : %u\n",filestat.st_gid);
printf("size :%ld bytes\n",filestat.st_size);
printf("block size : %lu bytes\n",filestat.st_blksize);
printf("no of blocks : %lu bytes\n",filestat.st_blocks);
return 0;
}
