#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node; 
//Traverse Through List
void printCircularList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* ptr = head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
//Insert at Beginning
void Insert_at_beginning(Node** head, int info) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = info;
    if (*head == NULL) {
        new->next = new;
        *head = new;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        new->next = *head;
        current->next = new;
        *head = new;
    }
}
//Insert at End
void Insert_at_end(Node** head, int info) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = info;
    if (*head == NULL) {
        new->next = new;
        *head = new;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = new;
        new->next = *head;
    }
}

//Delete at Beginning
void Delete_at_beginning(Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = temp->next;
        *head = temp->next;
        free(temp);
    }
}
//Delete at End
void Delete_at_end(Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* current = *head;
    if (current->next == *head) {
        free(current);
        *head = NULL;
    } else {
        Node* prev = NULL;
        while (current->next != *head) {
            prev = current;
            current = current->next;
        }
        prev->next = *head;
        free(current);
    }
}
//Delete after a Node
void Delete_after_Node(Node** head, int value) {
    if (*head == NULL) {
        printf("Empty List.\n");
        return;
    }
    struct Node* ptr = *head;
    while (ptr->next != *head  && ptr->data != value) {
        ptr = ptr->next;
    }
    Node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}





int main(){
    Node list1;
    Node* head = &list1;
    list1.data = 20;
    list1.next = head;
    printCircularList(head);
    Insert_at_beginning(&head,10);
    printCircularList(head);
    Insert_at_end(&head,30);
    printCircularList(head);
    Delete_at_beginning(&head);
    printCircularList(head);
    Delete_at_end(&head);
    printCircularList(head);
    return 0;
}