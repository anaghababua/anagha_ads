#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top=0;
void push(int value);
void pop();
void display();
void main()
{
int element*,choice;
printf("enter an element");
scanf("%d",&element);
printf("1.push..");
printf("enter choice");
scanf("%d",&choice);
do
{
switch(choice);
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
printf("exit");
break;
printf("does not match");
}
while(choice!=4);
void push(int element);
{
struct node *newnode;
newnode=(struct node*)malloc(size)
(struct node);
newnode->data=element;
newnode->next=top;
top=newnode;
}
void display()
{
struct node *temp;
temp=top
if(top==0)
{
printf("under flow");
else
{
while(temp!=0)
{
printf("%d",temp->data);
temp=temp->next.}
void pop()
{
struct node *temp;
temp=top;
if(top t==0)
printf("under flow")
{
else
}
printf("top element is %d".top->data);
top=top->next
free(temp);
}
}
