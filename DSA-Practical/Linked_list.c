#include <stdio.h>
#include <stdlib.h>

struct list{
    int value;
    struct list *next;
};

int ListLength(struct list *head){
    struct list *current = head;
    int count = 0;

    while(current!=NULL){
        count++;
        current = current->next;
    }
    return count;
}

void PrintList(struct list *head){
    struct list *current = head;
    printf("List Elements :\n");
    while(current!=NULL){
        printf("%d\n",current->value);
        current=current->next;
    }
}

void Insert(struct list **head, int data, int position) {
    int k = 0;
    struct list *q, *newNode;
    newNode = (struct list *)malloc(sizeof(struct list));
    if (!newNode) {
        printf("Memory Error\n");
        return;
    }
    newNode->value = data;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        q = *head;
        while (q != NULL && k < position - 1) {
            q = q->next;
            k++;
        }
        if (q == NULL) {
            printf("Position does not exist\n");
            free(newNode);
            return;
        }
        newNode->next = q->next;
        q->next = newNode;
    }
}

/*void Delete(struct list **head,int position){
    int k=1;
    struct list *q,*w;
    if(*head==NULL){
        printf("Empty List");
        return;
    }
    q=*head;
    if(position==1){
        *head=(*head)->p;
        free(q);
        return;
    }else{
        while((q!=NULL) && (k<position)){
            k++;
            w=q;
            q=q->p;
        }
        if(q==NULL){
            printf("Position Does not exist");
        }else{
            w->p = q->p;
            free(q);
        }
    }
}*/

void Delete(struct list **head, int position) {
    int k = 1;
    struct list *q, *w;
    if (*head == NULL) {
        printf("Empty List\n");
        return;
    }
    q = *head;
    if (position == 1) {
        *head = (*head)->next;
        free(q); 
        return;
    } else {
        while (q != NULL && k < position - 1) {
            k++;
            w = q;
            q = q->next;
        }
        if (q == NULL || q->next == NULL) {
            printf("Position Does not exist\n");
        } else {
            w->next = q->next;
            free(q);
        }
    }
}

int main(){
    struct list item1,item2,item3;
    struct list *head;

    item1.value=1;
    item2.value=2;
    item3.value=3;

    head = &item1;
    item1.next=&item2;
    item2.next=&item3;
    item3.next=NULL;

    int length = ListLength(head);
    printf("List length: %d\n",length);
    PrintList(head);

    Insert(&head,4,3);
    PrintList(head);

    Delete(&head,2);
    PrintList(head);
    return 0;
}