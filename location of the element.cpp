#include<stdio.h>
int main()
{
	int arr[100],i,size,element;
	printf("enter the size of the array:\n");
	scanf("%d",&size);
	printf("enter the elements of the array:\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the element to be searched:\n");
	scanf("%d",&element);
	for(i=0;i<size;i++)
	{ 
	if(arr[i]==element)
	{
		printf("%d is found at %d",element,i+1);
		return 0;
	}
	}
	printf("element not found");
	return 0;
}
