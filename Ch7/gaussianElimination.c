#include <stdio.h>
#include <stdlib.h>
#define n 5

/*
* This program performs Gaussian Elimination without pivoting. It is assumed that the matrix provided
* is not singular and it does not contain small pivot elements.
*/

void gaussianElimination(double** A, double* b, double* x, int size);
void rowEchelon(double** A, double* b, int rowIndex, int size);
void backwardSubstitution(double** A, double* b, double* x, int size);

int main(){
    double* x = (double*)malloc(n*sizeof(double));
    double* b = (double*)malloc(n*sizeof(double));
    double** mat = (double**)malloc(n*sizeof(double*));
    for(int i=0;i<n;++i){
        mat[i] = (double*)malloc(n*sizeof(double));
    }
    mat[0][0]=3.55618; mat[0][1]=5.87317; mat[0][2]=7.84934; mat[0][3]=5.6951; mat[0][4]=3.84642;
    mat[1][0]=-4.82893;mat[1][1]=8.38177;mat[1][2]=-0.301221;mat[1][3]=5.10182;mat[1][4]=-4.1169;
    mat[2][0]=-7.64196;mat[2][1]=5.66605;mat[2][2]=3.20481;mat[2][3]=1.55619;mat[2][4]=-1.19814;
    mat[3][0]=-2.95914;mat[3][1]=-9.16958;mat[3][2]=7.3216;mat[3][3]= 2.39876;mat[3][4]=-8.1302;  
    mat[4][0]=-8.42043; mat[4][1]=-0.369407;mat[4][2]=-5.4102;mat[4][3]=-8.00545;mat[4][4]= 9.22153;  
    
    b[0]=-1.92193; b[1]=-2.35262; b[2]=2.27709;b[3]=-2.67493;b[4]=1.84756;
     
    gaussianElimination(mat,b,x,n);
    printf("The solution of the system is as follows \n");
    printf("x[0]=%lf\n",x[0]);
    printf("x[1]=%lf\n",x[1]);
    printf("x[2]=%lf\n",x[2]);
    printf("x[3]=%lf\n",x[3]);
    printf("x[4]=%lf\n",x[4]);
    
    //deallocate memory
    for(int i=0;i<n;++i){
        free( mat[i]) ;
    }
    free(mat);
    free(b);
    free(x);
    return 0;
}

void gaussianElimination(double** A, double* b, double* x, int size){
    for(int k=0;k<size-1;++k){
        rowEchelon(A,b,k,size);
    }
    backwardSubstitution(A,b,x,size);
}

void rowEchelon(double** A, double* b, int rowIndex, int size){
    double pivot = A[rowIndex][rowIndex];
    for (int i=rowIndex+1;i<size;++i){
        double multiplier=A[i][rowIndex]/pivot;
        for(int j=rowIndex+1;j<size;++j){
            A[i][j] =  A[i][j] - (multiplier*A[rowIndex][j]);
        }
        b[i] = b[i] - (multiplier*b[rowIndex]);
    }
}

void backwardSubstitution(double** A, double* b, double* x, int size){
    x[size-1] = b[size-1]/A[size-1][size-1];
    for(int k=size-2; k>-1;--k){
        double sum = 0.0;
        for(int i=k+1;i<size;++i){
            sum+= A[k][i]*x[i];
        }
        x[k] = (b[k]-sum)/A[k][k];
    }
}