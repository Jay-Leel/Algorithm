//单源最短路径

#include <iostream>
#include <iomanip>

using namespace std;


void dijkstra(int n,int dist[],int prev[],int **c);

int main()
{
    int num_side;//边的数量
    int num_vertix;//顶点的数量

    cout<<"输入边的数量:";
    cin >> num_side;
    cout<<"输入顶点的数量:";
    cin >> num_vertix;
    
    int dist[num_vertix];
    for(int i=0;i<num_vertix;i++)
        dist[i] = INT_MAX;
    int prev[num_vertix];
    int **side = new int*[num_vertix];//顶点间的权

    int vertex_x, vertex_y, length;

    for(int i=0;i<num_vertix;i++)
    {
        side[i] = new int[num_vertix];
        for(int j=0;j<num_vertix;j++)
        {
            side[i][j] = INT_MAX;
        }
        side[i][i] = 0;
    }

    cout<<"输入边的权值<顶点 顶点 长度><'#'结束>"<<endl;
    while(cin>>vertex_x && cin>>vertex_y && cin>>length)
    {
        side[vertex_x][vertex_y] = length;
        side[vertex_y][vertex_x] = length;
    }

    dijkstra(num_vertix,dist,prev,side);
    
}

void dijkstra(int n,int dist[],int prev[],int**c)
{
//c[i][j]代表边[i,j]的权
//dist[i]表示当前从源到顶点i的最短特殊路径长度
//prev[i]代表从源到顶点i的最短特殊路径上i的前一个顶点
//v代表源顶点

    int v = 0;
    bool s[n];//集合s

    //初始化
    for(int i=0;i<n;i++)//i表示目的顶点
    {
        dist[i] = c[v][i];
        s[i]=false;
        if(dist[i] == INT_MAX)
            prev[i] = 0;
        else
            prev[i] = v;
    }

    dist[v] =0;
    s[v] = true;//把源顶点加入到集合s

    for(int i=1;i<n;i++)
    {
        //求当前源节点到其他顶点的最短路径
        int temp = INT_MAX;
        int u = v;
        for(int j=0;j<n;j++)
            if((!s[j] && (dist[j]<temp)))
            {
                u=j;
                temp = dist[j];
            }
        s[u] = true;

        //把u加入到s中后，更新当前源到其他顶点的距离
        for(int j=0;j<n;j++)
        {
            if((!s[j]) && (c[u][j]<INT_MAX))
            {
                int newdist = dist[u]+c[u][j];
                if(newdist<dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
        }
        cout<<"迭代"<<ends<<"     S      "<<ends<<"u "<<ends;
        for(int i=0;i<n;i++)
            cout<<"dist["<<i<<"]"<<ends;
        for(int i=0;i<n;i++)
            cout<<"prev["<<i<<"]"<<ends;
        cout<<endl;
        cout<<setw(4)<<i<<ends<<ends;
        int j=n;
        for(int i=0;i<n;i++)
        {
            if(s[i]==true)
            {
                if(i==0)
                    cout<<i;
                else
                    cout<<','<<i;
                j--;
            }
        }
        for(int k=0;k<j;k++)
                cout<<"  ";
        cout<<ends<<ends<<u<<ends;
        for(int i=0;i<n;i++)
        {
            cout<<setw(7)<<dist[i]<<ends;
        }
        for(int i=0;i<n;i++)
        {
            cout<<setw(7)<<prev[i]<<ends;
        }
        cout<<endl;
        
    }
}