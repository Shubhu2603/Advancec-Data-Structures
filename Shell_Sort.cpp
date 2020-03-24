/*Implement Shell Sort Using cpp*/
#include<iostream>
using namespace std;
int main()
{
	int a[10],n,i,j,temp,k;
	cout<<"Enter the number of elements";
	cin>>n;
	cout<<"Enter the elements";
	for(i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	for(i=n/2;i>0;i=i/2)
	{
		for(j=i;j<n;j++)
		{
			for(k=j-i;k>=0;k=k-i)
			{
				if(a[k]>a[k+i])
				{
					temp=a[k];
					a[k]=a[k+i];
					a[k+i]=temp;
				}
			}		
		}
	}
	cout<<"Array after sorting";
	for(i=0;i<n;i++)
	{
		cout<<a[i];	
	}
	return 0;
}
