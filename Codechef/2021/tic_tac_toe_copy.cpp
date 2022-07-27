#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >>t;

    while(t--)
    {
        char a[9][9];
        int winx=0, wino=0, x=0,o=0,u=0 ,i, j;

        for(i = 0; i < 3; i++)
        {
            for(j=0; j< 3; j++)
            {
                cin >>a[i][j];

                if(a[i][j] == '_')  u++;
                if(a[i][j] == 'X')  x++;
                if(a[i][j] == 'O')  o++;
            }
        }

        if(a[0][0]=='X' && a[1][0]=='X' && a[2][0]=='X')    winx=1;
        if(a[0][1]=='X' && a[1][1]=='X' && a[2][1]=='X')    winx=1;
        if(a[0][2]=='X' && a[1][2]=='X' && a[2][2]=='X')    winx=1;
        if(a[0][0]=='X' && a[1][1]=='X' && a[2][2]=='X')    winx=1;
        if(a[0][2]=='X' && a[1][1]=='X' && a[2][0]=='X')    winx=1;
        if(a[0][0]=='X' && a[0][1]=='X' && a[0][2]=='X')    winx=1;
        if(a[1][0]=='X' && a[1][1]=='X' && a[1][2]=='X')    winx=1;
        if(a[2][0]=='X' && a[2][1]=='X' && a[2][2]=='X')    winx=1;

        if(a[0][0]=='O' && a[1][0]=='O' && a[2][0]=='O')    wino=1;
        if(a[0][1]=='O' && a[1][1]=='O' && a[2][1]=='O')    wino=1;
        if(a[0][2]=='O' && a[1][2]=='O' && a[2][2]=='O')    wino=1;
        if(a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O')    wino=1;
        if(a[0][2]=='O' && a[1][1]=='O' && a[2][0]=='O')    wino=1;
        if(a[0][0]=='O' && a[0][1]=='O' && a[0][2]=='O')    wino=1;
        if(a[1][0]=='O' && a[1][1]=='O' && a[1][2]=='O')    wino=1;
        if(a[2][0]=='O' && a[2][1]=='O' && a[2][2]=='O')    wino=1;

        if((winx==1 && wino==1) || (x-o < 0) || (x-o>1))    cout<<"3"<<endl;
        else if(x==0 && o==0 && u==9)                       cout<<"2"<<endl;
        else if(winx==1 && wino==0 && x>o)                  cout<<"1"<<endl;
        else if(winx==0 && wino==1 && x==o)                 cout<<"1"<<endl;
        else if(winx==0 && wino==0 && u==0)                 cout<<"1"<<endl;
        else if(winx==0 && wino==0 && u>0)                  cout<<"2"<<endl;
        else                                                cout<<"3"<<endl;

    }
    return 0;
}