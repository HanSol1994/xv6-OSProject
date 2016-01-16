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

struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;

int nextpid = 1;
extern void forkret(void);
extern void trapret(void);

struct run {
  struct run *next;
};

struct {
  struct spinlock lock;
  int use_lock;
  struct run *freelist;
} kmem;




char*
kalloc(void)
{
  struct run *r;

  //if(kmem.use_lock)
    //acquire(&kmem.lock);
  r = kmem.freelist;
  if(r)
    kmem.freelist = r->next;
  //if(kmem.use_lock)
    //release(&kmem.lock);
  return (char*)r;
}



static struct proc*
allocproc(void)
{
  struct proc *p;
  char *sp;

  //acquire(&ptable.lock);
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++)
    if(p->state == UNUSED)
      goto found;
  //release(&ptable.lock);
  return 0;

found:
  p->state = EMBRYO;
  p->pid = nextpid++;
  //release(&ptable.lock);

  // Allocate kernel stack.
  if((p->kstack = kalloc()) == 0){
    p->state = UNUSED;
    return 0;
  }
  sp = p->kstack + KSTACKSIZE;
  
  // Leave room for trap frame.
  sp -= sizeof *p->tf;
  p->tf = (struct trapframe*)sp;
  
  // Set up new context to start executing at forkret,
  // which returns to trapret.
  
  sp -= 4;
  ///*(uint*)sp = (uint)trapret;

  sp -= sizeof *p->context;
  p->context = (struct context*)sp;
  memset(p->context, 0, sizeof *p->context);
  ///p->context->eip = (uint)forkret;

  return p;
}



void
myrun2(void)
{

  int fd = open ("Hprocess.txt",O_RDONLY);

  /*int pid;

  read( fd,&pid,sizeof(int) );*/

  struct proc tmp;
  struct proc *np;
  np = allocproc();
/*struct proc *p;



  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++)
    if(p->pid == pid){
      p->state=RUNNABLE;
      p->killed = 0 ;
}*/
	 
  read( fd,&tmp,sizeof(struct proc));
write(1,tmp.name,16);
  //read( fd,&np->sz,sizeof(uint) );
  //read( fd,np->parent,sizeof(struct proc) );
  //read( fd,np->tf,sizeof(struct trapframe) );


  //read( fd,np->cwd,sizeof(np->cwd) );
 
  //read( fd,np->name,16 );

  //np->tf->eax = 0;

  //pid = proc->pid;

  // lock to force the compiler to emit the np->state write last.
  ////acquire(&ptable.lock);
  np->state = RUNNABLE;
  ////release(&ptable.lock);
  
  
  close(fd);
  //return pid;
}
int main(){
myrun2();
exit();
}
