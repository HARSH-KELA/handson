
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
int fd=open("harsh1.txt",O_RDWR | O_CREAT | O_TRUNC,0644);
if(fd ==-1)
{
perror("error opening file");
return 1;
}

const char *data1="abcdefhgij";
ssize_t byteswritten=write(fd,data1,10);
if(byteswritten !=10)
{
perror("error writing data");
close(fd);
return 1;
}
off_t newpostion=lseek(fd,10,SEEK_CUR);
if(newpostion ==-1)
{
perror("error moving file");
close(fd);
return 1;
}
const char *data2="1234567890";
byteswritten=write(fd,data2,10);
if(byteswritten !=10)
{
perror("error writing data");
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





