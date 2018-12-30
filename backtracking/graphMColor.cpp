//图的m着色问题
//给定无向连通图G和m个颜色
#include <iostream>
#include <iomanip>

using namespace std;

const int Num = 5;//顶点数量
const int m_Num = 4;//颜色数

bool conflict(int k,int color[],const int graph[Num][Num]);
void Backtrack(int t,int color[], int &count,const int graph[Num][Num]);

int main()
{
    
    static int count = 0;
    int color[Num];//下标表示图的顶点 值代表颜色的种类

    //给图的顶点关系赋值
    const int graph[Num][Num] = {
        {0,1,1,1,0},
        {1,0,1,1,1},
        {1,1,0,1,0},
        {1,1,1,0,1},
        {0,1,0,1,0}
    };

    Backtrack(0,color,count,graph);
    cout<<count;
}

bool conflict(int k,int color[],const int graph[Num][Num])
{//检查颜色是否冲突
//true 代表无冲突
    for(int i=0;i<k;i++)
        if((graph[k][i] == 1) && (color[i] == color[k]))//graph[k][i]=1表示相邻
            return false;
    return true;
}

void Backtrack(int t,int color[], int &count,const int graph[Num][Num])
{//t表示从顶点标志
    //搜索到叶节点
    if(t>=Num)
    {
        count++;
        for(int i=0;i<Num;i++)
            cout<<color[i]<<ends;
        cout<<endl;
    }
    else
    {
        for(int i=0;i<m_Num;i++)
        {
            color[t] = i;
            if(conflict(t,color,graph))
                Backtrack(t+1,color,count,graph);
        }
    }

}