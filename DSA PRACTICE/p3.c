#include<stdio.h>
#include<stdlib.h>

#define MAX 3
int s[MAX];
int top=-1;

void push(int item){
    if(top==MAX-1){
        printf("\nStack Overflow\n");
        return;
    }
    top=top+1;
    s[top]=item;
}

int pop(){
    int item;
    if(top==-1){
        printf("\nStack Underflow\n");
        return -1;
    }
    item=s[top];
    top=top-1;
    return item;
}

void display(){
    int i;
    if(top==-1){
        printf("\nEmtpy stack\n");
        return;
    }
    printf("\nElements of stack are:\n");
    for(i=top; i>=0; i--){
        printf("|%d|\n",s[i]);
    }
}

void palindrome(){
    int flag=1, i;
    printf("\nContents of stack:\n");
    for(i=top; i>=0; i--){
        printf("|%d|\n",s[i]);
    }

    printf("\nReverse of stack:\n");
    for(i=0; i<=top; i++){
        printf("|%d|\n",s[i]);
    }

    for(i=0; i<=top/2; i++){
        if(s[i]!=s[top-i]){
            flag=0;
            break;
        }
    }

    if(flag==1){
        printf("\nIt is a palindrome number");
    }
    else{
        printf("\nIt is not a palindrome number");
    }
}

int main(){
    int ch, item;

    while(1){
        printf("\n");
        printf("\n----------MENU----------");
        printf("\n1. PUSH(OVERFLOW)");
        printf("\n2. POP(UNDERFLOW)");
        printf("\n3. Palindrome");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("\nEnter an element to be pushed:");
                scanf("%d",&item);
                push(item);
                break;

            case 2:
                item=pop();
                if(item!=-1){
                    printf("\nThe element popped is %d", item);
                }
                break;

            case 3:
                palindrome();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(1);

            default:
                printf("\nPlease enter a valid choice");
        }
    }

    return 0;
}
