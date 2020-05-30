import java.util.Scanner;
import java.io.InputStream;
class square	{
	public static void main(String args[])	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int c = 0;
		for(int i = 1;i<n/2; i++)	{
			if(i*i==n)	{
				c++;
				break;
				}
			}
		if(c == 1 || n==1)
			System.out.println("Square");
		else	
			System.out.println("Not a Square");
		}
	}