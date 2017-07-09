#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    struct node *left,*right,*p;
}node;

node *newnode(){
    node *p=(node *)malloc(sizeof(node));
    p->left=(node *)malloc(sizeof(node));
    p->right=(node *)malloc(sizeof(node));
    p->left->left=p->left->right=p->right->left=p->right->right=NULL;
    return p;
}

/*Tabulation method
 *Worst case time complexity = O(n^3).
 */
void optimalbst(float *p,float *q,float **e,float **w,int **root,int n){
    int i,j,k,l;
    float temp;
    for(l=1;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            e[i][j]=INT_MAX;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(k=i;k<=j;k++){
                temp=e[i][k-1]+e[k+1][j]+w[i][j];
                if(temp<e[i][j]){
                    e[i][j]=temp;
                    root[i][j]=k;
                }
            }
        }
    }
    return;
}

/*Worst case time complexity =O(n).
 */
node *constructoptimalbst(int **root,int i,int j){
    node *x=newnode();
    if(j<i){
            return x;
    }
    if(i>root[i][j]-1)printf("d%d is the left child of k%d\n",root[i][j]-1,i);
    else printf("k%d is the left child of k%d\n",root[i][root[i][j]-1],root[i][j]);
    x->left=constructoptimalbst(root,i,root[i][j]-1);
    if(root[i][j]+1>j)printf("d%d is the right child of k%d\n",j,j);
    else printf("k%d is the right child of k%d\n",root[root[i][j]+1][j],root[i][j]);
    x->right=constructoptimalbst(root,root[i][j]+1,j);
    return x;
}

int main() {
    int n,i;
    scanf("%d",&n);
    node *head;
    float *p=(float *)malloc(sizeof(float)*(n+1));
    float *q=(float *)malloc(sizeof(float)*(n+1));
    float **e=(float **)malloc(sizeof(float *)*(n+2));
    float **w=(float **)malloc(sizeof(float *)*(n+2));
    int **root=(int **)malloc(sizeof(int *)*(n+1));
    printf("Enter probabilities of keys:\n");
    for(i=1;i<=n;i++)scanf("%f",&p[i]);
    printf("Enter probabilities of dummys:\n");
    for(i=0;i<=n;i++)scanf("%f",&q[i]);
    for(i=1;i<=n+1;i++){
        e[i]=(float *)malloc(sizeof(float)*(n+1));
        w[i]=(float *)malloc(sizeof(float)*(n+1));
        if(i<=n)root[i]=(int *)malloc(sizeof(int)*(n+1));
        if(i>0){
                w[i][i-1]=q[i-1];
                e[i][i-1]=q[i-1];
        }
    }
    optimalbst(p,q,e,w,root,n);
    printf("Total cost for optimal BST:%f\n",e[1][n]);
    printf("K%d is the root\n",root[1][n]);
    head=constructoptimalbst(root,1,n);
    return 0;
}
