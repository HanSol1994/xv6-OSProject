/*#include "types.h"

#include "fcntl.h"

#include "stat.h"

#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "spinlock.h"

#include "user.h"
#include "proc.h"

struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;

int nextpid = 1;
extern void forkret(void);
extern void trapret(void);


void
myrun3(void)
{

  int fd = open ("Hprocess.txt",O_RDONLY);
  
  //int pid;
  struct proc np;

  read( fd,&np.sz,sizeof((&np)->sz) );
  read( fd,&np.parent,sizeof((&np)->parent) );
  read( fd,&np.tf,sizeof((&np)->tf) );

  (&np)->tf->eax = 0;

  read( fd,&np.cwd,sizeof((&np)->cwd) );


 
  read( fd,&np.name,sizeof((&np)->name) );
 
  //pid = proc->pid;

  // lock to force the compiler to emit the np->state write last.
  ////acquire(&ptable.lock);
  (&np)->state = RUNNABLE;
  ////release(&ptable.lock);
  close(fd);


  //return pid;
}

void
myrun2(void)
{
  int fd = open ("Hprocess.txt",O_RDONLY);
  
	
  read( fd,a,sizeof(proc) );
  write(1,a,sizeof(proc));
  //proc->tf->eax = 0;

  
  //pid = proc->pid;

  // lock to force the compiler to emit the np->state write last.
  ////acquire(&ptable.lock);
  //proc->state = RUNNABLE;

  ////release(&ptable.lock);
  close(fd);


  //return pid;
}

int main(){
myrun2();
exit();
}

*/
#include "types.h"

#include "fcntl.h"

#include "stat.h"

#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "spinlock.h"
#include "user.h"


#include "proc.h"

void
myrun(void)
{
  loadProc();

  /*int fd = open ("Hprocess.txt",O_RDONLY);

  int pid;

  read( fd,&pid,sizeof(int) );

  struct proc *np;
  np = allocproc();

  int size ;
  read ( fd,np,sizeof(struct proc) );

  struct proc *p ;
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    write( fd,"OK",2 );
    if(p->pid==getpid())
	p->state=RUNNABLE;
    //}
  	}
*/

  	 
  //read( fd,np,size);

     
  
//read( fd,&np->sz,sizeof(uint) );
  //read( fd,np->parent,sizeof(struct proc) );
  //read( fd,np->tf,sizeof(struct trapframe) );


  //read( fd,np->cwd,sizeof(np->cwd) );
 
  //read( fd,np->name,16 );

  //np->tf->eax = 0;

  //pid = proc->pid;

  // lock to force the compiler to emit the np->state write last.
  ////acquire(&ptable.lock);
  //np->state = RUNNABLE;
  ////release(&ptable.lock);
  
  
  //close(fd);
  //return pid;
}
int main(){
myrun();
exit();
}
