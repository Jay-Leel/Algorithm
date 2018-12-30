//最长公共子序列
//动态规划

#include <iostream>
#include <string>

using namespace std;

void LCSLength(string x,string y,int m,int n);
void print_LSC(char **b,string x,int i,int j);
int main()
{
    //用0填充
    string x("0ABCBDAB");
    string y("0ADCABA");
    int m = x.length();
    int n = y.length();

    LCSLength(x,y,m,n);
    return 0;
}


void LCSLength(string x,string y,int m,int n)
{

    char **b = new char*[m];
    for(int i=0;i<m;i++)
        b[i] = new char[n];

    int c[m][n];

    for(int i=0;i<m;i++)
        c[i][0] = 0;

    for(int i=0;i<n;i++)
        c[0][i] =0;
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j] = '\\';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = '|';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = '-';
            }
        }
    }
//竖排为x，横排为y
    cout<<"b[i][j]"<<endl;
    cout<<ends<<ends;
    for(int i=1;i<n;i++)
        cout<<i<<ends;
    cout<<endl;
    for(int i=1;i<m;i++)
    {
        cout<<i<<ends;
        for(int j=1;j<n;j++)
        {
            cout<<b[i][j]<<ends;
        }
        cout<<endl;
    }

    cout<<"c[i][j]"<<endl;
    cout<<ends<<ends;
    for(int i=0;i<n;i++)
        cout<<i<<ends;
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<i<<ends;
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<ends;
        }
        cout<<endl;
    }

    print_LSC(b,x,m-1,n-1);

}


void print_LSC(char **b,string x,int i,int j)
{
    if(i==0||j==0)
        return;
    if(b[i][j]=='\\')
    {
        print_LSC(b,x,i-1,j-1);
        cout<<x[i]<<ends;
    }
    else if(b[i][j]=='|')
        print_LSC(b,x,i-1,j);
    else
        print_LSC(b,x,i,j-1);
}