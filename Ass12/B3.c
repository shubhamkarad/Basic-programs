
/********************************
NAME :-
CLASS:-
ROll no:-
BATCH:-
ASSIGNMENT NO.:-3(group B)
*********************************/
/*# Aim: C/C++ Program to Parent creating the child process by use of fork.
________________________________________________________________*/

#include<stdio.h>
#include<unistd.h>
int main()
{
int pid;

pid=fork();

if(pid==0)
{
printf("\n After fork");
printf("\n The new child process created by fork system call %d\n", getpid());
}
else {
printf("\n Befor fork");

printf("\n The parent process id is :- %d ", getppid());
printf("\n parent excuted successfully\n");

}

return 0;

}


/***OUTPUT******
student@jit:~/OSAprogram$ gcc B3.c
student@jit:~/OSAprogram$ ./a.out

 Befor fork
 The parent process id is :- 2019 

 parent excuted successfully
 After fork
 The new child process created by fork system call 2789
*/
