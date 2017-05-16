#include <stdio.h>
#include <stdlib.h>

/*
worst case time complexity = O(log n) (found using recursion methods eg:recursion tree method,master method)
best case time complexity =O(1) when element being serched is in middle of sorted array
average time complexity =O(log n)
*/

int binarysearch(int *a,int p,int q,int k){
    printf("%d,%d\n",p,q);
    if(p<=q){
        int r= (p+q)/2;
        if(k==a[r]){printf("Key found:");return 1;}
        if(k<a[r])return binarysearch(a,p,r-1,k);
        if(k>a[r])return binarysearch(a,r+1,q,k);
    }
    printf("Key not found:");
    return 0;
}

int main()
{
    int a[]={1,2,3,5,6,7,9,12};
    printf("%d\n",binarysearch(a,0,7,12));
}
