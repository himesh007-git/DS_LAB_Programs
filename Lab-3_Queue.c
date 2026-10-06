#include<stdio.h>
#define MAX 100
int front=-1,rear=-1;
int Queue[MAX];

void insert(int n){

    if(rear==MAX-1){
        printf("\nQueue is full");
    }
    else{
        if (front==-1){
        front=0;
        }
    rear++;
    Queue[rear]=n;
    printf("%d added successfully\n",n);
    }
}

void Delete(){
    int val;
    if (front==-1 || front>rear)
        printf("\nQueue is empty");
    else{
        val=Queue[front];
        printf("\n%d is deleted",val);
        front++;

    }
    if (front> rear){
        front=-1;
        rear=-1;
    }
}

void display(){
    if (front==-1 || front>rear){
        printf("\n\nQueue is empty");
    }

    else{

        printf("Displaying Queue\n");

        for (int i=front;i<=rear;i++)
            {
                printf("%d ",Queue[i]);
            }
    }
}

int main(){
    int a=1,choice,val;
    while (a==1){
        printf("\n===Queue Operations Menu===\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:printf("\nEnter your value:");
                   scanf("%d",&val);
                   insert(val);
                   break;

            case 2:Delete();
                   break;

            case 3:display();
                   break;

            case 4:a=0;
                    printf("\nPrograsm has ended");
                    break;

            default : printf("\nInvalid choice.Enter valid choice");

        }
    }
}
