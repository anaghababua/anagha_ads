#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*prev;
struct node*next;
};
struct node*head=NULL,*end=NULL;
static int size=0;
void insert_head(int data){
struct node*node;
node=(struct node*)malloc(sizeof(struct node));
node->data=data;
node->prev=NULL;
if(head!=NULL)
{
head->prev=node;
head=node;
}
else
{
head=node;
end=node;
}
size++;
}
void insert_end(int data){
struct node*node;
node=(struct node*)malloc(sizeof(struct node));
node->data=data;
node->prev=NULL;
if(end==NULL)
{
head=node;
end=node;
}
else{
node->prev=end;
end->next=node;
end=node;
}
size++;
}
void insert(int data,int pos){
int count=1;
struct node*node,*temp;
temp=head;
node=(struct node*)malloc(sizeof(struct node));
node->data=data;
do{
if(count==pos){
node->next=temp->next;
(temp->next)->prev=node;
node->prev=temp;
temp->next=node;
size++;
break;
}
else{
count++;
temp=temp->next;
}
}while(count<=pos);
}
void delete_head(){
struct node*temp;
if(head!=NULL){
printf("\n\t\tNode deleted:%d",head->data);
temp=head;
head=head->next;
if(head!=NULL)
head->prev=NULL;
else
end=NULL;
free(temp);
size--;
}
else
printf("\n\t\tLinked list is empty!!");
}
void delete_end(){
if(head==NULL)
printf("\t\tLinked list is empty!!");
else{
printf("\n\t\tNode deleted:%d",end->data);
struct node*temp,*nxt_temp;
temp=end;
end=end->prev;
if(end==NULL)
head=NULL;
else
end->next=NULL;
free(temp);
size--;
}
}
void delete(int pos){
int count=1;
struct node*temp,*next_temp;
temp=head;
next_temp=temp->next;
do{
if(count==pos){
temp->next=next_temp->next;
(next_temp->next)->prev=temp;
printf("\n\t\tNode deleted:%d",next_temp->data);
free(next_temp);
size--;
break;
}
else{
count++;
temp=next_temp;
next_temp=next_temp->next;
}
}while(count<=pos);
}
void display_forward(){
if(head==NULL)
printf("\n\t\tLinked list is empty!!");
else{
struct node*link=head;
printf("\t\t");
while(link->next!=NULL){
printf("%d",link->data);
link=link->next;
}
printf("%d\n",link->data);
}
}
void display_reverse(){
if(end==NULL)
printf("\n\t\tLinked list is empty!!");
else{
struct node*link=end;
printf("\t\t");
while(link->prev!=NULL){
printf("%d",link->data);
link=link->prev;
}
printf("%d\n",link->data);
}
}
void search(){
int count=1;
if(head==NULL)
printf("\n\t\tLinked list is empty!!");
else{
int data;
printf("enter the number you want to search:");
scanf("%d",&data);
struct node*link=head;
printf("\t\t");
do{
if(link->data==data){
printf("\\nt\t\tthe number is found in the linked list!!%d and postion is %d",link->data,count);
return;
}
count++;
link=link->next;}while(link !=NULL);
printf("\nt\tthe number is not found in the limked list!!");
}
}
int main(){
int ch,data,pos;
do{
printf("\nChoose:\n1.Insert head\n2.Insert end\n3.Insert at particular position\n4.Delete head\n5.Delete end\n6.Delete from particular position\n7.Display forward\n8.Display reverse\n9.Search\n10.end\n::");
scanf("%d",&ch);
switch(ch){
case 1:
printf("enter the data you need to store:");
scanf("%d",&data);
insert_head(data);
break;
case 2:
printf("enter the data you need to store:");
scanf("%d",&data);
insert_end(data);
break;
case 3:
printf("enter the data you need to store:");
scanf("%d",&data);
printf("enter the position where you need to store(head=0:end=%d):",size);
scanf("%d",&pos);
if(pos<0 || pos>size)
printf("\n\t\tinvalid postion!!");
else if(pos==0)
insert_head(data);
else if(pos==size)
insert_end(data);
else{
insert(data,pos);
}
break;
case 4:
delete_head();
break;
case 5:
delete_end();
break;
case 6:
printf("enter the postion where you need to delete from (head=0:end=%d):",size-1);
scanf("%d",&pos);
if(pos<0|| pos>size)
printf("\n\t\tinvalid postion!!");
else if(pos==0)
delete_head();
else if(pos==size-1)
delete_end();
else
delete(pos);
break;
case 7:
display_forward();
break;
case 8:
display_reverse();
break;
case 9:
search();
break;
case 10:
printf("\n\t\tthe program is successfully exiting!!");
break;
default:
printf("\n\t\twrong input!!");
}
}while(ch!=10);
return 0;
}
