package chiraag;
import java.util.*;

public class Shit
{
	double MINDIFF=2.25e-308;
	public void square (int a)
	{
		int b;
		b=a*a;
		System.out.println("Squareroot:"+b);
	}
	public double sin (double deg)
	{
		 
   		 while (deg >= 360) deg = deg - 360;
    		while (deg < 0) deg = deg + 360;
   		 if (deg > 180) {
       			 deg = deg - 180;
     			 }
   		 double ret = (double)(4*deg*(180-deg))/(40500-(deg*(180-deg)));
    		return ret;
	}
	
	 public double sqroot(double square)
	{
    		double root=square/3, last, diff=1;
    		if (square <= 0) return 0;
    		do {
       		 last = root;
        		root = (root + square / root) / 2;
        		diff = root - last;
    		} while (diff > MINDIFF || diff < -MINDIFF);
    		return root;
	}
	public double cos(float x){
	double b=90-x;	
	b=sin(b);
	return b;
	}
	public double tan(float x){	
	double b=sin(x)/cos(x);
		return b;
	}

}
