#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



/*
 *Memoization method.
 *Worst case time complexity = O(n^2).
 */
int lis(int *a,int *arr,int *b,int i){
    if(arr[i]==-1){
            int j;
            arr[i]=1;
            for(j=0;j<i;j++){
                if(a[i]>a[j]&&1+lis(a,arr,b,j)>arr[i]){
                        arr[i]=1+arr[j];
                        b[i]=j;
                }
            }
    }
    return arr[i];
}

/*Worst case time complexity = O(n).
 */
void printans(int *a,int *b,int i){
    if(i>=0){
        printans(a,b,b[i]);
        printf("%d ",a[i]);
    }
    return;
}



/*
 *Tabulation method.
 *Worst case time complexity = O(n^2).
 */
int lis_t(int *a,int n){
    int *arr=(int *)malloc(sizeof(int )*(n));
    int i,j,max=0;
    for(i=0;i<n;i++)arr[i]=1;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[i]>a[j]&&arr[j]+1>arr[i])arr[i]=arr[j]+1;
        }
    }
    for(i=0;i<n;i++){
            if(arr[i]>max)max=arr[i];
    }
    free(arr);
    return max;
}



int main() {
    int i,max=0,n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    int *b=(int *)malloc(sizeof(int)*n);
    int *arr=(int *)malloc((n)*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        arr[i]=b[i]=-1;
    }
    lis(a,arr,b,n-1);
    for(i=0;i<n;i++)if(max<arr[i])max=arr[i];
    printf("The length of longest increasing subsequence is : \nMemoization : %d\nTabulation : %d\n",max,lis_t(a,n));
    printf("The longest increasing subsequence of X,Y is : ");
    for(i=0;i<n;i++){
        if(max==arr[i]){
                printans(a,b,i);
                break;
        }
    }
    printf("\n");
    return 0;
}
