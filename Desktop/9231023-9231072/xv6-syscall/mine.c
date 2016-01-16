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
myexit(void)
{
  saveProc();
  exit();

  //int fd;
  //fd = open ("Hprocess.txt",O_CREATE|O_WRONLY);

  //struct proc *p ;
  //for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    //write( fd,"OK",2 );
    //if(p->pid==getpid()){
	//int size = proc->killed;//getpid();//sizeof(proc);

  	//write(fd,&size,sizeof(int));
  	//write( fd,proc,size );
	
//	write(fd,&size,sizeof(int));
	
	

  /*write( fd,proc->pgdir,sizeof(proc->pgdir));
  write( fd,&proc->sz,sizeof(proc->sz) );
  write( fd,&proc->parent,sizeof(proc->parent) );
  write( fd,proc->tf,sizeof(proc->tf) );


  write( fd,proc->cwd,sizeof(proc->cwd) );
 
  write( fd,proc->name,sizeof(proc->name) );
  
*///size=getpid();


  /*int pid ;
  pid = fork();
  if(pid == 0){
  	write( fd,proc,sizeof(proc) );
	exit();
  }
  else {
	wait();
	exit();
  }*/
 
  //close(fd);

}

void
mine(void)
{ 
  write(1, "0",1);
  write(1, "1",1);
  write(1, "2",1);
  write(1, "3",1);
  write(1, "4",1);

  myexit();
  //exit();
  write(1, "5",1);


  write(1, "6",1);


  write(1, "7",1);


  write(1, "8",1);


  write(1, "9",1);


}

int
main(void)
{
  mine();
  exit();
}
