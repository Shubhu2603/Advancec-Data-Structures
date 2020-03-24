/*Implement Shell sort using Java*/
import java.util.*;
public class Shell
{
	public static void main(String abcd[])
	{

		Scanner s=new Scanner(System.in);
		int[] a=new int[30];
		System.out.println("Enter the size of array");
		int n=s.nextInt();
		System.out.println("Enter the array elements");
		for(int i=0;i<n;i++)
		{
			a[i]=s.nextInt();
		}
		for(int i=n/2;i>0;i=i/2)
		{
			for(int j=i;j<n;j++)
			{
				for(int k=j-i;k>=0;k=k-i)
				{
					if(a[k]>a[k+i])
					{
						int temp=a[k];
						a[k]=a[k+i];
						a[k+i]=temp;
					}
				
				}				
			}
		}
		for(int i=0;i<n;i++)
		{
			System.out.print(a[i]+"\t");
		}
	}
}	
