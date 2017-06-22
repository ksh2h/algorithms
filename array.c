#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
# define MAXSIZE 100
int n=0;

void insert1(int *a,int key){//worst case time complexity = O(1).
    if(n==MAXSIZE){
        printf("Array out of bounds\n");
        return;
    }
    a[n++]=key;
    return;
}

int search1(int *a,int key){//worst case time complexity = O(n).
    int i;
    for(i=0;i<n;i++)if(a[i]==key)return i;
    return -1;
}

void delete1(int *a,int key){//worst case time complexity = O(n).
    int i;
    i=search1(a,key);
    if(i==-1){
        printf("Error : key not found\n");
        return;
    }
    for(;i<n-1;i++)a[i]=a[i+1];
    n--;
    return;
}

int partition(int *a,int p,int r){//worst case time complexity = O(n).
    int i=p-1,j=p,temp;
    while(j<r){
        if(a[j]<=a[r]){
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
        j++;
    }
    temp=a[r];
    a[r]=a[i+1];
    a[i+1]=temp;
    return i+1;
}

void quicksort(int *a,int p,int r){//worst case time complexity = O(n^2).Average time complexity = O(n log n).
    if(p<r){
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
    return;
}



/*Should be improved by using binary search to find the location where to be inserted
  but still time complexity remains same.
*/
void insert2(int *a,int key){//worst case time complexity = O(n).
    if(n==MAXSIZE){
        printf("Array out of bounds\n");
        return;
    }
    int i=n-1;
    n++;
    while(i>=0&&a[i]>key){
            a[i+1]=a[i];
            i--;
    }
    a[i+1]=key;
    return;
}

int search2(int *a,int p,int r,int key){//worst case time complexity = O(log n).
    if(p<=r){
            int q=(p+r)/2;
            if(a[q]==key)return q;
            if(key<a[q])return search2(a,p,q-1,key);
            else return search2(a,q+1,r,key);
    }
    return -1;
}

void delete2(int *a,int key){//worst case time complexity = O(n).
    int i=search2(a,0,n-1,key);
    if(i==-1){
        printf("Error : key not found\n");
        return;
    }
    for(;i<n-1;i++)a[i]=a[i+1];
    n--;
    return;
}


int main() {
    int i,key,op;
    int *a=(int *)malloc(sizeof(int)*MAXSIZE);
    printf("Unsorted:\n");
    while(1){
        scanf("%d",&op);
        if(op==1||op==2||op==3)scanf("%d",&key);
        if(op==1)insert1(a,key);
        else if(op==2){
            op=search1(a,key);
            if(op==-1)printf("Not found\n");
            else printf("Found in position %d\n",op+1);
        }
        else if(op==3){
            delete1(a,key);
        }
        else break;
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)printf("%d ",a[i]);
    printf("\nsorted.\n");
    while(1){
        scanf("%d",&op);
        if(op==1||op==2||op==3)scanf("%d",&key);
        if(op==1)insert2(a,key);
        else if(op==2){
            op=search2(a,0,n-1,key);
            if(op==-1)printf("Not found\n");
            else printf("Found in position %d\n",op+1);
        }
        else if(op==3){
            delete2(a,key);
        }
        else if(op==4){
            for(i=0;i<n;i++)printf("%d ",a[i]);
            printf("\n");
        }
        else break;
    }
    return 0;
}
