#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
        int n,m, count = 0;
        cin>>n>>m;

        char grid[n+1][m+1];

        for(int i=0;i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==n || j==m)
                grid[i][j] = '.';
                else
                cin>>grid[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; i<m; i++)
            {
                if(grid[i][j]=='L' && grid[i][j+1]=='D')
                {
                    count++;
                    grid[i][j+1]=='.';
                    grid[i][j]=='.';
                }
                if(grid[i][j]=='D' && grid[i][j+1]=='L')
                {
                    count++;
                    grid[i][j]=='.';
                    grid[i][j+1]=='.';
                }

            }
        }

        for(int j=0; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
                if(grid[i+1][j]=='L' && grid[i][j]=='D')
                {
                    count++;
                    grid[i][j]=='.';
                    grid[i+1][j]=='.';
                }
                if(grid[i][j]=='L' && grid[i+1][j]=='D')
                {
                    count++;
                    grid[i+1][j]=='.';
                    grid[i][j]=='.';
                }
            }
        }

        cout<<count<<endl;
    return 0;
}