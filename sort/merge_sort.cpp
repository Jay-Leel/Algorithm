//merge sort
//divide and conquer

#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge_sort(int *,int ,int );
void merge(int *array,int start,int mid,int end);

const int Num = 8;
const int Max = 50;
const int Min = 10;


int main()
{
    srand((unsigned int) time(0));
    int random[Num];
    for (int i=0;i<Num;i++)
        random[i]= rand()%(Max-Min) + Min;//[Min,Max)

    cout<<"before sort"<<endl;
    for(auto w:random)
        cout<<w<<ends;
    cout<<endl;

    merge_sort(random,0,Num-1);
    cout<<"after sort"<<endl;
    for(auto w:random)
        cout<<w<<ends;

    return 0;
}

//merge sort
void merge_sort(int *array,int start,int end)
{
    if(start<end)
    {
        int mid = start+(end-start)/2;
        merge_sort(array,start,mid);
        merge_sort(array,mid+1,end);
        merge(array,start,mid,end);
        for(int i=0;i<Num;i++)
            cout<<array[i]<<ends;
        cout<<endl;
    }
}

void merge(int *array,int start,int mid,int end)
{   //merge
    //array[start:end]
    int temp1 = end-mid;  //the length of second half 
    int temp2 = mid-start+1;  //the length of first half

    int left[temp2+1];
    int right[temp1+1];

    for(int i=0;i<temp2;i++)
    {
        left[i] = array[start+i];
    }
    for(int i=0;i<temp1;i++)
    {
        right[i] = array[mid+i+1];
    }
    //set guard
    left[temp2] = INT_MAX;
    right[temp1] = INT_MAX;

    int k=0;
    int p=0;
    for(int i=start;i<=end;i++)
    {
        if(left[k]<=right[p])
        {
            array[i] = left[k];
            k++;
        }
        else
        {
            array[i] = right[p];
            p++;
        }
    }//当碰到哨兵牌的时候已经都合并完成
}
