#include <stdio.h>
#include <cs50.h>

int main(void){
    int change=get_int("Change owed=");
    int i=0;
    if(change>0)
    {
        while(change-25>=0)
        {
            i=i+1;
            change=change-25;
        }
        while(change-10>=0){
            i=i+1;
            change=change-10;
        }
        while(change-5>=0){
            i=i+1;
            change=change-5;
        }
        while(change-1>=0){
            i=i+1;
            change=change-1;
        }
        printf("%i\n",i);
    }
    else if(change==0)
    {
        printf("0\n");
    }
}
