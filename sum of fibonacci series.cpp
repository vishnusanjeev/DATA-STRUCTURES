#include<stdio.h>
int main()
{
      int limit,first=0,second=1,next,sum=1;
      printf("enter the limit:\n");
      scanf("%d",&limit);
      printf("fibonacci series up to %d:\n",limit);
      printf("%d\n",first);
      printf("%d\n",second);
      for(int i=2;i<limit;i++)
      {
      	next=first+second;
      	printf("%d\n",next);
      	first=second;
      	second=next;
      	sum+=next;
	  }
      
	printf("sum of fibonacci series:%d",sum);
	return 0;
}
