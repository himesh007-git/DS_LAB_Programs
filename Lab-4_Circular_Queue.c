#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int n){
    if ((front==0 && rear==4 ) || (front==rear+1)){
        printf("\nQueue is full");
        return ;
    }
    if (front==-1){
        front=0;rear=0;
        Queue[rear]=n;
    }
    else if (rear==MAX-1){
        rear=0;
        Queue[rear]=n;
    }
    else{
        rear++;
        Queue[rear]=n;
    }


}

void dequeue(){
    int val;
    if (front==-1){
        printf("\nQueue is empty");
        return ;
    }
    if (front==rear){
        val=Queue[front];
        front=-1;rear=-1;
    }
    else if (front==MAX-1){
        val=Queue[front];
        front=0;
    }
    else{
        val=Queue[front];
        front++;
    }
    printf("\n%d Delete successfully",val);

}

void display(){
    int i;
    if (front==-1){
        printf("\nQueue is empty");
        return ;
    }
    for(i=front;i!=rear;i=(i+1)%MAX){
        printf("\n %d",Queue[i]);

    }printf("\n %d",Queue[i]);
}

int main(){
    int choice,num;
    int c=1;
    while (c==1){
        printf("\nCircular Queue Operations");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        if (choice==1){
            printf("\nEnter your number:");
            scanf("%d",&num);
            enqueue(num);
        }
        else if (choice==2){
            dequeue();
        }
        else if (choice==3){
            display();
        }
        else if (choice==4){
            c=0;
        }
        else{
            printf("\nInvalid choice");
        }
    }


   return 0;
}
