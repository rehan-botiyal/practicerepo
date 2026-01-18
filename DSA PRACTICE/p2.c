#include<stdio.h>
char str[50], res[50], rep[20], pat[20];
int i=0, j=0, k, m=0, c=0, flag=0;

void stringMatch(){
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag=1;
                for(k=0; rep[k]!='\0'; k++, j++){
                    res[j]=rep[k];
                }
                i=0;
                c=m;
            }
        }
        else{
            res[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
    res[j]='\0';
}

int main(){
    printf("Enter the main string:");
    gets(str);

    printf("\nEnter the pattern string:");
    gets(pat);

    printf("\nEnter the replace string:");
    gets(rep);

    printf("\nThe string before pattern matching: %s\n", str);

    stringMatch();
    if(flag==1)
        printf("\nThe string after pattern match: %s\n", res);
    else
        printf("\nPattern string not found");

    return 0;
}
