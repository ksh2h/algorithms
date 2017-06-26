#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

void fastest_way(int *a1,int *a2,int *t1,int *t2,int *f1,int *f2,int *l1,int *l2,int e1,int e2,int x1,int x2,int *fp,int *lp,int n){

    f1[0]=e1+a1[0];//worst case time complexity=O(n).
    f2[0]=e2+a2[0];
    int j;
    for(j=1;j<n;j++){
        if(f1[j-1]<=f2[j-1]+t2[j-1]){
                f1[j]=f1[j-1]+a1[j];
                l1[j]=1;
        }
        else {
            f1[j]=f2[j-1]+t2[j-1]+a1[j];
            l1[j]=2;
        }
        if(f2[j-1]<=f1[j-1]+t1[j-1]){
            f2[j]=f2[j-1]+a2[j];
            l2[j]=2;
        }
        else {
            f2[j]=f1[j-1]+t1[j-1]+a2[j];
            l2[j]=1;
        }
    }
    if(f1[n-1]+x1<=f2[n-1]+x2){
        *fp=f1[n-1]+x1;
        *lp=1;
    }
    else {
        *lp=2;
        *fp=f2[n-1]+x2;
    }
    return;
}

void printstations(int *l1,int *l2,int i,int j){//worst case time complexity=O(n).s
    if(j>0){
        if(i==1)printstations(l1,l2,l1[j],j-1);
        else printstations(l1,l2,l2[j],j-1);
        printf("Line : %d , Station : %d\n",i,j+1);
    }
    else printf("Line : %d , Station : %d\n",i,j+1);
    return;
}


int main() {
    int i,n,e1,e2,x1,x2,fans,lans;
    scanf("%d%d%d%d%d",&n,&e1,&e2,&x1,&x2);
    int *a1=(int *)malloc(sizeof(int)*(n));
    int *a2=(int *)malloc(sizeof(int)*(n));
    int *t1=(int *)malloc(sizeof(int)*(n-1));
    int *t2=(int *)malloc(sizeof(int)*(n-1));
    int *f1=(int *)malloc(sizeof(int)*(n));
    int *f2=(int *)malloc(sizeof(int)*(n));
    int *l1=(int *)malloc(sizeof(int)*(n));
    int *l2=(int *)malloc(sizeof(int)*(n));
    for(i=0;i<n;i++)scanf("%d%d",&a1[i],&a2[i]);
    for(i=0;i<n-1;i++)scanf("%d%d",&t1[i],&t2[i]);
    fastest_way(a1,a2,t1,t2,f1,f2,l1,l2,e1,e2,x1,x2,&fans,&lans,n);
    printstations(l1,l2,lans,n-1);
    printf("Total time taken in the fastest case : %d\n",fans);
    return 0;
}
















