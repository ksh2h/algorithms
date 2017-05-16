#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/*
worst case time complexity = O(n^2) when array is sorted in reverse order
best case time complexity = O(n) when array is already sorted
average time complexity = O(n^2)
*/

void bubblesort(int *a,int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    return;
}

int main() {
    int i,n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    bubblesort(a,n);
    for(i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
