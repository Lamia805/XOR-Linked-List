#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<windows.h>
#include<time.h>
time_t t;
struct linked
{
int data;
struct linked *XorNode;
};
typedef struct linked node;
node *XOR(node *a,node *b) // It returns Xored value of the node

{
node *address; //a temporary pointer for store Xor node value address store
address=(node *)((uintptr_t )(a)^(uintptr_t)(b));//uintptr_t is anunsigned integer type that is capable of storing a data pointer.
return(address);
}
node *insert(node **head,int no)
{
int data;
for(int i=0; i<no; i++)
{
printf("\t\t\t\t\tEnter the data position [%d] :> ",i+1);
scanf("%d",&data);
node *NewNode;
NewNode=(node *)malloc(sizeof(node));
NewNode->data=data; //in new node store the data
NewNode->XorNode=XOR(*head,NULL);
if(*head!=NULL)
{
node *next=XOR((*head)->XorNode,NULL); // If we Xor Null with next we get next
(*head)->XorNode=XOR(NewNode,next);
}
*head=NewNode;
}
printf("\t\t\t\t__________________________________________________\n");
printf("\t\t\t\t\t Successfully Data Entered.");
printf("\n\t\t\t\t---------------$$$$$$$$$----------------\n");
printf("\t\t\t\tEnter any key to go to menu!!");
getch();
node *curr=*head;
node *prev=NULL;

node *next;
while(curr!=NULL) // get address of next node: curr->xnode is
// next^previous, so current->xnode^prev will be
// next^prev^prev which is next
{
next=XOR(prev,curr->XorNode);
prev=curr; // update previous and current for next iteration
curr=next; //update current pointer
}
return(prev);
}
node *AddElementBeganning(node **head)
{
printf("\t\t__________________________________________________________________");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||\n");
printf("\t\t||\t Add Element at beginning X-OR Linked List.\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
if(*head==NULL)
{
printf("No data found enter data First\n");
return(*head);
}
int i;
node *NewNode,*next;
printf("\t\t \t\t\tEnter the data : ");
scanf("%d",&i);
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
NewNode=(node *)malloc(sizeof(node));
NewNode->data=i;
next=XOR((*head)->XorNode,NULL); //In next we store XOr head DATA and NULL
(*head)->XorNode=XOR(NewNode,next); //we send New_node and next pointer in XOR
NewNode->XorNode=XOR(*head,NULL);
*head=NewNode;
printf("\t\t|| \t\t Data %d added at beginning.\t\t\t||",i);
printf("\n\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t||______________________________________________________________||");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||");
printf("\n\t\t\t**Enter any key to go to menu:**");
getch();

return(*head);
}
node *AddElementAtEnd(node **head)
{
printf("\t\t__________________________________________________________________");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||\n");
printf("\t\t||\t Add Element at End X-OR Linked List.\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
if(*head==NULL)
{
printf("No data found enter data first.\n");
return(*head);
}
int i;
node *NewNode,*next,*curr,*prev;
printf("\t\t \t\t\tEnter the data : ");
scanf("%d",&i); // insert a value
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
NewNode=(node *)malloc(sizeof(node)); //for insert a new data memory allocation
NewNode->data=i; //Store i in New_node pointer
curr=*head;
prev=NULL;
while(curr!=NULL)
{
next=XOR(prev,curr->XorNode); //call XOR function and send previous node and current node data
prev=curr; //update previous node
curr=next; //update previous next
}
next=XOR(prev->XorNode,NULL); //Update next node and send previous xor node and null in XOr function
prev->XorNode=XOR(next,NewNode); //update previous node
NewNode->XorNode=XOR(prev,NULL); // store new node to at end
printf("\t\t|| \t\t\t Data %d added at End.\t\t\t||",i);
printf("\n\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t||______________________________________________________________||");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||");
printf("\n\t\t\t**Enter any key to go to menu:**");
getch();
return(*head);
}
node *DeleteElementBeganning(node **head)

{
printf("\t\t__________________________________________________________________");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||\n");
printf("\t\t||\t Delete first Element from List.\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
if(*head==NULL)
{
printf("No data found enter data first.\n");
return(*head);
}
else
{
node *ptr,*addrs,*next; //some temporary Pointer
ptr=*head; // store head in ptr
addrs=XOR(ptr->XorNode,NULL); //in address pointer we store ptr data and NUll
next=XOR(addrs->XorNode,*head); //In next pointer we send in XOR function (address->xornode data and head pointer)
addrs->XorNode=XOR(next,NULL);
*head=addrs; //Update head
printf("\t\t||\tYour Element have been deleted From Beginning: %d\t||",*ptr);
free(ptr);
}
printf("\n\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t||______________________________________________________________||");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||");
printf("\n\t\t\t**Enter any key to go to menu:**");
getch ();
system("cls");
return(*head);
}
node *DeleteElementEnd(node **head)
{
if(*head==NULL)
{
printf("No data found enter data First\n");
return(*head);
}
node *curr,*prev,*next;
curr=*head; //store head in current
prev=NULL;
printf("\t\t__________________________________________________________________");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||\n");

printf("\t\t||\t Delete first Element from List.\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
while(curr!=NULL)
{
next=XOR(prev,curr->XorNode); //send previous pointer and current xornode in XOR function for update.
prev=curr; //update previous pointer
curr=next; //update current pointer
}
next=XOR(prev->XorNode,NULL); // send in XOR previous xor node data and NUll and store in next pointer
curr=XOR(next->XorNode,prev); //send in XOR next node xor data and Previous node pointer and store in current position
next->XorNode=XOR(curr,NULL); // Send in xor function Current pointer and Null and store next xor node data
printf("\t\t||\tYour Element have been deleted From Ending:%d\t\t||",*prev);
free(prev);
printf("\n\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t||______________________________________________________________||");
printf("\n\t\t||.----------------------&&&&&&&&&&&&&&&&------------------------||");
printf("\n\t\t\t**Enter any key to go to menu:**");
getch ();
system("cls");
return(*head);
}
void DisplayXorList(node *addr)
{
printf("\t\t__________________________________________________________________");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||\n");
printf("\t\t||\t\t Display X-OR Linked List.\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
if(addr==NULL)
{
printf("\t\t||No data found enter data First.\t\t||\n");
return;
}
node *curr=addr; //store address in new pointer its Current
node *prev=NULL; //Store previous pointer = NUll
node *next;
printf("\t\t||\t\tThis are the nodes Data of linked list: \t||");
printf("\n\t\t||\t\t\tData are: ");
while(curr!=NULL) //Before Current pointer not equal it's check
{
printf("%d ",curr->data); //print the current pointer data

next=XOR(prev,curr->XorNode); //store in next previous pointer address and current pointer data
prev=curr;
curr=next;
}
printf("\t\t\t||");
printf("\n\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t||______________________________________________________________||");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||");
printf("\n\t\t\t**Enter any key to go to menu:**");
getch();

}

int main()
{
node *head=NULL; //initially it's null
int num,no,ii;
while(1)
{
system("COLOR 5F");
system("cls");
time(&t);
printf("\n%65s\n\n\n",ctime(&t));
printf("\n\t\t\t\t\t*********************\n");
printf("\t\t\t\t\tWELCOME TO TASK MENU\n");
printf("\t\t\t\t\t---------------------\n");
printf("\t\t__________________________________________________________________");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t||\t\tPress [1] for Insert Data in Node \t\t||\n");
printf("\t\t||\t\tPress [2] for print the data\t\t\t||\n");
printf("\t\t||\t\tPress [3] for Adding element in beginning\t||\n");
printf("\t\t||\t\tPress [4] for Adding element in end\t\t||\n");
printf("\t\t||\t\tPress [5] for Deleting element in beginning\t||\n");
printf("\t\t||\t\tPress [6] for Deleting element in end\t\t||\n");
printf("\t\t||\t\tPress [7] for Exit\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||\n");
printf("\t\t|| \t\t\t\t\t\t\t\t||");

printf("\n\t\t||______________________________________________________________||");
printf("\n\t\t||----------------------&&&&&&&&&&&&&&&&------------------------||\n");
printf("\t\t\tEnter Your Choice:");
scanf("%d",&num);
switch(num)
{
case 1 :
system("cls");
system("COLOR 8F");
time(&t);
printf("\n%65s\n\n\n",ctime(&t));
printf("\n\t\t\t\t\t*********************\n");
printf("\t\t\t\t\t Insert Menu\n");
printf("\t\t\t\t\t---------------------\n\n");
printf("\t\t\t\t\tHow much data you Insert:");
scanf("%d",&no);
printf("\t\t\t\t\t-------------------------\n\n");
head=insert(&head,no);
break;
case 2 :
system("cls");
time(&t);
printf("\n%65s\n\n\n",ctime(&t));
system("COLOR 4F ");
DisplayXorList(head);
break;
case 3 :
system("cls");
time(&t);
printf("\n%65s\n\n\n",ctime(&t));
system("COLOR B8");
head=AddElementBeganning(&head);
break;
case 4 :
system("cls");
time(&t);
printf("\n%65s\n\n\n",ctime(&t));
system("COLOR 2f");
head=AddElementAtEnd(&head);
break;
case 5 :
system("cls");
time(&t);
printf("\n%65s\n\n\n",ctime(&t));
system("COLOR 6E");
head=DeleteElementBeganning(&head);
break;
case 6 :
system("cls");
time(&t);
printf("\n%65s\n\n\n",ctime(&t));
system("COLOR F6");
head=DeleteElementEnd(&head);
break;

case 7:
system("cls");
time(&t);
printf("\n%65s\n\n\n",ctime(&t));
system("COLOR E2");
printf("\n\t\t\t\t\t*********************\n");
printf("\t\t\tThanks a lot Ma'am for making the data structure so much easier\n");
printf("\t\t\t\t\t---------------------\n");
exit(0);

}
}
}

