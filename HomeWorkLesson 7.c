#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define SIZE 30
#define swap(a, b, c) c=a, a=b, b=c

void InitArray(int *arr){

    for (int i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }
}

void printArray(int *arr){

    for (int i = 0; i < SIZE; i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}


void sortInserts(int *arr, int len){
    int temp,pos;
    for (int i = 1; i<len;i++){
        temp = arr[i];
        pos = i-1;
        while(pos>=0 && arr[pos]>temp){
            arr[pos+1] = arr[pos];
            pos--;
        }
        arr[pos+1] = temp;
    }
}

void medianaQS(int *arr,int first, int last){

    int swapInt=0;
    if(arr[first] > arr[(first+last)/2]){
        if(arr[first] < arr[last]){
            swap(arr[first], arr[(first+last)/2], swapInt);
        }else
            swap(arr[last], arr[(first+last)/2], swapInt);
    }else if (arr[(first+last)/2] > arr[last]){
        swap(arr[last], arr[(first+last)/2], swapInt);
    }else
      swap(arr[(first+last)/2], arr[(first+last)/2], swapInt);
}

void qs(int *arr, int first, int last){
    int swapInt=0;
    int i = first;
    int j = last;
    int x = arr[(first+last)/2];

    if (arr[SIZE] > 10){
    medianaQS(arr, 0, SIZE-1);
    do{
        while(arr[i]<x) i++;
        while(arr[j]>x) j--;
        if (i <= j){
            swap(arr[i],arr[j],swapInt);
            i++;
            j--;
        }
      }while (i<=j);

      if(i<last){
          qs(arr,i,last);
      }
      if (first<j){
          qs(arr,first,j);
      }
    }else
     sortInserts(arr, SIZE);
      }

//Task 2
void bucketSort(int *arr, int len){
    const int max = len;
    const int b = 10;
    int buckets[b][max+1];
    for (int i = 0;i < b;++i){
        buckets[i][max] = 0;
    }
    for(int digit = 1; digit< 1000000000;digit*=10){
        for (int i = 0; i < max; ++i){
            int d = (arr[i]/digit)%b;
            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max]=counter;
        }

        int idx = 0;
        for (int i = 0; i < b; ++i){
            for (int j = 0;j < buckets[i][max];++j){

                if (buckets[i][j]%2==0){
                    while(arr[idx]%2!=0){
                        idx++;
                    }
                 arr[idx++]= buckets[i][j];
                }
            }
            buckets[i][max]=0;
        }
    }
}

int main() {

srand(time(NULL));

int *arr = (int*)malloc(SIZE * sizeof(int));
InitArray(arr);
printArray(arr);

//Task2
bucketSort(arr,SIZE);

//Task1
//qs(arr,0,SIZE-1);

printArray(arr);

free(arr);

return 0;
}
