import java.util.Scanner;
class dupstr	{
	public static void main(String args[])	{
		Scanner in = new Scanner(System.in);
		String s=in.nextLine();
		String s_lower = s.toLowerCase();
		System.out.println("String is converted to lowercase to detect duplicate characters : "+s_lower);
		int n=s.length()-1;
		int cnt=0;
		char[] c = s.toCharArray();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (c[i] == c[j]) {
					System.out.println(c[j]);
     					cnt++;
					break;
					}
				}
			}
		}
	}