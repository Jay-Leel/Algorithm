//01背包问题
//动态规划

#include<iostream>
#include<iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;

const int Num = 5;//物品个数

void Knapsack(int v[],int w[],int c,int n,int **m);
void OptimalKnapsack(int [],int [],int,int,vector<vector<int>> &,vector<vector<int>> &);//优化后的函数
int main()
{
    //下标为0的时候代表没有物品
    int v[Num+1] = {0,1,6,18,22,28};//value
    int w[Num+1] = {0,1,2,5,6,7};//weight
    int c = 11;//背包容量
    int **m = new int*[Num+1];
    for(int i=0;i<Num+1;i++)
        m[i] = new int[c+1];
    Knapsack(v,w,c,Num,m);
    // cout<<"goods -- x"<<"capacity -- y"<<endl;
    // for(int i=0;i<=c;i++)
    //     cout<<setw(2)<<i<<ends;
    // cout<<endl;
    // for(int i=0;i<Num+1;i++)
    // {
    //     for(int j=0;j<c+1;j++)
    //         cout<<setw(2)<<m[i][j]<<ends;
    //     cout<<endl;
    // }
    vector<vector<int>> capacity;
    vector<vector<int>> value;
    OptimalKnapsack(v,w,c,Num,capacity,value);
    // for(size_t i=0;i<capacity.size();i++)
    // {
    //     cout<<"S["<<i<<"]"<<ends;
    //     for(size_t j=0;j<capacity[i].size();j++)
    //     {
    //         cout<<"("<<capacity[i][j]<<",";
    //         cout<<value[i][j]<<")";
    //     }
    //     cout<<endl;
    // }

        
}


void Knapsack(int v[],int w[],int c,int n,int **m)
{//v[]物品价值
//w[] 物品重量
//c背包容量
//n物品个数
//m[i][j]前i个物品中挑选重量不超过j的物品，使得总价值最大
//这时的最优值为m[i][j]
//时间复杂度O(cn)当c>2^n O(n2^n)
    for(int i=0;i<=c;i++)
        m[0][i] = 0;//容量从1开始 0代表背包容量为0
    for(int i=0;i<=n;i++)
        m[i][0] = 0;//物品从1开始 0代表没有物品
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=c;j++)
        {
            if(w[i]>j)
                m[i][j] = m[i-1][j];
            else//选第i个物品（容量减少）和不选第i个物品
                m[i][j] = max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
        }
}


void OptimalKnapsack(int v[],int w[],int c,int n,vector<vector<int>> &capacity,vector<vector<int>> &value)
{//算法来源https://zhuanlan.zhihu.com/p/30959069
//时间复杂度和空间复杂度均降低的算法 
//时间复杂度最大为O(2^n)
    // vector<vector<int>> capacity;//容量
    // vector<vector<int>> value;//总价值
    vector<int> capacity_temp;
    vector<int> value_temp;
    capacity_temp.push_back(0);
    value_temp.push_back(0);

    //初始化
    capacity.push_back(capacity_temp);
    value.push_back(value_temp);
    
    capacity_temp.clear();
    value_temp.clear();

    for(int i=1;i<=n;i++)//i代表物品数量
    {
        //把上一个vector中元素加入
        for(size_t j=0;j<capacity[i-1].size();j++)
        {
            capacity_temp.push_back(capacity[i-1][j]);
            value_temp.push_back(value[i-1][j]);
        }
        capacity.push_back(capacity_temp);
        value.push_back(value_temp);
        value_temp.clear();
        capacity_temp.clear();
        for(size_t j=0;j<capacity[i-1].size();j++)
        {
            int temp_cap = capacity[i-1][j]+w[i];//重量
            int temp_val = value[i-1][j]+v[i];//价值
            if(temp_cap<=c)//小于背包容量时才允许
            {
                vector<int>::iterator ret;
                ret = find(capacity[i-1].begin(),capacity[i-1].end(),temp_cap);
                if(ret == capacity[i-1].end())
                {//没有重复元素的出现
                    capacity[i].push_back(capacity[i-1][j]+w[i]);
                    value[i].push_back(value[i-1][j]+v[i]);
                }
                else
                {//重复元素出现
                    int index = distance(capacity[i-1].begin(),ret);//返回相同元素的索引
                    if(value[i][index]<temp_val)
                        value[i][index] = temp_val;
                }
            }
        }
    }
}