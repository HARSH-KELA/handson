#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
fd_set fds;
struct timeval timeout;
FD_ZERO(&fds);
FD_SET(STDIN_FILENO,&fds);

timeout.tv_sec=10;
timeout.tv_usec;

printf("waiting for input from stdin for 10 seconds....\n");
int ready=select(STDIN_FILENO+1,&fds,NULL,NULL,&timeout);
if(ready==-1)
{
perror("error in select");
return 1;
}
else if(ready==0)
{
 printf("no input eithin 10 seconds. \n");
}
else
{
if(FD_ISSET(STDIN_FILENO,&fds))
{
printf("input is available within 10 sec \n");
}
}
return 0;
}

