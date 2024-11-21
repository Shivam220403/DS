#include<stdio.h>
#include<stdlib.h>
//Node 
struct Node{
    int data;
    struct Node* next;
};
//Traverse Through List
void PrintList(struct Node* head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
//Insert at Beginning
void Insert_at_start(struct Node** head,int info){
    struct Node *new;
    new  = (struct Node*)malloc(sizeof(struct Node));
    new->data = info;
    new->next = *head;
    *head = new;
}

// Insert at End
void Insert_at_End(struct Node** head, int info){
    struct Node *ptr,*new;
    new = (struct Node*)malloc(sizeof(struct Node));
    new->data = info;
    new->next = NULL;
    ptr = *head;
    if (ptr!=NULL){
        while (ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }else{
        *head = new;
    }
}
//Insert after a Node
void Insert_after_Node(struct Node** head,int info,int x){
    struct Node *ptr,*new;
    new = (struct Node*)malloc(sizeof(struct Node));
    new->data= info;
    ptr = *head;
    while(ptr->data!=x && ptr!=NULL){
        ptr=ptr->next;
    }
    if(ptr->data==x){
        new->next = ptr->next;
        ptr->next=new;
    }
}

//Delete at Beginning 
void Delete_at_beginning(struct Node** head){
    struct Node *ptr;
    if(head == NULL){
        printf("Empty List");
        return ;
    }else{
        ptr = *head;
        *head = ptr->next;
        free(ptr);
    }
}
//Delete at End
void Delete_at_End(struct Node** head) {
    struct Node *ptr = *head, *prep = NULL;
    if (*head == NULL) {
        printf("Empty List\n");
        return;
    } else if (ptr->next == NULL) {
        free(ptr);
        *head = NULL;
    } else {
        while (ptr->next != NULL) {
            prep = ptr;
            ptr = ptr->next;
        }
        prep->next = NULL;
        free(ptr);
    }
}
//Delete after a Node
void Delete_after_Node(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Empty List.\n");
        return;
    }
    struct Node* ptr = *head;

    while (ptr != NULL && ptr->data != value) {
        ptr = ptr->next;
    }
    if (ptr == NULL || ptr->next == NULL) {
        printf("No node exists after the node with value %d.\n", value);
        return;
    }
    struct Node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}
//Reverse List
void ReverseList(struct Node** head){
    struct Node* prev = NULL,*next = NULL;
    struct Node* ptr = *head;
    while(ptr != NULL){
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    *head = prev;
}



int main(){
    struct Node List1;
    struct Node* head = &List1;
    List1.data = 20;
    List1.next = NULL;
    Insert_at_start(&head,10);
    Insert_at_End(&head,30);
    Insert_after_Node(&head,35,30);
    Insert_at_End(&head,40);
    PrintList(head);
    Delete_at_beginning(&head);
    PrintList(head);
    Delete_at_End(&head);
    PrintList(head);
    Insert_at_start(&head,100);
    Delete_after_Node(&head,30);
    PrintList(head);
    return 0;
}