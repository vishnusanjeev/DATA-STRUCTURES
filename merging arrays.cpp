#include<stdio.h>
int main()
{
	int i,k,arr1[100],arr2[100],merge[200],size1,size2;
	printf("enter the size of the first array:\n");
	scanf("%d",&size1);
	printf("enter the elements of the first array:\n");
	for(i=0;i<size1;i++)
	 {
	   scanf("%d",&arr1[i]);
	   merge[i]=arr1[i];
     }
     k=i;
    printf("enter the size of the second array:\n");
	scanf("%d",&size2);
	printf("enter the elements of the second array:\n");
	for(i=0;i<size2;i++)
	{
	  scanf("%d",&arr2[i]);
	  merge[k]=arr2[i];
	  k++;
    }
    printf("merged array:\n");
    for(i=0;i<k;i++)
    printf("%d",merge[i]);
    return 0;
		
}
