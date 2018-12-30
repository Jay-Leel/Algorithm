//大整数相乘
//以符号数组的形式存储和打印数据

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string multi(string numA,string numB);


int main()
{
    string numA = "-12356";
    string numB = "-12356";

    string result = multi(numA,numB);
    cout<<result<<endl;
}   

string multi(string numA,string numB)
{
    int len_A=numA.length();
    int len_B = numB.length();
    int start_A;
    int start_B;
    if(numA[0] == '-' || numA[0] == '+')
    {
        start_A = 1;
    }
    else 
    {
        start_A = 0;
    }
    if(numB[0] == '-' || numB[0] == '+')
    {
        start_B = 1;
    }
    else 
    {
        start_B = 0;
    }

    string sign;       
    if((numA[0]=='-' && numB[0] != '-') || (numA[0] !='-' && numB[0] =='-'))
        sign = "-";
    else 
        sign = "+";

    int num_arr[len_A+len_B];
    memset(num_arr,0,sizeof(int)*(len_A+len_B));//zero

    for(int i=len_A-1;i>=start_A;i--)
    {//从数据的低位开始计算
        for(int j=len_B-1;j>=start_B;j--)
        {
            num_arr[i+j+1] += (numA[i]-'0')*(numB[j]-'0');
        }
    }

    for(int i=len_A+len_B-1;i>0;i--)
    {//carry
        if(num_arr[i]>=10)
        {
            num_arr[i-1] += num_arr[i]/10;
            num_arr[i] %= 10;
        }
    }

    string result="";
    for(int i=0;i<(len_A+len_B);i++)
    {
        result = result+(char)(((int)'0')+num_arr[i]);
    }
    result.insert(0,sign);
    return result;
}