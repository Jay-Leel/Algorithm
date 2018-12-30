//切割钢条
//动态规划

#include <iostream>
#include <sys/time.h>

using namespace std;

int cutRod(int p[],int n);
int memorizedCutRodAux(int p[],int n,int r[]);
int memorizedCutRod(int p[],int n);
int bottomUpCutRod(int p[],int n,int s[]);
void printCutRod(int p[],int n);

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
    {    
       struct timeval tv;    
       gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
       return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
    }  

int main()
{
    time_t before;
    time_t after;

    int value[11]={0,1,5,8,9,10,17,17,20,24,30};      //下标代表钢条长度 内容表示价格 0不用
    int Num = 7;
    before = getCurrentTime();
    int result = memorizedCutRod(value,Num);
    after = getCurrentTime();
    cout<<"备忘录"<<result<<ends<<"所用时间:"<<after-before<<endl;

    before = getCurrentTime();
    int result1 = cutRod(value,Num);
    after = getCurrentTime();
    cout<<"朴素递归"<<result1<<ends<<"所用时间:"<<after-before<<endl;
    
    printCutRod(value,Num);


    return 0;

}

//朴素递归方式
//自顶向下
int cutRod(int p[],int n)
{
    if(n==0)
        return 0;//不切割
    int q = INT_MIN;
    for(int i=1;i<=n;i++)
    {   
        q = max(q,p[i]+cutRod(p,n-i));
    }
    
    return q;
}

//备忘录递归方法
//自顶向下
int memorizedCutRod(int p[],int n)
{
    
    int r[n+1];//保存值
    //初始化
    for(int i=0;i<=n;i++)
        r[i] = INT_MIN;
    
    return memorizedCutRodAux(p,n,r);
}
int memorizedCutRodAux(int p[],int n,int r[])
{
    int q;
    //检查所需值是否已知
    if(r[n]>=0)
        return r[n];
    
    if(n==0)
        q=0;
    else
    {
        q = INT_MIN;
        for(int i=1;i<=n;i++)
            q = max(q,p[i]+memorizedCutRodAux(p,n-i,r));
    }

    r[n] = q;//将已知值保存
    
    return q;
}   

//动态规划
//自底向上
//包含切割规则
int bottomUpCutRod(int p[],int n,int s[])
{
    //保存子问题数据
    int r[n+1];
    r[0] = 0;
    
    //保存钢条长度
    // int s[n+1];

    //求一个问题之前先求解子问题
    int q;
    for(int j = 1;j<=n;j++)
    {
        q = INT_MIN;
        for(int i=1;i<=j;i++)
        {
            if(q<p[i]+r[j-i])
                {
                    q = p[i]+r[j-i];
                    s[j] = i;
                }
        }
        r[j] = q;
    }

    return r[n];
}

void printCutRod(int p[],int n)
{
    int s[n+1];//保存钢条长度
    int r = bottomUpCutRod(p,n,s);
    cout<<"最大价值："<<r<<endl;
    cout<<"分割规则："<<endl;
    while(n>0)
    {
        cout<<s[n]<<ends;
        n = n-s[n];
    }
}