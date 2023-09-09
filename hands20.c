#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main()
{
int old_priority, new_priority;

old_priority = getpriority(PRIO_PROCESS, getpid());
  if (old_priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("Old priority: %d\n", old_priority);

  new_priority = nice(10); 
    if (new_priority == -1) {
        perror("Error setting priority");
        return 1;
    }

   
    old_priority = getpriority(PRIO_PROCESS, getpid());
    if (old_priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("New priority: %d\n", old_priority);

    return 0;
}
