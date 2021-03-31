#include <stdio.h>
#include <stdlib.h>

#define T int
#define SIZE 1000
#define true 1==1
#define false 1!= 1
#define divider 2

#define SZ 10

typedef int boolean;

int cursor = -1;
T Stack[SIZE];

boolean push(T data)
{
    if (cursor < SIZE)
    {
        Stack[++cursor] = data;
        return true;
    }
    else
    {
        printf("Stack overflow\n");
        return false;
    }
}

T pop()
{
    if (cursor != -1)
        return Stack[cursor--];
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

void taskTwo(){
    int number,answer;
    printf("Enter number :");
    scanf("%d", &number);
        do{
        answer = number % divider;
        push(answer);
        number = number/divider;
        }while(number>0);
        printf("\n");
        do{
            printf("%d",pop());
        }while(cursor!=-1);
}

//TASK 1
typedef struct
{
    int pr;
    int dat;
} Node;

Node *arr[SZ];
int head;
int tail;
int items;

void init()
{
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items == 0)
    {
        arr[tail++] = node;
        items++;
    }
    else if (items == SZ)
    {
        printf("Queue is full");
        return;
    }
    else
    {
        if (items > 0){
            arr[tail++] = node;
            items++;
        }
    }
}

Node *rem()
{
    int flag;
    if (items == 0)
        return NULL;
    else
    {
        for (int i = head; i < tail; i++){
             int idx = i % SZ;
              int tmpPr = arr[idx]->pr;

             for (int j = head; j<tail;j++){
                 int tmpIdx = j % SZ;

                 if (tmpPr <= arr[tmpIdx]->pr){
                    tmpPr = arr[tmpIdx]->pr;
                    flag = j;
                 }

                 if (j == tail-1){
                     Node *tmp = arr[flag];
                     arr[flag] = NULL;
                     tail--;
                     do{
                         int dop = arr[flag];
                         arr[flag] = arr[flag+1];
                         arr[flag+1] = dop;
                         flag++;
                     }while(flag < tail);
                     items--;
                     return tmp;
               }
           }
       }
    }
}

void printQueue()
{
    printf("[ ");
    for (int i = 0; i < SZ; ++i)
    {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

void taskOne(){
    int n;
    init();
    ins(1, 11);
    ins(3, 22);
    ins(7, 33);
    ins(2, 44);
    ins(8, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(6, 100);

    printQueue();
    printf ("Remove frome the queue N iteams:");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        Node *n = rem();
        printf("pr = %d, dat = %d\n", n->pr, n->dat);
    }
    printQueue();
}

int main(const int argc, const char **argv)
{
    int n;
    do{
    printf("Enter number 1(Task 1)/2(Task 2):");
    scanf("%d",&n);
    }while(n != 1 && n !=2);

    if (n == 1){
        taskOne();
    }else if (n == 2)
        taskTwo();


    return 0;
}
