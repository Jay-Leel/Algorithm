//n皇后
//backtracking 

#include <iostream>
#include <cmath>

using namespace std;

const int Num = 8;

bool conflict(int k,int chess[]);
void QueenRecursive(int k,int chess[],int &count);
void printChess(int count,int chess[]);
void QueenIteration(int k,int chess[],int &count);

int main()
{
    int chess[Num];//下标存储行数 值存储列数

    static int count = 0;
    // QueenRecursive(0,chess,count);
    QueenIteration(0,chess,count);
    cout<<"result:";
    cout<<count<<endl;
    getchar();
    return 0;
}

bool conflict(int k,int chess[])
{//k代表开始的行数
//当没有冲突的时候返回true
    for(int i=0;i<k;i++)
    {
        if(chess[k] == chess[i] ||abs(chess[k]-chess[i]) == (k-i))
            return false;
    }
    return true;
}

void QueenRecursive(int k,int chess[],int &count)
{
    if(k>=Num)
    {//到达叶子节点
        count++;
        printChess(count,chess);
    }
    else
    {
        for(int i=0;i<Num;i++)
        {
            chess[k] = i;
            if(conflict(k,chess))
                QueenRecursive(k+1,chess,count);
        }
    }
}

void QueenIteration(int k,int chess[],int &count)
{
    chess[k] = -1;
    while(k>=0)
    {
        chess[k]+=1;
        while((chess[k]<Num) && !conflict(k,chess))
            chess[k]+=1;
        if(chess[k]<Num)
        {
            if(k==Num-1)//到达叶子节点
            {
                count++;
                printChess(count,chess);
            }
            else//继续向下搜索
            {
                k++;
                chess[k] = -1;   //初始化新行的皇后位置
            }
        }//未找到合适的位置
        else
            k--;
    }
}

void printChess(int count,int chess[])
{
    for(int i=0;i<Num;i++)
    {
        for(int k=0;k<Num;k++)
        {
            if(k == chess[i])
                cout<<"#"<<ends;
            else    
                cout<<"*"<<ends;
        }
        cout<<endl;
    }
    cout<<endl;
}