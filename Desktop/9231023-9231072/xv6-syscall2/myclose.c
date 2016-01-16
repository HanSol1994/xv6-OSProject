#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "spinlock.h"

struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;

static struct proc *initproc;

int nextpid = 1;
extern void forkret(void);
extern void trapret(void);

void
myexit(void)
{
  struct proc *p;
  int fd;
  int fd = open ("Hprocess.txt",O_OWRNLY|O_CREATE);


  write( fd,&p->sz,sizeof(np->sz) );////////////////////////////////
  write( fd,&p->parent,sizeof(np->parent) );////////////////////////
  write( fd,&p->tf,sizeof(np->tf) );////////////////////////////////

//  np->sz = proc->sz;
  //np->parent = proc;
  //*np->tf = *proc->tf;



  //for(i = 0; i < NOFILE; i++)
    //if(proc->ofile[i])
      //np->ofile[i] = filedup(proc->ofile[i]);

  //np->cwd = idup(proc->cwd);
    write( fd,&p->cdw,sizeof(p->cwd) );////////////////////////////	
 
  //safestrcpy(np->name, proc->name, sizeof(proc->name));
    write( fd,&p->name,sizeof(p->name) );//////////////////////////
 
  close(fd);

}

// Wait for a child process to exit and return its pid.
// Return -1 if this process has no children.

int main(){
myexit();
exit();
}
