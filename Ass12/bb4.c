#include<stdio.h>
include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
int main()
{
	int rc,nc;
	int ch;
	while(1)
	{
		system("ps axl");
		printf("\n current nice value can be checked from above table")
		printf("\n current priority of the process %d is %d :",getpid(),getpriority(PRIO_PROCESS,0));
		printf("\n enter the new nice value between -20 to 20:");
		scanf("%d",&nc);
		rn=setpriority(PRIO_PROCESS,0,nc);
		
		
		if(0!=rc)
		{
			perror=("setpriority");
			

		}
		sleep(2);
		
		printf("\n modified nice value of the process %d is %d",getpid(),getpriority(PRIO_PROCESS,0));
		printf("\n do you want to continue :");
		scanf("%d",&ch);
		
		
		if(ch==0)
		{
			exit(0);
		}
	}
	return 0;
}