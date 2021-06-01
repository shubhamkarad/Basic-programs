#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid;
	pid=fork();
	
	if(pid==0)
	{
		printf("\n after fork ");
		
		printf("\n the new child id created by fork system call%d \n :",getpid());
		
	}
	else
	{
		printf("\n before fork :");
		
		printf("\n parent procees id  is %d :",getppid());
		printf("\n parent executed successfully");
	}
		return 0;
		
}