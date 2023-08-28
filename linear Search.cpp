#include<stdio.h>
int linearSearch(int arr[],int size,int key)
{ for(int i=0;i<size;i++)
{ 
if(arr[i]==key)
 {return i;
  } 
}
return -1;
}
int main()
{ int arr[]={2,5,7,9,12,15};
int size=sizeof(arr)/sizeof(arr[0]);
int key=2;
int result=linearSearch( arr,size,key);
if(result!=-1)
{ printf("Element %d found at index %d\n",key,result+1);
}
else
printf("not found");
return 0;
}
