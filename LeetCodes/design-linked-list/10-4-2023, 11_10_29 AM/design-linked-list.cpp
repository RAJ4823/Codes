// Link: https://leetcode.com/problems/design-linked-list

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-linked-list
 *  RUNTIME: 32 ms
 *  MEMORY: 20.1 MB
 *  DATE: 10-4-2023, 11:10:29 AM
 *
 */

// Solution:

class Node{
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
    MyLinkedList() {}
    
    int get(int index) {
        if(index >= size) return -1;

        Node* ptr = head;
        for(int i=0; i < index; i++)
            ptr = ptr->next;
        return ptr->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if(size == 0) {
            tail = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        if(size == 0) {
            addAtHead(val);
            return;
        }
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void deleteHead() {
        Node* ptr = head;
        head = head->next;
        ptr = NULL;
    }

    void deleteTail(int index) {
        if(index == 0) {
            head = NULL;
            tail = NULL;
        } else {
            Node* ptr = head;
            while(ptr->next != tail) {
                ptr = ptr->next;
            }
            tail = ptr;
            ptr->next = NULL;
        }
    }    

    void addAtIndex(int index, int val) {
        if(index > size) return;
        else if(index == size) addAtTail(val);
        else if(index == 0)    addAtHead(val);
        else {
            Node* ptr = head;
            Node* newNode = new Node(val);
            for(int i=0; i<index-1; i++) {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        else if(index == size - 1) deleteTail(index);
        else if(index == 0)    deleteHead();
        else {
            Node* ptr = head;
            for(int i=0; i<index-1; i++) {
                ptr = ptr->next;
            }
            Node* del = ptr->next;
            ptr->next = ptr->next->next;
            del->next = NULL;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
