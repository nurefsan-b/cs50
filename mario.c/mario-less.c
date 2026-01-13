#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int line,height;
    Starting:
    printf("Height:");
    height = get_int();
    if(height>0)
    {
        for(line=0;line<height;line++){
            int space = height-line-1;
            int hash = line+2;

            for(int x=0;x<space;x++)
            {
                printf(" ");
            }
            for(int y=0; y<hash;y++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    else if()
    {
        goto Starting;
    }




}
