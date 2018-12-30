// divide and conquer
// binary search 
// O(logn)

#include <iostream>

using namespace std;

int binarySearch(int *,const int &,int);

int main()
{
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    int serachX = 2;

    int index = binarySearch(array,serachX,9);
    if(index == -1)
        cout<<"search fail"<<endl;
    else
        cout<<"index:"<<index;
}

int binarySearch(int *array,const int &x,int end)
{//array sorted from small to large
    int left = 0;
    int right = end;

    while(left<=right)
    {
        int mid = left+(right-left)/2;
        if(x>array[mid])
            left = mid+1;
        else if(x==array[mid])
            return mid; //success
        else
            right = mid-1;
    }

    return -1;//fail
}