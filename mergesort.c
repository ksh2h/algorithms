#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/*
worst case time complexity = O(n*log n)
best case time complexity = O(n*log n)
average time complexity = O(n*log n)
*/

void merge(int *a,int p,int q,int r){
    int m=q-p+1,n=r-q,i,j,k;
    int *L=(int *)malloc(sizeof(int)*(m+1));
    int *R=(int *)malloc(sizeof(int)*(n+1));
    for(i=0;i<m;i++)L[i]=a[i+p];
    for(i=0;i<n;i++)R[i]=a[i+q+1];
    L[m]=R[n]=INT_MAX;
    for(i=0,j=0,k=p;k<=r;k++){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else {
            a[k]=R[j];
            j++;
        }
    }
    return;
}

void mergesort(int *a,int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
    return;
}

int main() {
    int i,n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
