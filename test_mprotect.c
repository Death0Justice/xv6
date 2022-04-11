#include "types.h"
#include "stat.h"
#include "user.h"
 
int 
main(int argc, char *argv[]) 
{
    printf(1, "return val of system call is %d\n", mprotect((char *)0x1024, 1));
    printf(1, "Congrats !! You have successfully added new system  call in xv6 OS :) \n");
    exit();
 }