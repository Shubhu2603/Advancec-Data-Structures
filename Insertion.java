import java.util.*;
public class Insertion
{
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		int a[]=new int[30];
		System.out.println("Enter the size");
		int n=s.nextInt();
		System.out.println("Enter the elements");
		for(int i=0;i<n;i++)
		{
			a[i]=s.nextInt();
		}
		for(int i=1;i<n;i++)
		{
			int temp=a[i];
			int j=i-1;
			while(j>=0 && a[j]>temp)
			{
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=temp;
		}
		System.out.println("Sorted array is:");
		for(int i=0;i<n;i++)
		{
			System.out.print(a[i]+"\t");
		}
	
	}
}
