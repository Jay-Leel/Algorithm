//maximum subarray with divide-and-conquer
//O(nlogn)
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int Num = 20;
const int Max = 20;
const int Min = -10;

vector<int> findMaxCrossingSubarray(int *array,int start,int mid,int end);
vector<int> findMaximumSubarray(int *array,int start,int end);

int main()
{
    int random[Num];
    for (int i=0;i<Num;i++)
        random[i]= rand()%(Max-Min) + Min;//[Min,Max)


    cout<<"content:"<<endl;
    for(auto w:random)
        cout<<w<<ends;
    cout<<endl<<endl;
    
    vector<int> temp;
    temp = findMaximumSubarray(random,0,Num-1);
    cout<<"maximum:"<<ends<<temp[2]<<endl;
    cout<<"start:"<<ends<<temp[0]<<endl;
    cout<<"end:"<<ends<<temp[1]<<endl;

    return 0;
}


vector<int> findMaxCrossingSubarray(int *array,int start,int mid,int end)
{
    //maximum on the left
    int left_sum = INT_MIN;
    int temp_sum = 0;
    int min_left;
    for(int i=mid;i>=start;i--)
    {
        temp_sum = temp_sum+array[i];
        if(temp_sum>left_sum)
        {
            left_sum = temp_sum;
            min_left = i;
        }
    }
    //maximum on the right
    int right_sum = INT_MIN;
    temp_sum = 0;
    int max_right;
    for (int i=mid+1;i<=end;i++)
    {
        temp_sum += array[i];
        if(temp_sum>right_sum)
        {
            right_sum = temp_sum;
            max_right = i;
        }
    }

    vector<int> temp={min_left,max_right,left_sum+right_sum};
    return temp;
}


vector<int> findMaximumSubarray(int *array,int start,int end)
{
    vector<int> temp;
    if(start == end)
    {
        temp.clear();
        temp = {start,end,array[start]};//base case only one element
        return temp;
    }
    else
    {
        int mid = start+(end-start)/2;
        temp = findMaximumSubarray(array,start,mid);
        int left_start = temp[0];
        int left_end = temp[1];
        int left_sum = temp[2];
        
        temp = findMaximumSubarray(array,mid+1,end);
        int right_start = temp[0];
        int right_end = temp[1];
        int right_sum = temp[2];

        temp = findMaxCrossingSubarray(array,start,mid,end);
        int cross_start = temp[0];
        int cross_end = temp[1];
        int cross_sum = temp[2];

        if(left_sum>=right_sum && left_sum>= cross_sum)
        {
            temp.clear();
            temp = {left_start,left_end,left_sum};
            return temp;
        }
        else if(right_sum>= left_sum && right_sum>=cross_sum)
        {
            temp.clear();
            temp = {right_start,right_end,right_sum};
            return temp;
        }
        else
        {
            temp.clear();
            temp ={cross_start,cross_end,cross_sum};
            return temp;
        }
    }
}