import java.util.Scanner;
public class banker
{
	private int need[][],avl[][],max[][],allocate[][],np,nr;
	
	private void input()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter the no. of process & resources :");
		np=sc.nextInt();
		nr=sc.nextInt();
		need=new int[np][nr];
		avl=new int[1][nr];
		allocate=new int[np][nr];
		max=new int[np][nr];
		
		
		System.out.println("enter the allocation matrix :");
		for(int i=0;i<np;i++)
		{
			for(int j=0;j<nr;j++)
			{
				allocate[i][j]=sc.nextInt();
			}
		}
		System.out.println("enter the max matrix :");
		for(int i=0;i<np;i++)
		{
			for(int j=0;j<nr;j++)
			{
				max[i][j]=sc.nextInt();
			}
		}
		System.out.println("enter the available matrix :");
		for(int j=0;j<nr;j++)
		{
			avl[0][j]=sc.nextInt();
		}
	
	}
	private int[][] calc_need()
	{
		for(int i=0;i<np;i++)
		{
			for(int j=0;j<nr;j++)
			{
				need[i][j]=max[i][j]-allocate[i][j];	
				
				
			}
			
		}
		return need;
	}
	
	private boolean check(int i)
	{
		for(int j=0	;j<nr;j++)
		{
			if(avl[0][j]<need[i][j])
			{
				return false;
				
			}
			
		}
			return true;
	}
	public void isSafe()
	{
		input();
		calc_need();
		boolean done[]=new boolean[np];
		int j=0;
		
		
		while(j<np)
		{
			boolean allocated=false;
			for(int i=0;i<np;i++)
			{
				if(!done[i]&&check(i))
				{
					for(int k=0;k<nr;k++)
					{
						avl[0][k]=avl[0][k]-need[i][k]+max[i][k];
						System.out.println("allocated process are :"+i);
						allocated=done[i]=true;
						j++;
					}
					
				}
					
			}
			if(!allocated)
			{
				break;
			}
		}
		if(j==np)
		{
			System.out.println("\n safely allocated");
		}
		else
		{
			System.out.println("\n not allocated");
		}
	}
	public static void main(String[] args)
	{
		new banker().isSafe();
	}
		
		
}