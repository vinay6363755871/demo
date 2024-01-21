#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void traverse(struct node *temp )
{
    
    while(temp!=NULL)
    {
    printf("%d",temp->data);
     temp=temp->next;
    }
};
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
    struct node *prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;

    }
    prev->next=NULL;
    free(temp);
    return head;
};
struct node *del_pos(struct node *head,int pos)
{
    struct node *temp=head;
    for(int i=0;i<pos-1;i++)
{
    temp=temp->next;
}
temp->next=temp->next->next;
return head;
}

struct node *lin_list()
{
struct node *head,*second,*third;
head=(struct node*)malloc(sizeof(struct node));
head->data=2;
head->next=NULL;
second=(struct node*)malloc(sizeof(struct node));
second->data=3;
head->next=second;
third=(struct node*)malloc(sizeof(struct node));
third->data=4;
second->next=third;
third->next=NULL;
return head;
};
int main()
{
    struct node *head=lin_list();
    traverse(head);
    printf("\n");
    printf("lin list after deleting the first node");

    head=del_beg(head);
    printf("\n");
    printf("deleting the last node\n");
    head=del_end(head);
    printf("deletion of nod ein the middle");
    head=del_pos(head,1);
    traverse(head);
    return 0;
}