#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[10]; a[0] = 'a';
        int row=0, col=0, inc, i, j, win=0;
        int count_x=0, count_o=0, count_s=0;
        
        for(i =1; i<10; i++)
        {
            scanf(" %c",&a[i]);

            if(a[i] == '_')  count_s++;
            if(a[i] == 'X')  count_x++;
            if(a[i] == 'O')  count_o++;
        }

        for(i=1; i<10; i= i+3) //row
        {
            if(a[i] == 'X' && a[i+1] == 'X' && a[i+2] == 'X')
            {
                row++; 
                win =1;
            }    
            if(a[i] == 'O' && a[i+1] == 'O' && a[i+2] == 'O')
            row++;
        }
        for(j=1; j<4; j++) //column
        {
            if(a[j] == 'X' && a[j+3] == 'X' && a[j+6] == 'X')
            {
                col++; 
                win =1;
            } 
            if(a[j] == 'O' && a[j+3] == 'O' && a[j+6] == 'O')
            col++;
        }
        if((a[1]=='X' && a[5]=='X' && a[9]=='X') || (a[3]=='X' && a[5]=='X' && a[7]=='X'))
        {
                inc=1; 
                win =1;
        } 
        if((a[1]=='O' && a[5]=='O' && a[9]=='O') || (a[3]=='O' && a[5]=='O' && a[7]=='O'))
        inc=1;
        
        if(count_s == 0) // NO SPACE
        {
            if(count_x - count_o != 1)
                printf("3\n");
            else
            {
                if(col > 1 || row > 1) 
                    printf("3\n");
                else if(col==1 || row==1 || inc==1)
                    printf("1\n");
                else 
                    printf("3\n");
            }
        }
        else  // WITH SPACE
        {     
            if(count_s%2 == 0)
            {
                if(count_x - count_o != 1)
                printf("3\n");
            }
            else
            {
                if(count_o != count_x)
                    printf("3\n");
                else if((count_o == count_x && win==1) || (col > 1 || row > 1))
                    printf("3\n");
                else if(col==1 || row==1 || inc==1)
                    printf("1\n");
                else 
                    printf("2\n");  
            }          
        }
    }
    return 0;
}