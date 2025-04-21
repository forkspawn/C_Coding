#include<iostream>
#include<string>
using namespace std;

int editDistance(string s, string t)
{
    if(s.size()==0 || t.size()==0)
    {
        if(s.size()==0)
            return t.size();
        if(t.size()==0)
            return s.size();
    }
    
    if(s[0]==t[0])
        return editDistance(s.substr(1),t.substr(1));
    else
    {
        int a=1+ editDistance(s.substr(1),t); //deletion
        int b=1+ editDistance(s,t.substr(1)); //insertion
        int c=1+ editDistance(s.substr(1),t.substr(1)); //subsitution

        return min(a,min(b,c));
    }

}

int editDistance_mem(string s,string t, int **ans)
{
  
    int m=s.size(); 
    int n=t.size();
    int answer;

    if(s.size()==0 || t.size()==0)
    {
        if(s.size()==0)
        {
            ans[m][n]=t.size();
            return t.size();
        }
        if(t.size()==0)
        {   
            ans[m][n]==s.size();  
            return s.size();
        }
    }
    if(ans[m][n]!=-1)
    {
        return ans[m][n];
    }
    
    if(s[0]==t[0])
        answer= editDistance_mem(s.substr(1),t.substr(1),ans);
    else
    {
        int a=1+ editDistance_mem(s.substr(1),t,ans); //deletion
        int b=1+ editDistance_mem(s,t.substr(1),ans); //insertion
        int c=1+ editDistance_mem(s.substr(1),t.substr(1),ans); //subsitution

        answer= min(a,min(b,c));
    }
    ans[m][n]=answer; 
    return answer;
}

int editDistance_mem(string s, string t)
{
    int m=s.size(); // size of column
    int n=t.size(); // size of row
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        ans[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            ans[i][j]=-1;
    }
    }
    return editDistance_mem(s,t,ans);

}

int editDistance_dp(string s, string t)
{
    int m=s.size();
    int n=t.size();
    int answer;
   
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        ans[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            ans[i][j]=-1;
        }
     
    }   // 1st row
        for(int j=0;j<=n;j++)
        {
         ans[0][j]=j;
        }
        //ist column
        for(int i=0;i<=m;i++)
        {
            ans[i][0]=i;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[m-i]==t[n-j])
                {
                     ans[i][j]=ans[i-1][j-1];
                }
                else
                {
                    int a=1+ans[i-1][j]; //deletion
                    int b=1+ans[i-1][j-1]; //subsitute
                    int c=1+ans[i][j-1]; //insertion
                
                    ans[i][j]=min(a,min(b,c));
                }
            }
        }
    
        return ans[m][n];

}
int main()
{
    string s,t;
    cout<<"Enter two strings\n";
    cin>>s>>t;
    int ans=editDistance(s,t);
    cout<<"Number of operation to become equal "<<endl;
    cout<<"With Memorization "<<editDistance_mem(s,t)<<endl;
    cout<<"recursion "<<ans<<endl;

}

