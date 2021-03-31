#include <stdio.h>
#include <stdlib.h>


#define true 1==1
#define false 1!=1
#define T char
#define SIZE 10

typedef int boollean;

typedef struct Node{
    int dat;
    struct Node *next;
} Node;

typedef struct{
    Node *head;
    int size;
} OneLinkList;

typedef struct{
    Node *head;
    int size;
} Stack;

void init(OneLinkList *lst)
{
    lst->head = NULL;
    lst->size = 0;
}


void ins(OneLinkList *lst, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->dat = data;
    new->next = NULL;

    Node *current = lst->head;
    if (current == NULL)
    {
        lst->head = new;
        lst->size++;
        return;
    }else{
        while (current->next != NULL)
            current = current->next;
        current->next = new;
        lst->size++;
    }
}

Node *rm(OneLinkList *lst, int data)
{
    Node *current = lst->head;
    Node *parent = NULL;
    if (current == NULL)
        return NULL;

    while (current->next != NULL && current->dat != data){
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
        return NULL;
    if (current == lst->head){
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printNode(Node *n)
{
    if (n == NULL){
        printf("[]");
        return;
    }
    printf("[%d] ", n->dat);
}

void printList(OneLinkList *lst)
{
    Node *current = lst->head;
    if (current == NULL)
        printNode(current);
    else{
        do{
            printNode(current);
            current = current->next;
        }while (current != NULL);
    }
    printf(" Size: %d\n", lst->size);
}



//Task 2
void CopyList(OneLinkList *from, OneLinkList *to){

  Node *OldList = from->head;
  Node *NewList = to->head;

  while (OldList->next != NULL){
      int data = OldList->dat;
      OldList = OldList->next;
      NewList = OldList;
      ins(to, data);
  }
  if (OldList->next == NULL){
      ins(to, OldList->dat);
  }
}


//Task 3
boollean CheckSortList (OneLinkList * lst){
    int data;
    int tmp;
    Node * current = lst->head;
    if (current == NULL){
        printf ("List is empty");
        return false;
    }

    while (current->next != NULL ){

         int data = current->dat;
         current = current->next;

         if (data > tmp){
            tmp = data;
         }else if (data < tmp){
            printf("\nNo sorty");
            return false;
         }
         if (current->next == NULL){
             if (data > tmp){
                tmp = data;
             }else if (data < tmp){
                printf("\nNo sorty");
                return false;
             }
         }

    }


      return true;
}
//Task 1
boollean push(Stack *stack, T value){
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (tmp == NULL)
    {
        printf("Stack overflow\n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack){
    if (stack->size == 0)	{
        printf("Stack is empty\n");
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    stack->size--;
    free(tmp);
    return data;
}

void printStack(Stack *stack){
    Node *current = stack->head;
    if (current == NULL)
        printNode(current);
    else{
        do{
            printNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d\n", stack->size);
}

boollean CheckSeqence(char *arr, Stack *stack){

     Node *number = (Node *)malloc(sizeof(Node));

     for(int i = 0; i < SIZE+1; i++){
        if(arr[i]=='(' || arr[i] == '{'){
            push(stack,arr[i]);
        }else{
            if(arr[i] == ')'){
                pop(stack);
            }else{
                if(arr[i] == '}'){
                    pop(stack);
            } else if ((arr[i] == '}' || arr[i] == ')') && number->next == 0) {
                push(stack,arr[i]);
                CheckSeqence(arr, stack);
            }
        }
    }
}
    if(stack->size == 0){
        return true;
    }else{
       return false;
    }

}
int main(const int arc, const char **argv){

    //Task1
    Stack *st = (Stack *)malloc(sizeof(Stack));

    printf("Enter seqence\n ");
    init(st);
    char *arr  = (char *)malloc(SIZE * sizeof(char));
    for (int i = 0; i < SIZE; i++){
        scanf("%s", &arr[i]);
    }
    if (CheckSeqence(arr, st) == true){
        printf("Seqence - true");
    }else
        printf("Seqence - false");
    printStack(st);


    OneLinkList *from = (OneLinkList *)malloc(sizeof(OneLinkList));
    OneLinkList *to = (OneLinkList *)malloc(sizeof(OneLinkList));

    init(from);
    init(to);
    printList(from);
    ins(from, 1);
    printList(from);
    ins(from, 2);
    printList(from);
    ins(from, 3);
    printList(from);
    ins(from, 5);
    printList(from);
    ins(from, 6);
    printList(from);

    printf("\nTask 2\n");

    CopyList(from, to);
    printList(to);
    printNode(rm(to, 1)); printf("<- removed node\n");
    printList(to);
    printf("\nTask 3\n");

    if (CheckSortList(to) == 1){
        printf("True");
    }else {
        printf("false");
        }

    return 0;
}
