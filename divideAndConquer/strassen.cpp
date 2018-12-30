//Matrix Multiply with Strassen
//divide and conquer
//the size of the matrix must be 2^n

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int Num = 16;//   the size of the matrix
const int Max = 10;
const int Min = 0;

void MatrixSub(int n,int A[][Num],int B[][Num],int T[][Num]);
void MatrixMultiply(int A[][Num],int B[Num][Num],int C[Num][Num]);
void MatrixAdd(int n,int A[][Num],int B[][Num],int T[][Num]);
void strassen(int n,int A[][Num],int (&B)[Num][Num],int C[][Num]);

int main()
{
    int A[Num][Num];
    int B[Num][Num];
    int C[Num][Num];

    //assignment
    for(int i=0;i<Num;i++)
    {
        for(int j=0;j<Num;j++)
        {
            A[i][j] = rand()%(Max-Min) + Min;//[Min,Max)
            B[i][j] = rand()%(Max-Min) + Min;//[Min,Max)
        }
    }

    cout<<"Matrix A:"<<endl;
    for(int i=0;i<Num;i++)
    {
        for(int j=0;j<Num;j++)
        {
            cout<<setw(2)<<A[i][j]<<ends;
        }
        cout<<endl;
    }
    cout<<"Matrix B:"<<endl;
    for(int i=0;i<Num;i++)
    {
        for(int j=0;j<Num;j++)
        {
            cout<<setw(2)<<B[i][j]<<ends;
        }
        cout<<endl;
    }

    strassen(Num,A,B,C);
    cout<<"A*B:"<<endl;
    for(int i=0;i<Num;i++)
    {
        for(int j=0;j<Num;j++)
        {
            cout<<setw(4)<<C[i][j]<<ends;
        }
        cout<<endl;
    }

    return 0;
}

void MatrixMultiply(int A[][Num],int B[][Num],int (*C)[Num])
{//三个形参表达方式相同！！！！
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            C[i][j] = 0;
            for(int t=0;t<2;t++)
            {
                C[i][j] = C[i][j] + A[i][t]*B[t][j];
            }
        }
    }
}

void MatrixAdd(int n,int A[][Num],int B[][Num],int T[][Num])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            T[i][j] = A[i][j] + B[i][j];
        }
    }
}

void MatrixSub(int n,int A[][Num],int B[][Num],int T[][Num])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            T[i][j] = A[i][j] - B[i][j];
    }
}

void strassen(int n,int A[][Num],int (&B)[Num][Num],int C[][Num])
{//引用作为参数的效果相同！！！！！
    int A11[Num][Num],A12[Num][Num],A21[Num][Num],A22[Num][Num];
    int B11[Num][Num],B12[Num][Num],B21[Num][Num],B22[Num][Num];
    int C11[Num][Num],C12[Num][Num],C21[Num][Num],C22[Num][Num];
    int M1[Num][Num],M2[Num][Num],M3[Num][Num],M4[Num][Num],M5[Num][Num],M6[Num][Num],M7[Num][Num];
    // int **A11,**A12,**A21,**A22;

    if(n==2)
    {
        MatrixMultiply(A,B,C);
    }
    else
    {//divide
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j+n/2];
                A21[i][j] = A[i+n/2][j];
                A22[i][j] = A[i+n/2][j+n/2];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j+n/2];
                B21[i][j] = B[i+n/2][j];
                B22[i][j] = B[i+n/2][j+n/2];
            }
        }   

    int AA[Num][Num];
    int BB[Num][Num];

    //calculate M5 =(A11+A22)(B11+B22)
    MatrixAdd(n/2,A11,A22,AA);
    MatrixAdd(n/2,B11,B22,BB);
    strassen(n/2,AA,BB,M5);

    //calculate M1 =A11(B12-B22)
    MatrixSub(n/2,B12,B22,AA);
    strassen(n/2,A11,AA,M1);

    //calculate M2 = (A11+A12)B22
    MatrixAdd(n/2,A11,A12,AA);
    strassen(n/2,AA,B22,M2);

    //calculate M3 = (A21+A22)B11
    MatrixAdd(n/2,A21,A22,AA);
    strassen(n/2,AA,B11,M3);

    //calculate M4 =A22(B21-B11)
    MatrixSub(n/2,B21,B11,AA);
    strassen(n/2,A22,AA,M4);

    //calculate M6= (A12-A22)(B21+B22)
    MatrixSub(n/2,A12,A22,AA);
    MatrixAdd(n/2,B21,B22,BB);
    strassen(n/2,AA,BB,M6);

    //calculate M7=(A11-A21)(B11+B12)
    MatrixAdd(n/2,B11,B12,BB);
    MatrixSub(n/2,A11,A21,AA);
    strassen(n/2,AA,BB,M7);


    //calculate C11=M5+M4-M2+M6
    MatrixAdd(n/2,M5,M4,AA);
    MatrixSub(n/2,AA,M2,BB);
    MatrixAdd(n/2,BB,M6,C11);

    //calculate C12 = M1+M2
    MatrixAdd(n/2,M1,M2,C12);

    //calculate C21=M3+M4
    MatrixAdd(n/2,M3,M4,C21);

    //calculate C22 = M5+M1-M3-M7
    MatrixAdd(n/2,M5,M1,AA);
    MatrixSub(n/2,AA,M3,BB);
    MatrixSub(n/2,BB,M7,C22);


    //set C
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            C[i][j] = C11[i][j];
            C[i][j+n/2]=C12[i][j];
            C[i+n/2][j] = C21[i][j];
            C[i+n/2][j+n/2]=C22[i][j];
        }
    }
    }
}