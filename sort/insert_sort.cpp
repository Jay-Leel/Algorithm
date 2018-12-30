//suitable for sorting small amounts of elements

#include <iostream>
#include <cstdlib>

using namespace std;

const int Num = 10;
const int Min =0;
const int Max = 20;

void insert_sort(int *);

int main()
{
    int random[Num];
    for (int i=0;i<Num;i++)
    {
        random[i] = rand()%(Max-Min)+Min;//[Min~max)
    }

    cout<<"before sort"<<endl;
    for(auto &w:random)
        cout<<w<<ends;
    cout<<endl;

    insert_sort(random);
    cout<<"after sort"<<endl;
    for(auto w:random)
        cout<<w<<ends;

    return 0;
}

// sort function
// small to large
void insert_sort(int *array)
{   
    for(int i=1;i<Num;i++)
    {
        int key = *(array+i);
        int j = i-1;
        //compare every elements
        while(j>=0 && *(array+j)>key)
        {
            *(array+j+1) = *(array+j);
            j--;
        }
        *(array+j+1) = key;
    }
}