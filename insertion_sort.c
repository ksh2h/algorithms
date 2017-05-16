#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*
worst case time complexity =O(n^2) when array is sorted in reverse order
best case time complexity =O(n) when array is already sorted
average time complexity =O(n^2)
*/

void insertion_sort(int *a,int n){
	int i,j,key;
	for(i=1;i<n;i++){
	   key=a[i];
	   for(j=i-1;j>=0&&a[j]>key;j--){
	      a[j+1]=a[j];
	   }
	   a[j+1]=key;
	}
return;
}

int main(){
	int i,n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	insertion_sort(a,n);
	for(i=0;i<n;i++)printf("%d ",a[i]);
return 0;
}
