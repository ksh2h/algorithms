#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>
/*
worst case time complexity =O(n+k)
when k=O(n) then T(n)=O(n);
counting sort is a stable sorting algorithm
*/

void countingsort(int *a,int *b,int n,int k){
    int i;
    int *c=(int *)calloc(k,sizeof(int));
    for(i=0;i<n;i++)c[a[i]]++;
    for(i=1;i<k;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--){
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    free(c);
    return;
}

int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    int *a=(int *)malloc(sizeof(int)*n);
    int *b=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    countingsort(a,b,n,k);
    for(i=0;i<n;i++)printf("%d\n",b[i]);
    return 0;
}
