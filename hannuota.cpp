//汉诺塔

#include <iostream>
#include<string>

using namespace std;

int hannuota(int n,string a,string b,string c)
{//c为目标塔 a->>>>c
    if(n==1)
    {
        cout<<"塔"<<a.c_str()<<"--------->"<<c.c_str()<<endl;
    }
    else
    {
        hannuota(n-1,a,c,b);
        cout<<"塔"<<a.c_str()<<"--------->"<<c.c_str()<<endl;
        hannuota(n-1,b,a,c);
    }
    return 1;
}

int main()
{
    cout<<"input the number:"<<endl;
    int num;
    cin>>num;
    hannuota(num,"A","B","C");
    return 0;
}