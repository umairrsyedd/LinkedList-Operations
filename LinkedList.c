
/* Program To Perform All Operations On A Singly-Linked List!
   
   This Code Was Written By Syed Muhammed Umair Of Presidency University Bangalore. 
   If Anyone Requires Help In Interpreting The Code, I Would Be Pleased To Help!
   You Can Get In Touch With Me at https://github.com/umairrsyedd */

------------------------------------------------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct nodes
{
    int data;
    struct nodes* next;
};
typedef struct nodes* node;
node InsertFront(node head)
{
    node temp=malloc(sizeof(node));
    printf("Enter The Value Of Node\n");
    scanf("%d",&temp->data);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    return(head);
}
node InsertBack(node head)
{
    node temp=malloc(sizeof(node));
    node newnode=malloc(sizeof(node));
    printf("Enter The Value Of Node\n");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
    return(head);
}
node InsertPosition(node head)
{
    node previousnode,nextnode,temp;
    node newnode=malloc(sizeof(node));
    int position,count=1;
    printf("Enter the Position At Which New Node Has To Be Inserted\n");
    scanf("%d",&position);
    printf("Enter The Value Of Node\n");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL && count<position)
        {
            previousnode=temp;
            nextnode=temp->next;
            count=count+1;
            temp=temp->next;
        }
        if(position<=count)
        {
            previousnode->next=newnode;
            newnode->next=nextnode;
        }
        else
        {
            printf("Invalid Position Given\n");
        }
        return(head);
    }
}
node DeleteFront(node head)
{
    node temp;
    if(head==NULL)
    {
        printf("Linked List Is Empty Nothing To Delete\n");
    }
    else
    {
        temp=head->next;
        head=NULL;
        head=temp;
    }
    return(head);
}
node DeleteBack(node head)
{
    node temp;
    if(head==NULL)
    {
        printf("Linked List Is Empty Nothing To Delete\n");
    }
    else
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    return(head);
}
node DeletePosition(node head)
{
    int pos,count=1;
    node prevnode,deletenode,nextnode,temp;
    if(head==NULL)
    {
        printf("Linked List Is Empty Nothing To Delete");
    }
    else
    {
        printf("Enter Postition To Be Deleted\n");
        scanf("%d",&pos);
        temp=head;
        while(temp->next!=NULL && count!=pos)
        {
            prevnode=temp;
            nextnode=temp->next->next;
            deletenode=temp->next;
            count=count+1;
            temp=temp->next;
        }
        prevnode->next=nextnode;
        deletenode=NULL;
    }
    return(head);
}
void Search(node head)
{
    int element,count=1;
    bool found=false;
    node temp;
    printf("Enter The Element To Be Searched In The Linked List\n");
    scanf("%d",&element);
    \
    if(head==NULL)
    {
        printf("Linked List Seems To Be Empty, Nothing To Search\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(temp->data==element)
            {
                printf("Element Found At Position %d In The Linked List\n",count);
                temp=temp->next;
                count=count+1;
                found=true;
            }
            else
            {
                temp=temp->next;
                count=count+1;
            }
        }
        if(found==false)
        {
            printf("Element Not Found In The Linked List");
        }
    }
}

node Reverse(node head)
{
    node temp,prevnode=NULL;
    node nextnode;
    temp=head;
    while(temp!=NULL)
    {   
        nextnode=temp->next;
        temp->next=prevnode;
        prevnode=temp;
        temp=nextnode;
    }
    head=prevnode;
    return(head);
}
void Display(node head)
{
    node temp=malloc(sizeof(node));
    if(head==NULL)
    {
        printf("Linked List Seems To Be Empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    node head=malloc(sizeof(node));
    head=NULL;
    int choice;
    for(;;)
    {
        printf("\nLINKED LIST OPERATIONS\n\n");
        printf("Select An Option\n1 - Insert From Front\t      2 - Insert From Back\n3 - Insert At A Position      4 - Delete At The Front\n5 - Delete At The Back\t      6 - Delete At A Position\n7 - Display\t\t      8 - Search For An Element\n9 - Reverse The Linked List   10 - Exit\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case(1) :
            {
                head=InsertFront(head);
                break;
            }
            case(2) :
            {
                head=InsertBack(head);
                break;
            }
            case(3) :
            {
                head=InsertPosition(head);
                break;
            }
            case(4) :
            {
                head=DeleteFront(head);
                break;
            }
            case(5) :
            {
                head=DeleteBack(head);
                break;
            }
            case(6) :
            {
                head=DeletePosition(head);
                break;
            }
            case(7) :
            {
                Display(head);
                break;
            }
            case(8) :
            {
                Search(head);
                break;
            }
            case(9) :
            {
                head=Reverse(head);
                break;
            }
            case(10) :
            {
                exit(0);
                break;
            }
            default :
            {
                printf("Invalid Input\n");
                exit(0);
            }
        }
    }
}
