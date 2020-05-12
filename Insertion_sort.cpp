#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n) {
	for(int i=1;i<n;i++)	{
		int e = a[i];
		int j = i-1;
		while(j>=0 && e<a[j])	{
			a[j+1] = a[j];
			j-=1;
		}
		a[j+1] = e;
	}
}
int main()	{
	int n, a[100];
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	cout<<"Unsorted array"<<endl;
	for(int i=0;i<n;i++)	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	insertion_sort(a, n);
	cout<<"Sorted Array"<<endl;
	for(int i=0;i<n;i++)	{
		cout<<a[i]<<" ";
	}
}
