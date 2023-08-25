#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
 const char *filename="harsh1.txt";

 int fd=open(filename,O_RDONLY);
 if(fd==-1)
{
 perror("error opening file");
 return 1;
}
 int mode=fcntl(fd,F_GETFL);

int access_mode=mode & O_ACCMODE;
 if(access_mode==-1)
{
perror("error getting acces");
}
else
{
if(access_mode & O_RDONLY)
{
 printf("file is open in read only mode.\n");
}
else if(access_mode & O_WRONLY)
{
 printf("file is open in write  only mode.\n");
}
else if(access_mode & O_RDWR)
{
 printf("file is open in read-Write  only mode.\n");
}
}
close(fd);
return 0;
}

