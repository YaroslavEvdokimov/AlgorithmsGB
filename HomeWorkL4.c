#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
#define HEIGHT 8
#define WIDTH 8

int arr[HEIGHT][WIDTH];

void Task1 (int n){
    int Dec;
    if (n % 2 == 0){
        Dec = 0;
        printf("%d", Dec);
     }else{
     Dec = 1;
     printf("%d", Dec);
     }
     if ((n/2)!=0){
       Task1(n/2);
     }
     printf ("\n");
}

int Task2 (int a, int b){

   if ((b-1)!= 0){
      return a * Task2(a , b-1);

   }
}

int Task3 (int a , int b){

  if ((b-1)!= 0){
    if (b%2 == 0){
       return Task3(a*a,b/2);
       }else{
        return a * Task3(a, b - 1);
       }
    }
}


void board(){
    int x,y;
    for (int i = 0; i < HEIGHT; i++){
       x = rand()%8;
       y = rand()%8;
       for (int j = 0; j < WIDTH; j++){
          arr[i][j] = 0;
          arr[x][y] = 1;
       }
   }
}

int routes (int x ,int y){
    if (x == 0 && y == 0) return 0;
    else if (x == 0 ^ y == 0) return 1;
    else if (arr[x][y] == 1) return 1;
    else
    return routes(x ,y - 1)+ routes(x-1,y);
}


int main(const int argc, const char **argv){

    srand(time(NULL));

    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    Task1(n);

    int a,b;
    printf("Enter number a: ");
    scanf("%d",&a);
    printf("Enter number b: ");
    scanf("%d",&b);

    Task3(a , b);
    printf("%d", Task3(a, b));
    Task2(a, b);
    printf("%d", Task2(a,b));

    board();

    const int sizeX = 8;
    const int sizeY = 8;
     for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
             printf("%5d",routes(x,y));
         }
        printf("\n");
     }
    return 0;
}
