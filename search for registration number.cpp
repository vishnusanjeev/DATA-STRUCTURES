#include<stdio.h>
int main()
{
	int n,a[100],i,regno;
	printf("limit if register numbers:\n ");
	scanf("%d",&n);
	printf("enter the registration numbers:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter the register number to be searched:\n");
	scanf("%d",&regno);
	for(i=0;i<n;i++)
	{
		if(a[i]==regno)
	{
		printf("found");
		return 0;
    }
    }
	printf("not found");
	return 0;	
}
