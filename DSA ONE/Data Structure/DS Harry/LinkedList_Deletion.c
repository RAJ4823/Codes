#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
 
void display(struct node * ptr) {
    while(ptr!= NULL) {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct node * delete_first(struct node  * head) {
    struct node * p = head;
    head = head->next;
    free(p);

    return head;
}
struct node * delete_last(struct node * head) {
    struct node * p = head;
    struct node * q = head->next;

    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}
struct node * delete_index(struct node * head, int index) {
    struct node * p = head;
    struct node * q = head->next;
    
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}
struct node * delete_value(struct node * head, int value) {
    struct node * p = head;
    struct node * q = head->next;

    while(q->data!=value && q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    if(q->data == value) {
        p->next = q->next;
        free(q);
    }
    else {
        printf("There is no such value in Linked List\n");
    }

    return head;
}

int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * forth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));

    //Linking all structs
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = forth;
    forth->data = 40;
    forth->next = NULL;

    //Fun to show output
    display(head);

    //deleteing element at head
    // printf("\nDeletion at head : \n");
    // head = delete_first(head);
    // display(head);

    //deleteing element at last (END)
    // printf("\nDeletion at last : \n");
    // head = delete_last(head);
    // display(head);

    //deleteing element at given index
    // printf("\nDeletion at Index %d : \n",2);
    // head = delete_index(head, 2);
    // display(head);

    printf("\nDeletion with Value : (Value = 20)\n");
    head = delete_value(head,20);
    display(head);;

    return 0;
}