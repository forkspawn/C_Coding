#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int count_p=0; // for printing the matrix

int minCostPath_Dp(int** edges, int m, int n) //creating a 2d array
{
    int **ans=new int*[m]; // first column

    for(int i=0;i<m;i++)
    {
        ans[i]=new int [n];// then creating rows for each column
        for(int j=0;j<n;j++)
        {
            ans[i][j]=0;
        }
    }
  ans[m-1][n-1]=edges[m-1][n-1];

  for(int j=n-2;j>=0;j--) // for last row
  {
    ans[m-1][j]=edges[m-1][j]+ans[m-1][j+1];
  }
  for(int i = m-2;i>=0;i--) // for last column
  {
    ans[i][n-1]=edges[i][n-1]+ans[i+1][n-1];
  }
  for(int i=m-2;i>=0;i--)
  {
    for(int j=n-2;j>=0;j--)
    {
        ans[i][j]=edges[i][j]+min(ans[i][j+1], min(ans[i+1][j],ans[i+1][j+1]));
    }
  }
    return ans[0][0];
}


int minCostHelper(int **edges,int m,int n,int i, int j)
{
    if(i==m-1 && j==n-1) // meaning you reached the last cell
    {
        return edges[i][j];
    }
    if(i>=m || j>=n)
    {
        return INT_MAX;
    }
    int x=minCostHelper(edges,m,n,i,j+1);
    int y=minCostHelper(edges,m,n,i+1,j);
    int z=minCostHelper(edges,m,n,i+1,j+1);
    int output=min(x,min(y,z))+edges[i][j];
    return output;
}

int minCostPath(int **edges,int m,int n)
{
    return minCostHelper(edges,m,n,0,0);
}

int main()
{
    int m; // these are the columns
    int n; // these are the rows
    cout<<"Enter Number of columns and rows"<<endl;
    cin>>m>>n;
    int **edges=new int*[m];

    for(int i=0;i<m;i++)
    {
        edges[i]=new int [n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int ans;
            cout<<"Enter the values for the matrix at position "<<i<<j<<endl;
            cin>>ans;
            edges[i][j]=ans;
        }
    }

    cout<<"The matrix is\n";

   for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
             cout<< edges[i][j]<<" ";
             count_p=count_p+1;  // if((i==0&&j==2)||(i==1&&j==2)||(i==2&&j==2))
          if(count_p%m==0)
            { cout<<"\n"; }
        }
    }
    

    int ans= minCostPath(edges,m,n);
    cout<<"Without memorization \n"<<ans<<endl;
    cout<<"with memorization"<<endl;
    ans=minCostPath_Dp( edges,m,n); 
    cout<<ans<<endl;
}
