#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    int m,n, k=0, l=0;
    cin>>m>>n;
    int mtrx[m][n];

    /* 
        k = first index of column
        l = first index of row
        m = number of row
        n = number of column
    */
   
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n ; j++)
        {
            cin>>mtrx[i][j];
        }
    }
    
    while(k < m && l < n)
    {
        //first row from remaining rows
        for(int i=l; i<n; i++)
        {
            cout<<mtrx[k][i]<<" ";
        }
        k++;

        //last colimn from remaining columns
        for(int i=k; i<m; i++)
        {
            cout<<mtrx[i][n-1]<<" ";
        }
        n--;

        //last row from remaining rows
        if(k<m)
        {
            for(int i=n-1; i >= l; i--)
            {
                cout<<mtrx[m-1][i]<<" ";
            }
            m--;
        }

        //first column from remaining columns
        if(l<n)
        {
            for(int i=m-1; i>=k; i--)
            {
                cout<<mtrx[i][l]<<" ";
            }
            l++;
        }
    }
    return 0;
}