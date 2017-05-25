#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/*
For quicksort:
    Expected value of running time = O(n*log n)
  It is an in-place sorting algorithm unlike mergesort but follows divide and conquer paradigm
*/

int partition_rand(int *a,int p,int r){//time complexity = O(n)
    int i,j,temp;
    srand( time(NULL));
    i=(rand()%(r-p+1))+p;
    temp=a[i];
    a[i]=a[r];
    a[r]=temp;
    for(i=p-1,j=p;j<r;j++){
        if(a[j]<=a[r]){
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

void quicksort_rand(int *a,int p,int r){
    if(p<r){
        int q=partition_rand(a,p,r);
        quicksort_rand(a,p,q-1);
        quicksort_rand(a,q+1,r);
    }
    return;
}

int main() {
    int i,n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    quicksort_rand(a,0,n-1);
    for(i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
