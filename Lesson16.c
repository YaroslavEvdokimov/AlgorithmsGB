#include "geek.c"
#include "geek.h"
#include <stdio.h>
#include <stdbool.h>
#define SIZE_ENG 27

int SizeStr;

char insArray(char *Arr, char *str){
    for (int i = 0; i<SizeStr; ++i){
        Arr[i] = str[i];
    }
}

char ArrEng (int n, int key){
    int num;
    char ArrayEng[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i<SIZE_ENG; ++i ){
        if (ArrayEng[i] == n){
            return ArrayEng[i+key%SizeStr];
        }
    }
}

void PrintStr(char *arr){
  for (int i = 0; i<SizeStr; ++i){
      printf("%c", arr[i]);
  }
}

char* caesar(char* in, int key, bool encrypt){
    if (encrypt){
    for (int i = 0; i <SizeStr-1; ++i){
        if (in[i] != ' '){
         int n = ArrEng(in[i], key);
         in[i] = n;
         printf("%c" , in[i]);
         }else
         printf("%c", ' ');
       }
    }else
       for (int i = 0; i <SizeStr-1; ++i){
            if (in[i] != ' '){
             int n = ArrEng(in[i], -key);
             in[i] = n;
             printf("%c" , in[i]);
            }else
         printf("%c", ' ');
       }
    return in;
}

char* shuffle(char* in, int key, int rowArr, bool encrypt){
   int countS = 0;
   char arr[rowArr][key];

    if (encrypt){
        char arr[5][key];
        for (int i = 0; i< rowArr ; ++i){
            for (int j = 0; j< key ; ++j){
                arr[i][j]=in[countS];
                if (in[countS] == ' '){
                    arr[i][j] = '!';
                }
              countS++;
            }
        }

        int j = 0;
        int col = 0;
        for (int i = 0; i< key ; ++i){
            int row = 0;
             while(row < rowArr){
             in[j] = arr[row][col];
             row++; j++;
             }
             col++;
            }
        printf("\n");
        for (int i = 0; i< SizeStr-1 ; ++i){
                printf("%c",in[i]);
        } printf("\n");

    }else{
        char arrDe[key][rowArr];
        int countDe = 0;
        for (int i = 0; i< key ; ++i){
            for (int j = 0; j< rowArr ; ++j){
                arrDe[i][j]=in[countDe];
                 countDe++;
                }
            }

        int j = 0;
        int col = 0;
        for (int i = 0; i< rowArr ; ++i){
            int row = 0;
             while(row < key){
             in[j] = arrDe[row][col];
             if (arrDe[row][col] == '!'){
                 in[j] = ' ';
               }
             row++; j++;
              }
             col++;
            }

        printf("\n");
        for (int i = 0; i< SizeStr-1 ; ++i){
                printf("%c",in[i]);
        }
       }
    return in;
}

int main()
{
    char str1[] = "home work for lesson";
    SizeStr = sizeof(str1);
    char *str = (char*)malloc(SizeStr* sizeof(char));
    printf("Task 1\n");
    insArray(str, str1);
    PrintStr(str);
    printf("\n");
    caesar(str, 3 , true);
    printf("\n");
    caesar(str, 3 , false);
    printf("\n");

    printf("\nTask 2");
    int ArrKey = 4;
    shuffle(str1, ArrKey, 5, true);
    printf("\n");
    shuffle(str1, ArrKey, 5, false);
    printf("\n");
    free(str);
    return 0;
}
