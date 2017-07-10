#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/*DP - (Bottom up method)
 *Worst case time complexity = O(n^3).
 */
int dp_tabulation(int *s,int *f,int n){
    int i,j,k,l,temp;
    int **c=(int **)malloc(sizeof(int *)*(n+2));
    int **w=(int **)malloc(sizeof(int *)*(n+2));
    for(i=0;i<=n+1;i++){
        c[i]=(int *)malloc(sizeof(int)*(n+2));
        w[i]=(int *)malloc(sizeof(int)*(n+2));
        for(j=0;j<=i+1&&j<=n+1;j++)c[i][j]=0;
    }
    for(l=3;l<=n+2;l++){
        for(i=0;i<=n-l+2;i++){
           j=i+l-1;
           c[i][j]=0;
           for(k=i+1;k<j;k++){
                if(s[k]>=f[i]&&f[k]<s[j]){
                    temp=c[i][k]+c[k][j]+1;
                    if(temp>c[i][j]){
                        c[i][j]=temp;
                        w[i][j]=k;
                    }
                }
           }
        }
    }
    return c[0][n+1];
}

/*Greedy - (Top down fashion)
 *Worst case complexity = O(n).
 */
int greedy(int *s,int *f,int i,int j){
    if(i>=j-1)return 0;
    int k;
    for(k=i+1;k<j;k++){
        if(s[k]>=f[i]&&f[k]<s[j])break;
    }
    if(k==j)return 0;
    return 1+greedy(s,f,k,j);
}

int main() {
    int n,i;
    scanf("%d",&n);
    int *s=(int *)malloc(sizeof(int)*(n+2));
    int *f=(int *)malloc(sizeof(int)*(n+1));
    for(i=1;i<=n;i++)scanf("%d%d",&s[i],&f[i]);
    f[0]=0;
    s[n+1]=INT_MAX;
    printf("Size of maximum subset of mutually compatible activities from S:%d\n",dp_tabulation(s,f,n));
    printf("Size of maximum subset of mutually compatible activities from S:%d\n",greedy(s,f,0,n+1));
    return 0;
}
