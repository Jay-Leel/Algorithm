//投资问题

#include <iostream>
#include <iomanip>

using namespace std;

void Inveset(int m,int n,int **f,const int g[][9],int **d);

int main()
{
    //g[i][j]表示向i个项目投资j时的收益
    const int g[3][9] ={
        {0,5,15,40,80,90,95,98,100},
        {0,5,15,40,60,70,73,74,75},
        {0,4,26,40,45,50,51,53,53}
    };
    int **f = new int *[3];
    for(int i=0;i<3;i++)
        f[i] = new int[9];
    int **d = new int *[3];
    for(int i=0;i<3;i++)
        d[i] = new int[9];

    Inveset(9,3,f,g,d);

    cout<<"收益如下"<<endl;
    cout<<ends<<ends;
    for(int i=0;i<9;i++)
        cout<<setw(3)<<i<<ends;
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<i<<ends;
        for(int j=0;j<9;j++)
            cout<<setw(3)<<f[i][j]<<ends;
        cout<<endl;
    }

    cout<<"投资分配"<<endl;
    cout<<ends<<ends;
    for(int i=0;i<9;i++)
        cout<<setw(3)<<i<<ends;
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<i<<ends;
        for(int j=0;j<9;j++)
            cout<<setw(3)<<d[i][j]<<ends;
        cout<<endl;
    }
}   

void Inveset(int m,int n,int **f,const int g[][9],int **d)
{//m代表总投资额
//n代表n项工程
//f[i][j]代表共有i项工程总投资额为j时的收益
//即向前i项工程投资为j时f[i][j]获得最大收益，
// 此时向第i项工程的投资额为d[i][j]
    for(int j=0;j<m;j++)
    {
        f[0][j] = g[0][j];
        d[0][j] = j;
    }
    for(int i=0;i<n;i++)
        d[i][0] = 0;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            f[i][j] = 0;
            for(int k=0;k<=j;k++)
            {
                int s = f[i-1][j-k]+g[i][k];
                if(s>f[i][j])
                {
                    f[i][j] = s;
                    d[i][j] =k;
                }
            }
        }
    }
}