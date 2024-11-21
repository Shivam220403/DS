#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
//Traversal
void PrintList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* ptr = head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
//Insertion at Beginng
void Insert_at_Beginning(Node** head, int info) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = info;
    if (*head == NULL) {
        new->next = new;
        new->prev = new;
        *head = new;
    } else {
        Node* tail = (*head)->prev;
        new->next = *head;
        new->prev = tail;
        tail->next = new;
        (*head)->prev = new;
        *head = new;
    }
}
//Insertion at End
void Insert_at_End(Node** head, int info) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = info;
    if (*head == NULL) {
        new->next = new;
        new->prev = new;
        *head = new;
    } else {
        Node* tail = (*head)->prev;
        new->next = *head;
        new->prev = tail;
        tail->next = new;
        (*head)->prev = new;
    }
}
//Insertion after a Node
void Insert_after_Node(Node** head, int info, int value) {
    if (*head == NULL) return;
    Node* ptr = *head;
    do {
        if (ptr->data == value) {
            Node* new = (Node*)malloc(sizeof(Node));
            new->data = info;
            new->next = ptr->next;
            new->prev = ptr;
            ptr->next->prev = new;
            ptr->next = new;
            return;
        }
        ptr = ptr->next;
    } while (ptr != *head);
    
    printf("Node with value %d not found.\n", value);
}
//Deletion at Beginning
void Delete_at_Beginning(Node** head) {
    if (*head == NULL) {
        printf("Empty List.\n");
        return;
    }
    Node* tail = (*head)->prev;
    Node* temp = *head;
    
    if (*head == (*head)->next) {
        *head = NULL;
    } else {
        tail->next = (*head)->next;
        (*head)->next->prev = tail;
        *head = (*head)->next;
    }
    free(temp);
}
//Deletion at End
void Delete_at_End(Node** head) {
    if (*head == NULL) {
        printf("Empty List.\n");
        return;
    }
    Node* tail = (*head)->prev;
    if (*head == tail) {
        free(tail);
        *head = NULL;
    } else {
        tail->prev->next = *head;
        (*head)->prev = tail->prev;
        free(tail);
    }
}
//Deletion after a Node
void Delete_after_Node(Node** head, int value) {
    if (*head == NULL) return;
    Node* ptr = *head;
    do {
        if (ptr->data == value) {
            Node* temp = ptr->next;
            if (temp == *head) {
                printf("No node exists after the node with value %d.\n", value);
                return;
            }
            ptr->next = temp->next;
            temp->next->prev = ptr;
            free(temp);
            return;
        }
        ptr = ptr->next;
    } while (ptr != *head);
    printf("Node with value %d not found.\n", value);
}
int main(){
    Node list;
    list.data = 20;
    list.prev = &list;
    list.next = &list;
    Node* head = &list;
    PrintList(head);
    Insert_at_Beginning(&head,10);
    Insert_at_End(&head,40);
    Insert_after_Node(&head,30,20);
    PrintList(head);
    Delete_at_Beginning(&head);
    Delete_at_End(&head);
    Delete_after_Node(&head,20);
    PrintList(head);
    return 0;
}