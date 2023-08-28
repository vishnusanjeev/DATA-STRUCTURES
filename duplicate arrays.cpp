#include<stdio.h>
int main()
{ 
   int arr[100],i,j,n;
   printf("enter the no.of elements in a array:\n");
   scanf("%d",&n);
   printf("enter the elements:\n");
   for(i=0;i<n;i++)
   {
   	scanf("%d",&arr[i]);
   }
   for(i=0;i<n;i++)
   {
   	for(j=i+1;j<n;j++)
   	{ 
   	  if(arr[i]==arr[j])
		 printf("duplicate elements:%d\n",arr[j]);	
	}
   }
   return 0;   
}
