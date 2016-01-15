// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

void
mine(void)
{ 
int i ;
for(i=0;i<10;i++){
  write(1, i,sizeof(i));
  sleep(100);
}

}

int
main(void)
{
  mine();
  exit();
}
