import java.util.*;
import java.io.*;
 class Account	{
	private String cust_name;
	protected int acc_num;
	protected String acc_type;
	protected double balance;

	void openAccount(String cust_name,int acc_name, String acc_type,double balance)	{
		this.cust_name=cust_name;
		this.acc_num=acc_num;
		this.acc_type=acc_type;
		this.balance=balance;
		System.out.println("Account Created!");
		}
	
	Account()	{
		cust_name=" ";
		acc_num=-1;
		acc_type=" ";
		balance=0.0;
		}
	}
	
class Sav_acct extends Account	{
	double rate=0.045;
	void deposit(double amount)	{
		balance+=amount;
		System.out.println("New balance Rs"+balance);
		}
	void withdraw(double amount)	{
		if(balance<amount)	{
			System.out.println("Not enough balance");
			return;
			}
		balance-=amount;
		System.out.println("New balance Rs"+balance);
		}
	double getBalance()	{
		return balance;
		}
	double yearly_interest()	{
		double interest = balance*(1+rate)-balance;
		balance+=interest;
		return interest;
		}
	}
	
class Cur_acct extends Sav_acct	{
	double min_bal;
	
	void set_min_bal()	{
		min_bal=1000.00;
	}
	void penalty()	{
		if(balance<min_bal)
			balance-=100;
		System.out.println("Balance after penalty is Rs"+balance);
		}
	}

	
class Bank	{ 
	public static void main(String arg[])
	{
		Scanner in=new Scanner(System.in);
		
		//create initial accounts
		System.out.print("How many Customers do you want to Input : ");
		int n=in.nextInt();
		Cur_acct  C[]=new Cur_acct[n+1];
		for(int i=0;i<C.length;i++)
		{   
			C[i]=new Cur_acct();
		
		}
		
		//run loop until menu 5 is not pressed
		int ch;
		do
		{
			System.out.println("Main Menu\n1.Open Account\n2.Check Balance\n3.Deposit\n4.Withdrawal\n5.Calculate Interest\n6.Penalty\n7.Exit");
			System.out.println("Ur Choice :");
			ch=in.nextInt();
			switch(ch)
			{ 
				case 1:
					System.out.println("Enter customer number");
					int c=in.nextInt();
					System.out.println("Enter account number");
					int k=in.nextInt();
					System.out.println("Enter name");
					String name=in.nextLine();
					System.out.println("Enter account type");
					String t=in.nextLine();
					System.out.println("Enter starting balance");
					double bal=in.nextDouble();
					C[c].openAccount(name, k, t, bal);
					break;	
					
				case 2:
					System.out.println("Enter customer number");
					c=in.nextInt();
						System.out.println("Your Balance is "+C[c].getBalance());
					break;

				case 3:
					System.out.println("Enter customer number");
					c=in.nextInt();
					System.out.println("Enter amount");
					int amount=in.nextInt();
					C[c].deposit(amount);
					break;

				case 4:
					System.out.println("Enter customer number");
					c=in.nextInt();
					System.out.println("Enter amount");
					amount=in.nextInt();
					C[c].withdraw(amount);
					break;

				case 5:
					System.out.println("Enter customer number");
					c=in.nextInt();
					System.out.println("Interest for you is"+C[c].yearly_interest());
					break;

				case 6:
					System.out.println("Enter customer number");
					c=in.nextInt();
					C[c].penalty();
					break;

				case 7: 
					System.out.println("Exiting");
					break;
				
				default:
					System.out.println("Enter a valid input");
					break;
			}
		}
		while(ch!=7);
	}
}
			
	