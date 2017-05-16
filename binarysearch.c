#include <stdio.h>
#include <stdlib.h>

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
