#include <stdio.h>
#include <stdlib.h>

//?THE BEST Linked List Insertion code.

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
        i++;
    }
    printf("NULL\n");
}

struct node *insertAtStart(struct node *head, int newData)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newData;
    ptr->next = head;
    return ptr; // New head
}

struct node *insertAtEnd(struct node *head, int newData)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = newData;
    ptr->next = NULL;
    return head;
}

struct node *insertAtIndex(struct node *head, int newData, int index)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    p = head;

    if (index == 0) // == Inserting element at start
    {
        head = insertAtStart(head, newData);
        return head;
    }

    while (i != index - 1)
    {
        p = p->next;
        i++; // Since this is liniear linked list
        if (p == NULL) // if index > size of linked list
        {
            int newIndex;
            printf("\n* Enter valid index *\nNew index : ");
            scanf("%d", &newIndex);
            head = insertAtIndex(head, newData, newIndex);
            printf("Element successfully inserted at new index\n");
            return head;
        }
    }

    ptr->next = p->next;
    p->next = ptr;
    ptr->data = newData;
    return head;
}

struct node *deleteFirstNode(struct node *head) {
    struct node * ptr = head;
    free(ptr);
    head = head->next;
    return head;
}

struct node *deleteLastNode(struct node *head) {
    struct node * p = head;
    struct node * q = p->next;

    while(q->next != NULL) {
        q = q->next;
    }
    q->next = NULL;
    free(p);
    return head;
}

void manue() {
    printf("\t0) Exit\n\t1) Insert at Start\n\t2) Insert at Index\n\t3) Insert at End\n\t4) Display\n");
    printf("\t4) Delete First Node\n\t5) Delete Node at Index\n\t6) Delete Last node\n\t7) Delete using Value\n");
    printf("\t9) Display Linked List\t");
}
//!Insert After Node is not availbe when you are using user scanned inputs.

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    head->data = NULL;


    //Manue for choosing method
    manue();

    int choise;
    int data, index;

    while (choise != 0)
    {
        printf("\n---> ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 0:
            choise = 0;
            break;
        case 1:
            printf("Enter element : ");
            scanf("%d", &data);
            head = insertAtStart(head, data);
            break;
        case 2:
            printf("Enter index   : ");
            scanf("%d", &index);
            printf("Enter element : ");
            scanf("%d", &data);
            head = insertAtIndex(head, data, index);
            break;
        case 3:
            printf("Enter element : ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;
        case 4:
            head = deleteFirstNode(head);
            break;
        // case 5:
        //     deleteAtIndex(head);
        //     break;
        case 6:
            head = deleteLastNode(head);
            break;
        // case 7:
        //     deleteUsingValue(head);
        //     break;
        case 9:
            display(head);
            break;
        default:
            printf("\n* Enter valid choise *");
            break;
        }
    }
    return 0;
}