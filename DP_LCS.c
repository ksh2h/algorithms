#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



/*
 *Memoization method.
 *Worst case time complexity = O(m*n).
 */
int lcs(char *x,char *y,int **b,int **c,int i,int j){
    if(c[i][j]==-1){
        if(x[i-1]==y[j-1]){
            //printf("i:%d,j:%d,z[%d]=1\n",i,j,i);
            b[i][j]=1;
            c[i][j]=1+lcs(x,y,b,c,i-1,j-1);
        }
        else if(lcs(x,y,b,c,i-1,j)>=lcs(x,y,b,c,i,j-1)){
            c[i][j]=c[i-1][j];
            b[i][j]=2;
        }
        else {
            c[i][j]=c[i][j-1];
            b[i][j]=3;
        }
    }
    return c[i][j];
}

/*Worst case time complexity = O(m+n).
 */
void printans(char *x,int **b,int i,int j){
    if(i<1||j<1)return;
    if(b[i][j]==1){
        printans(x,b,i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]==2)printans(x,b,i-1,j);
    else printans(x,b,i,j-1);
    return;
}



/*
 *Tabulation method.
 *Worst case time complexity = O(m*n).
 */
int lcs_t(char *x,char *y,int m,int n){
    int **c=(int **)malloc(sizeof(int *)*(m+1));
    int i,j;
    for(i=0;i<=m;i++){
        c[i]=(int *)malloc(sizeof(int)*(n+1));
        if(!i){
            for(j=0;j<=n;j++)c[i][j]=0;
        }
        c[i][0]=0;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(x[i-1]==y[j-1])c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>=c[i][j-1])c[i][j]=c[i-1][j];
            else c[i][j]=c[i][j-1];
        }
    }
    return c[m][n];
}



int main() {
    int i,j,m,n;
    char *x=(char *)malloc(sizeof(char)*100);
    char *y=(char *)malloc(sizeof(char)*100);
    scanf("%s%s",x,y);
    m=strlen(x);
    n=strlen(y);
    int **b=(int **)malloc((m+1)*sizeof(int));
    int **c=(int **)malloc(sizeof(int *)*(m+1));
    for(i=0;i<=m;i++){
        c[i]=(int *)malloc(sizeof(int)*(n+1));
        b[i]=(int *)malloc(sizeof(int)*(n+1));
        for(j=0;j<=n;j++){
            if(!i||!j)c[i][j]=0;
            else c[i][j]=-1;
        }
    }
    printf("The length of longest common subsequence is :\nMemoization : %d\nTabulation : %d\n",lcs(x,y,b,c,m,n),lcs_t(x,y,m,n));
    printf("The longest common subsequence of X,Y is : ");
    printans(x,b,m,n);
    printf("\n");
    return 0;
}
