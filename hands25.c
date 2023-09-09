#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
int pid=fork();
if(pid)
{
if(fork())
{
if(!fork())
{
printf("child3 process id: %d\n",getpid());
printf("child3 parent process id :%d\n",getpid());
sleep(1);
printf("child3 wokeup\n");
}
}
else
{printf("child2 process id: %d \n",getpid());
printf("child2 parent process id : %d\n",getpid());
sleep(5);
printf("child2 wokeup\n");


} 
}
else
{
printf("child1 process id:%d\n",getpid());
printf("child parent process id : %d\n",getpid());
sleep(3);
printf("child1 wokeup\n");
}
waitpid(pid,NULL,0);
return 0;
}
