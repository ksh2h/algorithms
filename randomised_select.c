#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/*
worst case running time=O(n^2)
Expected value of running time = O(n).
*/

int randomised_partition(int *a,int p,int r){
    srand(time(NULL));
    int j=p,temp,i=(rand()%(r-p+1))+p;
    temp=a[i];
    a[i]=a[r];
    a[r]=temp;
    i=p-1;
    while(j<r){
        if(a[j]<=a[r]){
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        j++;
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

int randomised_select(int *a,int p,int r,int i){
    if(p==r)return a[p];
    int q=randomised_partition(a,p,r);
    if(i==q)return a[q];
    if(i<q)return randomised_select(a,p,q-1,i);
    else return randomised_select(a,q+1,r,i);
}

int main() {
    int i,n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&i);
    printf("%d\n",randomised_select(a,0,n-1,i-1));
    return 0;
}
