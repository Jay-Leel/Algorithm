//quick sort 
//divid and conquer

#include<iostream>
#include <cstdlib>

using namespace std;

void quick_sort(int *array,int start,int end);
int partition(int *array,int start,int end);

const int Num = 10;
const int Max = 50;
const int Min = 10;

int main()
{
    int random[Num];
    for (int i=0;i<Num;i++)
        random[i]= rand()%(Max-Min) + Min;//[Min,Max)

    cout<<"before sort"<<endl;
    for(auto w:random)
        cout<<w<<ends;
    cout<<endl;

    quick_sort(random,0,Num-1);
    cout<<"after sort"<<endl;
    for(auto w:random)
        cout<<w<<ends;

    return 0;
}

void quick_sort(int *array,int start,int end)
{
    if(start<end)
    {
        int flag = partition(array,start,end);
        quick_sort(array,start,flag-1);
        quick_sort(array,flag+1,end);
    }
}

int partition(int *array,int start,int end)
{//确定基准元素
    int i=start;
    int j = end+1;

    int x = array[start];//确定基准元素

    //把比x小的元素放左边 
    //比x大的元素放右边
    while(true)
    {
        while(array[++i]<x && i<end);
        while(array[--j]>x);
        if(i>=j)
        {
            break;
        }
        swap(array[i],array[j]);
    }
    array[start] =array[j];
    array[j] = x;
    for(int i=0;i<Num;i++)
        cout<<array[i]<<ends;
    cout<<endl;
    return j;
}