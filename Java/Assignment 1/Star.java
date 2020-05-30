import java.util.Scanner;
class Star	{
	public static void main(String[] args)	{
		int n;
		Scanner obj=new Scanner(System.in);
		System.out.println("Enter  a number");
		n=obj.nextInt();
		for(int i=0;i<2*n-1;i++)	{
			for(int j=0;j<2*n-1;j++)	{
				if(j==i || j==2*n-i-2)
					System.out.print("*");
				else
					System.out.print(" ");
				}
			System.out.println();
			}
		}
	}