import java.io.*;
class ltor
{
	public static void main(String arg[])throws IOException
	{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			int i;
			String a[][]=
			{
				{"","START","101",""},
				{"","MOVER","BREG","ONE"},
				{"","MOVEM","BREG","TERM"},
				{"AGAIN","MULT","BREG","TERM"},
				{"","MOVER","CREG","TERM"},
				{"","ADD","CREG","N"},
				{"","MOVEM","CREG","RESULT"},
				{"N","DS","2",""},
				{"RESULT","DS","2",""},
				{"ONE","DC","1",""},
				{"TERM","DS","1",""},
				{"END","","",""}
			};
			int lc=Integer.parseInt(a[0][2]);
			String st[][]=new String[5][2];
			int cnt=0,l;
			for(i=0;i<11;i++)
			{
					if(a[i][0]!="")
					{
							st[cnt][0]=a[i][0];
							st[cnt][1]=Integer.toString(lc);
							cnt++;
							if(a[i][1]=="DS")
							{
									l=Integer.parseInt(a[i][2]);
									lc=lc+l;
							}
							else
							{
									lc++;
							}
					}
					else
					{
							lc++;
					}
			}
			System.out.println("\nsymbol\t\tvalues\n");
			for(i=0;i<5;i++)
			{
				System.out.println(st[i][0]+"\t\t"+st[i][1]);
			}
	}
}