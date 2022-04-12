#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"
int
main(int argc, char *argv[])
{
  // allocate the page for testing
  char *start = sbrk(0);
  sbrk(PGSIZE);
  *start=100;

  mprotect(start, 1);
  printf(1, "Protected address has value: %d\n",*start);

  // test inherited protection in fork
  int child=fork();
  if(child)
  {
    // parent process
    wait();
    // test munprotect
    printf(1, "Unprotecting...\n"); 
    munprotect(start, 1);
    printf(1, "Writing to read-write page...\n"); 
    *start=5;
    printf(1, "After unprotecting the value became: %d\n",*start);
    exit();
  }
  else
  {
    // child process
    // test inherited mprotect
    printf(1, "Writing to read-only page...\n"); 
    *start=5;
    printf(1, "This should not be seen.\n");
    exit();
  }
  exit();
}