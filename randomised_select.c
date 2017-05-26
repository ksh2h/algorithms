#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void minmax(int *a,int n,int *p,int *q){
    int i;
    if(n==1){
        *p=*q=a[0];
        return;
    }
    if(n%2){
            *p=a[0];
            *q=a[0];
            i=1;
    }
    else {
        if(a[0]<a[1]){
            *p=a[0];
            *q=a[1];
        }
        else {
            *p=a[1];
            *q=a[0];
        }
        i=2;
    }
    for(;i<n-1;i+=2){
        if(a[i]<a[i+1]){
            if(a[i]<*p)*p=a[i];
            if(a[i+1]>*q)*q=a[i+1];
        }
        else {
            if(a[i]>*q)*q=a[i];
            if(a[i+1]<*p)*p=a[i+1];
        }
    }
    return;
}

int randomised_partition(int *a,int p,int r){//worst case running time=O(n^2)
    srand(time(NULL));//Expected value of running time = O(n)
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
    int i,n,min,max;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d",&i);
    printf("%d\n",randomised_select(a,0,n-1,i-1));
    minmax(a,n,&min,&max);
    printf("%d %d\n",min,max);
    return 0;
}
