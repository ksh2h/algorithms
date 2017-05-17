#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
int heapsize;

void heapify(int *a,int i){//time complexity = O(log n),,n= no of nodes in sub heap with root at index i
    int l=2*i+1,r=2*i+2,max=i,temp;
    if(l<heapsize&&a[l]>a[i])max=l;
    if(r<heapsize&&a[r]>a[max])max=r;
    if(max!=i){
        temp=a[i];
        a[i]=a[max];
        a[max]=temp;
        heapify(a,max);
    }
    return;
}

void buildheap(int *a){//time complexity = O(n)
    int i;
    for(i=heapsize/2-1;i>=0;i--)heapify(a,i);
    return;
}

void heapsort(int *a){//worst case time complexity = O(n*logn)
    int i,temp;
    buildheap(a);
    for(i=heapsize-1;i>0;i--){
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapsize--;
        heapify(a,0);
    }
    return;
}

int main() {
    int i,n;
    scanf("%d",&n);
    heapsize=n;
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    heapsort(a);
    for(i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
