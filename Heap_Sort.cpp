/*Implement Heap Sort using cpp*/
#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)
{
	int largest=i;
	int l=(i*2)+1;
	int r=(i*2)+2;
	
	if(arr[largest]<arr[l])
	{
		largest=l;	
	}
	if(arr[largest]<arr[r])
	{
		largest=r;
	}
	if(i!=largest)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,5,largest);
	}
}
void heap(int arr[],int n)
{
	for(int i=(n/2);i>=0;i--)
	{
		heapify(arr,5,i);
	}	
	for(int i=n-1;i>=0;i++)
	{
		swap(arr[i],arr[0]);
		heapify(arr,5,0);
	}
}
void swap(int& a,int& b)
{
	int temp=a;
	a=b;
	b=temp;
}

int main()
{
	int arr[5];	
	cout<<"\nEnter the array";
	for(int i=0;i<5;i++)
	{
		cin>>arr[i];
	}
	heap(arr,5);
	cout<<"\nArray is:";
	for(int i=0;i<5;i++)
	{
		cout<<arr[i];
	}
	return 0;
}
