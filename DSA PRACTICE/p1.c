#include<stdio.h>
#include<stdlib.h>

struct Day{
    char *dayName;
    int date;
    char *activity;
};

void create(struct Day*day){
    day->dayName=(char*)malloc(sizeof(char)*20);
    day->activity=(char*)malloc(sizeof(char)*100);

    printf("Enter day name:");
    scanf("%s",day->dayName);

    printf("Enter date:");
    scanf("%d",&day->date);

    printf("Enter activity:");
    scanf("%s",day->activity);
}

void read(struct Day*calendar, int size){
    for(int i=0; i<size; i++){
        printf("\nEnter details for day %d\n",i+1);
        create(&calendar[i]);
    }
}

void display(struct Day*calendar, int size){
    printf("\nWeek's activity details:");
    for(int i=0; i<size; i++){
        printf("\nDay %d\n",i+1);
        printf("Day Name: %s\n",calendar[i].dayName);
        printf("Date: %d\n",calendar[i].date);
        printf("Activity: %s\n",calendar[i].activity);
        printf("\n");
    }
}

void freeMemory(struct Day*calendar, int size){
    for(int i=0; i<size; i++){
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
}

int main(){
    int n;
    printf("\nEnter number of days in a week:");
    scanf("%d",&n);

    struct Day*calendar=(struct Day*)malloc(sizeof(struct Day)*n);

    if(calendar==NULL){
        printf("\nMemory allocation failed");
        return 1;
    }

    read(calendar,n);
    display(calendar,n);

    freeMemory(calendar,n);
    free(calendar);

    return 0;
}
