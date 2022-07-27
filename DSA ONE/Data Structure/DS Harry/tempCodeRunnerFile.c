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