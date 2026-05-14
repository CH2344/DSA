#include<stdio.h>
#include<stdlib.h>
void printMat(int rows,int col,int** mat){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");   
    }
}
int** mul(int m,int n, int p, int q,int A[][n], int B[][q]){
    if(n!=p){return NULL;}
    int k,sum;
    int** mul = (int**) calloc(m,sizeof(int*));
    if(mul==NULL){
        printf("Multiplication not possible");
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        mul[i] = (int*) calloc(q,sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            sum = 0;
            for (k = 0; k < n; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            mul[i][j] = sum;
        }
        
    }
    return mul;
}
int main(int argc, char const *argv[])
{
    int m,n,q,p;
    m=2,n=3,p=3,q=2;
    int A[2][3]={{1,2,3},{4,5,6}};
    int B[3][2]={{7,8},{9,10},{11,12}};
    int** multi = mul(m,n,p,q,A,B);
    printMat(m,q,multi);
    return 0;
}
