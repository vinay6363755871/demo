#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void traverse(struct node *ptr)
{
    //struct node *ptr=(struct node*)malloc(sizeof(struct node));
    
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
        
    }
    printf("\n");
};

struct node *del(struct node *head,int pos)
{
    struct node *temp=head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;

}
struct node *del_beg(struct node *head)
{
    struct node *temp=head;
    head=head->next;
    temp->next=NULL;
    return head;
};
struct node *del_end(struct node *head)
{
    struct node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

struct node *lin_list()
{
    struct node *head,*second,*third;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=2;
    head->next=second;
    third=(struct node *)malloc(sizeof(struct node));
    third->data=3;
    second->next=third;
    third->next=NULL;
    return head;
    
};
int main()
{
    struct node *head=lin_list();
    
    traverse(head);
    //printf("Deleting the node at the particular position"); 
    
   // head=del(head,1);
   // head=del_beg(head);
    head=del_end(head);
    traverse(head);
    return 0;
}