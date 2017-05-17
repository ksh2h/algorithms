#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
int heapsize=0;
#define maxheapsize 100

void heapifyup(int *a,int i){//time complexity =O(log n)
    int temp;
    while(i>0){
        if(a[i]<=a[(i-1)/2])break;
        temp=a[i];
        a[i]=a[(i-1)/2];
        a[(i-1)/2]=temp;
        i=(i-1)/2;
    }
    return;
}

void heapifydown(int *a,int i){//time complexity = O(log n),,n= no of nodes in sub heap with root at index i
    int l=2*i+1,r=2*i+2,max=i,temp;
    if(l<heapsize&&a[l]>a[i])max=l;
    if(r<heapsize&&a[r]>a[max])max=r;
    if(max!=i){
        temp=a[i];
        a[i]=a[max];
        a[max]=temp;
        heapifydown(a,max);
    }
    return;
}

void add(int *a,int k){//time complexity=O(log n)
    if(heapsize>=maxheapsize){
        printf("Out of limit\n");
        return;
    }
    a[heapsize++]=k;
    heapifyup(a,heapsize-1);
    return;
}

void increasekey(int *a,int i,int k){//time complexity=O(log n)
    if(k<a[i]){
        printf("Error:New value lesser than previous value\n");
        return;
    }
    a[i]=k;
    heapifyup(a,i);
    return;
}

void decreasekey(int *a,int i,int k){//time complexity = O(log n)
    if(k>a[i]){
        printf("Error:New value greater than previous value\n");
        return;
    }
    a[i]=k;
    heapifydown(a,i);
    return;
}

void extractmax(int *a){//time complexity =O(log n),,n= no of nodes in heap
    if(heapsize<1){
        printf("Heap is empty\n");
        return;
    }
    int temp=a[0];
    a[0]=a[--heapsize];
    heapifydown(a,0);
    return;
}

void delete(int *a,int i){//time complexity = O(log n),,n=no of nodes in heap
    if(i==-1)return;
    int temp=a[i];
    a[i]=a[--heapsize];
    if(a[i]>temp)heapifyup(a,i);
    else heapifydown(a,i);
    return;
}

int search(int *a,int i,int k){
    if(i>=heapsize||k>a[i])return -1;
    if(k==a[i])return i;
    int l=search(a,2*i+1,k),r=search(a,2*i+2,k);
    if(l==-1)return r;
    if(r==-1)return l;
    return l;
}

int main() {
    int t,i,k,j;
    scanf("%d",&t);
    int *a=(int *)malloc(sizeof(int)*maxheapsize);
    while(t--){
        scanf("%d",&i);
        if(i!=3)scanf("%d",&k);
        if(i==5||i==6)scanf("%d",&j);
        if(i==1)add(a,k);
        if(i==2){
            j=search(a,0,k);
            if(j==-1)printf("k not found\n");
            delete(a,j);
        }
        if(i==3)extractmax(a);
        if(i==4){
                j=search(a,0,k);
                if(j==-1)printf("k not found\n");
                else printf("%d\n",j);
        }
        if(i==5){
            decreasekey(a,j,k);
        }
        if(i==6)increasekey(a,j,k);
        for(j=0;j<heapsize;j++)printf("%d ",a[j]);
        printf("\n");
    }
    return 0;
}
