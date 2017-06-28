#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
//space complexity = O(n^2).


void matrixchainorder(int *p,int **m,int **s,int n){//worst case time complexity = O(n^3).
    int i,j,k,l,q;
    for(i=0;i<n;i++)m[i][i]=0;
    for(l=2;l<=n;l++){
        for(i=0;i<=n-l;i++){
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++){
                q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    return;
}

void print_optimal_parens(int **s,int i,int j){//worst case time complexity = O(n).
    if(i==j)printf("A%d",i+1);
    else {
        printf("(");
        print_optimal_parens(s,i,s[i][j]);
        print_optimal_parens(s,s[i][j]+1,j);
        printf(")");
    }
    return;
}



int main() {
    int n,i;
    scanf("%d",&n);
    int *p=(int *)malloc(sizeof(int)*(n+1));
    int **m=(int **)malloc(sizeof(int *)*n);
    int **s=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++){
        m[i]=(int *)malloc(n*sizeof(int));
        s[i]=(int *)malloc(sizeof(int)*n);
        scanf("%d",&p[i]);
    }
    scanf("%d",&p[n]);
    matrixchainorder(p,m,s,n);
    print_optimal_parens(s,0,n-1);
    printf("\nOptimal cost of multiplication : %d\n",m[0][n-1]);
    return 0;
}

