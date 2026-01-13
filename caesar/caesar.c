#include <cs50.h>
#include <ctype.h> //functions
#include <stdio.h> //basic i/o
#include <stdlib.h> //for string to integer atoi that's a new thing for me but I found it
#include <string.h>

bool only_digits(string s);
char rotate(char c,int k);

int main(int argc,string argv[]){
    if(argc != 2|| !only_digits(argv[1])){
        printf("Usage: ./ceaser key\n");   //here it is checking that user provide exactyly one number is input invalid it prints a message
        return 1;
    }

    int key=atoi(argv[1])%26; //converting the key to an int and mod 26 for alphabt range

    string plaintext=get_string("plaintext:  ");
    printf("ciphertext: ");

    for(int i=0,n=strlen(plaintext);i<n;i++){   //itarate over each characcter of string
        printf("%c",rotate(plaintext[i],key));  //encriytips and prints
    }
    printf("\n");
    return 0;
}

bool only_digits(string s){  //checks for string contains only digits
    for(int i=0;s[i]!='\0';i++){
        if(!isdigit((unsigned char)s[i])){
            return 0;
        }
    }
    return true;
}

//this given in the lesson I rememberdered the logic from there
char rotate(char c,int k){
    if(isupper((unsigned char) c)){
        return 'A'+((c-'A'+k)%26);
    }
    else if(islower((unsigned char)c)){
        return 'a'+((c-'a'+k)%26);
    }
    else
    {
        return c;
    }
}
