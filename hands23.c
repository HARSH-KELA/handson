#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
if(!fork())
{
printf("in child- pid=%d\n",getpid());
}
else
{
printf("this is parent proces %d\n",getpid());
sleep(10);
wait(0);
}
return 0;
}
