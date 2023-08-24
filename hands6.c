
#include<unistd.h>
int main()
{
 char buffer[1024];
 while(1)
{
 ssize_t byteread=read(STDIN_FILENO,buffer,sizeof(buffer));
if(byteread<=0)
{
break;
}
write(STDIN_FILENO,buffer,byteread);
}
return 0;
}