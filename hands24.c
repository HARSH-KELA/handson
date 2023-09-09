#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
if(!fork())
{
printf("child-before orphan ppid=%d\n",getpid());
sleep(5);
printf("child after orphan ppid=%d\n",getppid());
}
else
{
printf("this is parent process %d\n",getpid());
exit(0);
}
return 0;
}
