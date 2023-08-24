#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
int fd =open("harsh.c",O_RDONLY);
if(fd == -1)
{
perror(" error");
return -1;
}
char buffer[1024];
ssize_t byteread;

while(1)
{
byteread=read(fd, buffer,sizeof(buffer));
if(byteread == 0) break;
write(1,buffer,byteread);
}
if(byteread==-1)
{
perror("error file read");
close(fd);
return 1;
}
if(close(fd)==-1)
{
perror("error closing file");
  return 1;
}
return 0;
}
