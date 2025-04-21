#include<iostream>
#include<string>
using namespace std;

int lcs_dp(string s, string t)
{
 int m=s.size();
 int n=t.size();
 int **ans=new int*[m+1]; //Creating an Array of size m and n
    for(int i=0;i<=m;i++)
    {
        ans[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
          ans[i][j]=-1;   
        }
    }

    //for 1st row filling it with zeroes as we know in the base case s or t size is 0 then return 0
    for(int j=0;j<=n;j++)
    {
        ans[0][j]=0;
    }
    //for 1st column same filling it with zero
    for(int i=0;i<=m;i++)
    {
        ans[i][0]=0;
    }
    
    for(int i=1;i<=m;i++) // as wer already compared 0 we are starting from 1
    {
        for(int j=1;j<=n;j++)
        {
            if(s[m-i]==t[n-j]) // s[i]==s[j] compares each term of s to each term of t but we need to find each term of s to last term of t therefore s[m-i]==t[n-j]
            {
                 ans[i][j]=1+ans[i-1][j-1];
            }
            else{
            
                int a=ans[i][j-1];
                int b=ans[i-1][j];
                int c= ans[i-1][j-1];
                ans[i][j]=max(a,max(b,c));
            }
        } 
    }
    return ans[m][n];
}

int lcs_memcall(string s, string t,int **ans) // call to calculate wih memorization
{
   int m=s.size();
   int n=t.size();
   int answer;

    if(s.size()==0 || t.size()==0) // If the size of string is zero return 0
    {
        ans[m][n]=0;
        return 0;
    }
    if(ans[m][n]!=-1)
    {
        return ans[m][n];
    }
    if(s[0]==t[0]) //Checks the first part of the string of two strings in the recursive call, if they are match it returns and then checks the string from 1 position leaving 0
    {
        answer= 1+lcs_memcall(s.substr(1),t.substr(1),ans);
    }
    else
    {
    int a= lcs_memcall(s,t.substr(1),ans); // check first term in s and second to last term in t
    int b= lcs_memcall(s.substr(1),t,ans); // check second term to last in s and first term in t
    int c= lcs_memcall(s.substr(1),t.substr(1),ans); // checks the second term of both s and t
    answer= max(a,max(b,c)); // after checking the all three it gives the max value of finding it
    }
    ans[m][n]=answer;
    return answer;
}

int lcs_mem(string s, string t)// with memorization where we pass the memory to calculate the value
{
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1]; // creates new pointer with size m+1
    for(int i=0;i<=m;i++)
    {
        ans[i]=new int[n+1]; // assiging an array to new pointer so that it becomes 2-d array
        for(int j=0;j<=n;j++)
        {
          ans[i][j]=-1; // assiging -1 to all values in the array
        }
    }
    return lcs_memcall(s,t,ans);
}


int lcs(string s, string t) //lcs without memorization
{
    if(s.size()==0 || t.size()==0)
    {
        return 0;
    }
    if(s[0]==t[0])
    {
        return 1+lcs(s.substr(1),t.substr(1));
    }
    else
    {
    int a= lcs(s,t.substr(1));
    int  b= lcs(s.substr(1),t);
    int c=lcs(s.substr(1),t.substr(1));
        return max(a,max(b,c));
    }

}

int main(){
    
    string s,t; 
    cout<<"Enter two String with no spaces to compare the longest subsequence in them\n";
    cin>>s>>t;
    cout<<endl;
    cout<<"With Memorization "<<lcs_mem(s,t)<<endl;
    cout<<"With DynamicProgramming "<<lcs_dp(s,t)<<endl;
    cout<<"Without Memorization "<<lcs(s,t)<<"\n";
}
