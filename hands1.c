#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    int v =symlink("dest1.txt","destSL");
    if(v<0)
        {perror("failed");return 1;}
    int f = link("dest1.txt","destHL");


    if(f<0)
        {perror("Failed");}
    int e = mknod("destFIFO",S_IFIFO,0);
    if(e<0)
        perror("failed");
    return 0;
}