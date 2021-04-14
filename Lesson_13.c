#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define n 6


int visitedDepth[n] = {0};

typedef struct Node{
    int dat;
    struct Node *next;
}Node ;

typedef struct{
 Node *head;
 int size;
} Stack;


void StackInit(Stack *stack){
    stack->head = NULL;
    stack->size = 0;
}


bool push(Stack *stack, int val){
    Node *tmp = (Node*)malloc(sizeof (Node));
    if (tmp == NULL){
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = val;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
}


int pop(Stack * stack){
    if (stack->size == 0){
        printf("Stack is empty /n");
        return false;
    }
    Node *tmp = stack->head;
    int data = stack->head->dat;
    stack->head = stack->head->next;
    stack->size--;
    return data;
}

void depthTraversStack(int **matrix, Stack *stack, int st) {
    int r;
    printf("%d ", st);

    visitedDepth[st] = 1;

    for (r = 0; r < n; ++r){

        if (matrix[st][r] == 1 && !visitedDepth[r]) {
            push(stack,r);
            depthTraversStack(matrix,stack,r);
        }


    }
}
void depthTraversStackPop(int **matrix,Stack *stack, int st) {

    int r;
    printf("%d ", st);

    visitedDepth[st] = 1;

    for (r = 0; r < n; ++r){

    if (matrix[st][r] == 1 && visitedDepth[r] == 1 && r < n) {

                   if (matrix[st][r] == 1 && !visitedDepth[r]) {
                     depthTraversStack(matrix,stack,r);

               }else if (r+1 == n){
                     depthTraversStackPop(matrix,stack,pop(stack));
                 }
      } else if(matrix[st][r] == 1 && visitedDepth[r]!=1){
     depthTraversStack(matrix,stack,r);
      }

    if (stack->head->next == NULL)
    return;
    else
        depthTraversStack(matrix,stack,r);

    }
    }



void depthTravers(int **matrix, int st) {
    int r;
    int sumLink =  0;


    visitedDepth[st] = 1;

    for (int i = 0; i < n; i++){
        if (matrix[i][st] == 1)
         sumLink++;
    }
    printf("\n");
    printf ("%d(%d Link)", st, sumLink);


    for (r = 0; r < n; ++r){

        if (matrix[st][r] == 1 && !visitedDepth[r]) {
            depthTravers(matrix,r);
        }
    }
}

void resetArr() {
    for (int i = 0; i < n; ++i) {
        visitedDepth[i] = 0;
    }
}

int **ArrayInit(){
    int **Arr =(int** ) malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        Arr[i] = (int*)malloc(n*sizeof(int));
    }
    return Arr;
}

void Array (int **Arr){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Arr[i][j] = rand()% 2;
            printf("%2d",Arr[i][j]);
        }
        printf("\n");
    }
}


void FreeArray (int **Arr){
    for (int i = 0; i < n; i++){
        free(Arr[i]);
    }
    free(Arr);
}


void main(const int arc, const char **argv) {
    srand(time(NULL));
    int **Arr = ArrayInit();
    Array(Arr);

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    StackInit(stack);

    //Task 13.1
    printf("\n");
    depthTraversStack(Arr,stack,0);
    printf("\n");
    depthTraversStackPop(Arr,stack,pop(stack));
    resetArr();

    //Task 13.3
    depthTravers(Arr, 2);
    resetArr();


    FreeArray(Arr);
}

