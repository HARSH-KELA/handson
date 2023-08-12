#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
int fd;
fd=creat("demo.txt",0644);
if(fd == -1)
{
perror("error creating file");
exit(1);
}
printf("descriptor value:%d\n",fd);
close(fd);
return 0;
}
