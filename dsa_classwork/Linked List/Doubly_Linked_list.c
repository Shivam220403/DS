#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
//Traversing a DLL
void PrintList(Node* head){
    Node* ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void Insert_at_Beginning(Node** head,int info){
    Node *new,*ptr = *head;
    new = (Node*)malloc(sizeof(Node));
    new->data = info;
    new->next = *head;
    new->prev = NULL;
    if (ptr!= NULL) {
        ptr->prev = new;
    }
    *head = new;
}

void Insert_at_End(Node** head,int info){
    Node *new,*ptr = *head;
    new = (Node*)malloc(sizeof(Node));
    new->data = info;
    new->next = NULL;
    if (*head == NULL) {
        new->prev = NULL;
        *head = new;
        return;
    }
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = new;
    new->prev=ptr;
}

void Insert_after_Node(Node** head,int info,int x){
    Node *new,*ptr = *head;
    new = (Node*)malloc(sizeof(Node));
    new->data = info;
    while(ptr->data!=x && ptr!=NULL){
        ptr=ptr->next;
    }
    if (ptr == NULL) {
        printf("Value %d not found in the list.\n", x);
        return;
    }
    new->next = ptr->next;
    new->prev = ptr;
    if(ptr->data==x){
        ptr->next->prev = new;
    }
    ptr->next = new;
}


//Delete at beginninng
void Delete_at_Beginning(Node** head) {
    if (*head == NULL) {
        printf("Empty List.\n");
        return;
    }
    Node* ptr = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(ptr);
}
// Delete at End
void Delete_at_End(Node** head) {
    if (*head == NULL) {
        printf("Empty List.\n");
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev == NULL) {
        *head = NULL;
    } else {
        temp->prev->next = NULL;
    }
    free(temp);
}
//Delete After a Node
void Delete_after_Node(Node** head, int value) {
    if (*head == NULL) {
        printf("Empty List.\n");
        return;
    }
    Node* ptr = *head;
    while (ptr != NULL && ptr->data != value) {
        ptr = ptr->next;
    }
    if (ptr == NULL || ptr->next == NULL) {
        printf("No node exists after the node with value %d.\n", value);
        return;
    }
    Node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}


int main(){
    Node list1;
    list1.data = 20;
    list1.prev = NULL;
    list1.next = NULL;
    Node* head = &list1;
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