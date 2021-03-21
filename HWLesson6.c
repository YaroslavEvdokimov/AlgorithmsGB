#include <stdio.h>
#include <time.h>

#define SizeX 5
#define SizeY 5
#define swap(a,b,c) ((c = a), (a = b), (b = c))

void  BubbleSort(int array[SizeX][SizeY]){
int sort = 0;
for (int Cycle = 0; Cycle < (SizeX*SizeY)-1; Cycle++){
    for (int i = 0; i < SizeX; i++){
        for (int j = 0; j < SizeY; j++){


            if (array[i][j] > array[i][j+1])
            {
                swap(array[i][j],array[i][j+1],sort);
            }
        }
    }
}
     for (int i = 0; i < SizeX; i++){
        for (int j = 0; j < SizeY; j++){
            printf("%3d", array[i][j] );
        }
        printf("\n");
    }
}


double fanc(double X)
{
  return sqrt(fabs(X)) + 5 * pow(X, 3);
}

void TPK()
{
    double arr[11];

    for (int i = 0; i < 11; i++){
        scanf("%f",&arr[i]);
    }
    for (int j = 11; j > 0; j--){

        if (fanc(arr[j]) > 400){
        printf("Number > 400");
        }
    }
}


int main() {

   srand(time(NULL));
   int array[SizeX][SizeY];

   for (int i = 0; i < SizeX; i++){
      for (int j = 0; j < SizeY; j++){
           array[i][j]= rand() % 25;
           printf ("%3d", array[i][j]);
       }
     printf("\n");
   }
   printf("\n\n");

  BubbleSort(array);
  TPK();


    return 0;
}
