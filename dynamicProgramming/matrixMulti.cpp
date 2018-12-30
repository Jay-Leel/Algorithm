//矩阵链乘法
//动态规划
//O(n^3)

#include<iostream>
#include <iomanip>


using namespace std;

void MatrixChain(int p[],int n,int **m,int **s);
void printOptimal(int **s,int i,int j);
//备忘录方法
int LookUpChain(int **m,int p[],int i,int j);
int memoizedMatrix(int p[],int n,int **m);

int main()
{
    int p[7]={30,35,15,5,10,20,25};//存储矩阵维度 6个矩阵
    
    int **m = new int*[7];
    for(int i=0;i<7;i++)
        m[i] = new int[7];

    int **s = new int *[7];
    for(int i = 0;i<7;i++)
        s[i] = new int[7];

    cout<<"矩阵维度表"<<endl;
    for(int i=1;i<7;i++)
        cout<<"A"<<i<<setw(6);
    cout<<endl;
    for(int i=0;i<6;i++)
        cout<<p[i]<<"x"<<p[i+1]<<ends;
    cout<<endl;
    
    MatrixChain(p,6,m,s);
    cout<<"m[i][j]"<<endl;
    for(int i=1;i<7;i++)
        cout<<ends<<setw(5)<<i<<ends;
    cout<<endl<<"-----------------"<<endl;
    for(int i=1;i<7;i++)
    {
        cout<<i;
        for(int j=1;j<7;j++)
        {
            if(j<i)
                cout<<ends<<"none "<<ends;
            else
                cout<<ends<<setw(5)<<m[i][j]<<ends;
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<"s[i,j]"<<endl;
    for(int i=1;i<7;i++)
        cout<<ends<<setw(5)<<i<<ends;
    cout<<endl<<"-----------------"<<endl;
    for(int i=1;i<7;i++)
    {
        cout<<i;
        for(int j=1;j<7;j++)
        {
            if(j<=i)
                cout<<ends<<"none "<<ends;
            else
                cout<<ends<<setw(5)<<s[i][j]<<ends;
        }
        cout<<endl;
    }

    cout<<"矩阵分割过程"<<endl;
    printOptimal(s,1,6);

    cout<<endl<<"备忘录方法"<<endl;
    memoizedMatrix(p,6,m);
    cout<<"m[i][j]"<<endl;
    for(int i=1;i<7;i++)
        cout<<ends<<setw(5)<<i<<ends;
    cout<<endl<<"-----------------"<<endl;
    for(int i=1;i<7;i++)
    {
        cout<<i;
        for(int j=1;j<7;j++)
        {
            if(j<i)
                cout<<ends<<"none "<<ends;
            else
                cout<<ends<<setw(5)<<m[i][j]<<ends;
        }
        cout<<endl;
    }
    cout<<endl;

}

void MatrixChain(int p[],int n,int **m,int **s)
{//p存储矩阵的参数
//n代表矩阵数量
//公式m[i,j] = {0 ;如果i=j || min{m[i,k]+m[k+1,j]+p(i-1)p(k)p(j)} 如果i<j
    // int **m;//计算所需乘法的次数
    // int **s;//记录分割点
    //长度为1的链路的最小计算代价
    for(int i=1;i<=n;i++)
        m[i][i] = 0;
    
    for(int length =2;length<=n;length++)//length is the chain length
    {//链路长度从2增加到n
        for(int i=1;i<= n-length+1;i++)
        {//第一个下标的矩阵数
            int j= i+length-1;//第二个下标的矩阵数
            m[i][j] = INT_MAX;
            for(int k=i;k<= j-1;k++)
            {//[i,j]之间所有分割情况
                int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
            }
        }
    }
    return;    
}


void printOptimal(int **s,int i,int j)
{//打印矩阵分割过程
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        printOptimal(s,i,s[i][j]);
        printOptimal(s,s[i][j]+1,j);
        cout<<")";
    }
}


int memoizedMatrix(int p[],int n,int **m)
{
    for (int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
            m[i][j] = INT_MAX;
    }

    return LookUpChain(m,p,1,n);
}


int LookUpChain(int **m,int p[],int i,int j)
{
    if(m[i][j]<INT_MAX)
        return m[i][j];
    if(i==j)
        m[i][j] = 0;
    else
    {
        for(int k=i;k<= j-1;k++)
        {
            int q = LookUpChain(m,p,i,k) +LookUpChain(m,p,k+1,j)+p[i-1]*p[k]*p[j];
            if(q<m[i][j])
                m[i][j] = q;
        }
    }

    return m[i][j];
}