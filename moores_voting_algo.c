#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*Returns the index of majority element (which occurs more than n/2 times) in an array if exists.
 *else returns -1;
 *Worst case time complexity = O(n).
*/
int majority(int *a,int n){
    int i,m=0,count=1;
    for(i=1;i<n;i++){
        if(a[m]==a[i])count++;
        else count--;
        if(!count){
            m=i;
            count=1;
        }
    }
    for(i=0,count=0;i<n;i++)if(a[m]==a[i])count++;
    if(count>n/2)return m;
    return -1;
}


int main(){
    int n,i;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    i=majority(a,n);
    if(i==-1)printf("No majority element\n");
    else printf("Majority element : %d\n",a[i]);
    return 0;
}
