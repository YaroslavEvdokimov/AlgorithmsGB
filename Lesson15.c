#include "geek.h"
#include "geek.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int K;
typedef int htIndex;

int htTable;
int SizeStr;
int KMAX;

int profitCalculation(int* money, const int size) {
    int num;
    int j;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
           num = money[i];
           j = i;
           while(j<size){
               if (num < money[j]){
                   num = money[j];
                 }
             j++;
           }
            while(sum+num <= KMAX){
               sum+=num;
               printf("%d ",sum);
            }
        }
    return sum;
}

int simpleHashSum(char* in){
    int sum = 0;
    for (int i = 0; i < SizeStr; i++){
        sum += in[i];
    }
     printf("Sum = %d\n",sum );
    return sum % htTable;
}

bool InsertNode(OneLinkNode** table, char* data) {
    OneLinkNode *p, *p0;
    int bucket = simpleHashSum(data);
    p = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (p == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}

OneLinkNode* FindNode(OneLinkNode** table, char* data) {
    OneLinkNode *p = table[simpleHashSum(data)];
    while (p && !(p->dat == data))
        p = p->next;
    return p;
}

void DeleteNode(OneLinkNode **table, char* data) {
    OneLinkNode *parent, *current;
    parent = NULL;
    htIndex bucket = simpleHashSum(data);
    current = table[bucket];
    while (current && !(current->dat == data)) {
        parent = current;
        current = current->next;
    }
    if (!current) {
        printf("Value not found \n");
        return;
    }
    if (parent)
        parent->next = current->next;
    else
        table[bucket] = current->next;
    free(current);
}

void printTable(OneLinkNode** table, int size) {
    OneLinkNode *p;
    for (int i = 0; i < size; ++i) {
        p = table[i];
        while (p) {
            printf("%5d", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    htTable = 10;
    char strArr[] = "hello, world";
    SizeStr = sizeof(strArr);
    OneLinkNode** hashTable = (OneLinkNode**) calloc(htTable, sizeof(OneLinkNode*));
    InsertNode(hashTable, strArr);
    printTable(hashTable, htTable);
    DeleteNode(hashTable, strArr);

    const int Size =5;
    int money[] = {50,10,5,2,1};
    KMAX=98;
    printf("(%d)\n", profitCalculation(money, Size));
    KMAX = 124;
    printf("(%d)\n", profitCalculation(money, Size));
    KMAX = 249;
    printf("(%d)\n", profitCalculation(money, Size));
    return 0;
}
