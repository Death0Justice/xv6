#include "types.h"
#include "stat.h"
#include "user.h"
 
int 
main(int argc, char *argv[]) 
{
    printf(1, "return val of system call is %d\n", munprotect((char *)0x1000, 1));
    exit();
 }