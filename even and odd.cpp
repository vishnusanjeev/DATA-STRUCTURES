#include<stdio.h>
int main()
{
	int arr[100],i,even,odd,size;
	printf("enter the size of the array:\n");
	scanf("%d",&size);
	printf("enter the elements of the array:\n ");
	for(i=0;i<size;i++)
	{
		scanf("%d\n",&arr[i]);
    }
		printf("even numbers in the array:\n");
		for(i=0;i<size;i++)
		{
			if(arr[i]%2==0)
			printf("%d\n",arr[i]);
		}
		printf("odd numbers in the array:\n");
		for(i=0;i<size;i++)
		{
			if(arr[i]%2!=0)
			printf("%d\n",arr[i]);
		}
		return 0;
		
}
