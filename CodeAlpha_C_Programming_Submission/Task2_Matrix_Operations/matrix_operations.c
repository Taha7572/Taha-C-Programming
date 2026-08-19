#include <stdio.h>
#define MAX 10

void readMatrix(int m[MAX][MAX], int rows, int cols) {
    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            scanf("%d",&m[i][j]);
}

void printMatrix(int m[MAX][MAX], int rows, int cols) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) printf("%d ",m[i][j]);
        printf("\n");
    }
}

void add(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int out[MAX][MAX];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) out[i][j]=a[i][j]+b[i][j];
    printMatrix(out,r,c);
}

void multiply(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int r2, int c2) {
    if(c1!=r2){ printf("Matrix multiplication is not possible.\n"); return; }
    int out[MAX][MAX]={0};
    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++)
            for(int k=0;k<c1;k++)
                out[i][j]+=a[i][k]*b[k][j];
    printMatrix(out,r1,c2);
}

void transpose(int a[MAX][MAX], int r, int c) {
    for(int j=0;j<c;j++){
        for(int i=0;i<r;i++) printf("%d ",a[i][j]);
        printf("\n");
    }
}

int main(void) {
    int a[MAX][MAX],b[MAX][MAX],r,c,r2,c2,choice;
    printf("=== Matrix Operations ===\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose\nChoose: ");
    scanf("%d",&choice);

    if(choice==1){
        printf("Rows and columns: "); scanf("%d%d",&r,&c);
        printf("Enter matrix A:\n"); readMatrix(a,r,c);
        printf("Enter matrix B:\n"); readMatrix(b,r,c);
        printf("Result:\n"); add(a,b,r,c);
    } else if(choice==2){
        printf("Rows and columns of A: "); scanf("%d%d",&r,&c);
        printf("Rows and columns of B: "); scanf("%d%d",&r2,&c2);
        printf("Enter A:\n"); readMatrix(a,r,c);
        printf("Enter B:\n"); readMatrix(b,r2,c2);
        printf("Result:\n"); multiply(a,b,r,c,r2,c2);
    } else if(choice==3){
        printf("Rows and columns: "); scanf("%d%d",&r,&c);
        printf("Enter matrix:\n"); readMatrix(a,r,c);
        printf("Transpose:\n"); transpose(a,r,c);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
