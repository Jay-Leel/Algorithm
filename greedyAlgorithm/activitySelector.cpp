//活动选择
//贪心算法
//目标是选择一个最大的互相兼容的活动集合
//贪心选择是自顶向下的选择

#include <iostream>
#include <iomanip>

using namespace std;

const int N = 11;

void GreedySelector(int n, int s[], int f[], bool A[]);
void Sort(int s[],int f[],int n);
//递归
void RecursiveGreedySelector(int n,int k,int s[], int f[], bool A[]);

int main(void)
{
	//start
	int s[] = {1,3,0,5,3,5,5,8,8,2,12};
	//final
	int f[] = {4,5,6,7,8,9,10,11,12,13,14};
	//activity
	bool A[N];

    cout<<"i"<<ends<<ends<<ends;
	for(int i=0;i<N;i++)
		cout<<"|"<<setw(2)<<i;
	cout<<endl;

	cout<<"s[i]";
	for(int i=0;i<N;i++)
		cout<<"|"<<setw(2)<<s[i];
	cout<<endl;

	cout<<"f[i]";
	for(int i=0;i<N;i++)
		cout<<"|"<<setw(2)<<f[i];
	cout<<endl;

	// GreedySelector(N,s,f,A);
	Sort(s,f,N);
	RecursiveGreedySelector(N,0,s,f,A);
	cout<<"活动安排为"<<endl;
	for(int i=0;i<N;i++)
	{
		if(A[i])
        {
			cout<<i<<"--"<<ends;
		}
	} 

	

	return 0;
}

void GreedySelector(int n, int s[], int f[], bool A[])
{
	Sort(s,f,N);
	A[0]=true;
	int j=0;
 
	for (int i=1;i<n;i++)
	{
		if (s[i]>=f[j])
		{
			//更新j
			A[i]=true;
			j=i;
		}
		else
		{
			A[i]=false;
		}
	}
} 


void Sort(int s[],int f[],int n)
{
    int temps;
	for(int i=1;i<n;i++)
    {
        int key = f[i];
		temps = s[i];
        int j = i-1;
        //compare every elements
        while(j>=0 && f[j]>key)
        {
			f[j+1] =f[j];
			s[j+1] = s[j];
            j--;
        }
        f[j+1] = key;
		s[j+1] = temps;
    }
    
}

void RecursiveGreedySelector(int n,int k,int s[], int f[], bool A[])
{//n代表问题规模
//k代表已解决的子问题下标
	A[0]=true;
	int m = k+1;
	while(m<=n && s[m]<f[k])
	{
		A[m] = false;
		m = m+1;
	}
	if(m<=n)
	{
		A[m]=true;
		RecursiveGreedySelector(n,m,s,f,A);
	}
}