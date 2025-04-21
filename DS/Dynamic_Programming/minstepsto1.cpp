#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//int minStepsHelper(int n , int *ans);
//int minSteps_mem(int n);
//int minSteps(int n);

int minStep_DP(int n) //with dynamic programming
{
    int *ans = new int [n+1];
    ans[0]=0;
    ans[1]=0;
    for(int i=2; i<=n;i++)
    {
        int subtract1=ans[i-1];
        int divideby2=INT_MAX;
        int divideby3=INT_MAX;
            if(i%2==0)
            {
                divideby2=ans[i/2];
            }

            if(i%3==0)
            {
                divideby3=ans[i/3];
            }
    
            ans[i]=min(subtract1,min(divideby2,divideby3))+1;
    }
    return ans[n];
}

int minStepHelper(int n, int *ans)
{
    if(ans[n]!=-1)
    {
        return ans[n];
    }

   if(n<=1)
    {
       ans[n]=0;
       return ans[n];
    }
  
   int x=INT_MAX;
   int y=INT_MAX;
   int subtract1=minStepHelper(n-1,ans);
    if(n%2==0)
    {
        x=minStepHelper(n/2,ans);
    }

    if(n%3==0)
    {
        y=minStepHelper(n/3,ans);
    }

    int output=min(subtract1,min(x,y))+1;
    ans[n]=output;
    return output;
}

int minStep_mem(int n)
{
    int *ans= new int[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }
    return minStepHelper(n,ans);
}

int minStep(int n) // this function without helper
{
       if(n<=1)
    {
        return 0;
    }
      
     int x=INT_MAX;
     int y=INT_MAX;
     int subtract1=minStep(n-1);
    if(n%2==0)
    {
        x=minStep(n/2);
    }

    if(n%3==0)
    {
        y=minStep(n/3);
    }

    int ans=min(subtract1,min(x,y))+1;
    return ans;
}

int main()
{

    cout<<"Enter the number to find min steps to get 1 either by sub, div by2, div by3"<<endl;
    int n;
    cin>>n;
    cout<<minStep_mem(n)<<endl;
    cout<<minStep_DP(n)<<endl;
    cout<<minStep(n)<<endl;
    
}
