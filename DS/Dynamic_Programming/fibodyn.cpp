#include<iostream>
using namespace std;

int fiboHelper(int n,int *ans)
{
    if(ans[n]!=-1)
    {
        return ans[n];
    }

    if(n<=1)
    {
        ans[n]=n;
        return ans[n];
    }

    int a = fiboHelper(n-1,ans);
    int b = fiboHelper(n-2,ans);
    int output = a+b;
    ans[n] = output; // this part is memorization where the computer value is stored in an array
    return ans[n];
}

int fibo_mem(int n)
{
    int *ans = new int[n+1]; // dynamically create an array
    for(int i =0; i<=n; i++)
    {
        ans[i]=-1;
    }

    return fiboHelper(n,ans);
}

int fibo_dp(int n)
{
    int *ans = new int[n+1]; // does the same thing but with no memorization just sums previous two elements in an array
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        ans[i]=ans[i-1]+ans[i-2]; 
    }
    
    return ans[n];
}

int main()
{
    int n;
    cout<<"Type the number you want the fiboncaci sum"<<endl;
    cin>>n;
    cout<<fibo_mem(n)<<endl;
    
    cout<<fibo_dp(n)<<endl;

}
