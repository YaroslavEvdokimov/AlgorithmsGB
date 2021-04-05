#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SizeTree 10000

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
}TreeNode;

bool isBalanced (TreeNode*);

TreeNode *treeInsert(TreeNode *t, int data){
    TreeNode *newNode;
    newNode = (TreeNode *)malloc(sizeof (TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;

    if ( t == NULL){
        t = newNode;
    }else {
        while(current->key != data){
            parent = current;
            if (current->key > data){
                current = current->left;
                if (current ==NULL){
                    parent->left = newNode;
                    return t;
                }
            }else{

                current = current->right;

                if (current == NULL){
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}
TreeNode *TreeInit(){
    int STrue = 0;
    float Procent;
    TreeNode *treeArr[50];
    for (int i = 0; i<50; i++){

    treeArr[i] = treeInsert(NULL, rand()%100);

    for (int j = 0; j < SizeTree; j++){

        treeArr[i] = treeInsert(treeArr[i], rand()%100);
        if (j+1 == SizeTree){

           if (isBalanced(treeArr[i]) == 1){
              STrue++;

           }
        }
      }
    }
   Procent = STrue/(float)50 * 100;
   printf("%f / 100",Procent);

  }



void printTree(TreeNode * root){
    if (root){
        printf("%d", root->key);
        if (root->left || root->right){
            printf("(");
            if (root ->left){
                printTree(root->left);
            }else
                printf("NULL");

            printf(",");
            if (root->right){
                printTree(root->right);
            }else
                printf("NULL");
              printf(")");
        }
    }
}


TreeNode *binSearch(TreeNode *root, int data) {
    if (root == NULL)
        return false;

    if (root->key == data)
        return root->key;

    TreeNode *current = root;

    if (current->key != data) {
        if (data < current->key){
            current = current->left;
          binSearch(current, data);
        }else{
            current = current->right;
             binSearch(current, data);
         }

        if (current == NULL)
           return false;
    }
}



bool isBalanced(TreeNode *root){

TreeNode *carrentLeft = root->left;
TreeNode *carrentRight = root->right ;

    if (root == NULL){
        printf("Tree is empty");
        return false;
    }
       int LeftLvl = 0;
       int RightLvl = 0;

       if (carrentLeft!=NULL){

        while(carrentLeft->left != NULL && carrentLeft->right !=NULL){
        carrentLeft = carrentLeft->left;
        if (carrentLeft->left == NULL && carrentLeft->right !=NULL){
            carrentLeft = carrentLeft->right;
           }
            LeftLvl++;
         }
        }

        if (carrentRight!=NULL){
        while(carrentRight->right != NULL && carrentRight->left != NULL){
             carrentRight = carrentRight->right;
             if (carrentRight->right == NULL && carrentRight->left !=NULL){
                  carrentRight = carrentRight->left;
                }
                  RightLvl++;
               }
            }
         if (LeftLvl == RightLvl || LeftLvl == RightLvl-1){
             return true;
         }else
             return false;
        }


int main(const int arc, const char **argv)
{
   srand(time(NULL));
   TreeNode *tree = treeInsert(NULL,10);
   treeInsert(tree,9);
   treeInsert(tree,19);
   treeInsert(tree,5);
   treeInsert(tree,16);
   treeInsert(tree,21);


   printf("\n Task 1: ");
   printf("%s", isBalanced(tree) > 0 ? "true" : "false" );
   printf("\n Task 2.a,2.b: ");
   TreeInit();
   printf("\n Task 3: ");
   printf ("%d",binSearch(tree, 9));
  
   return 0;
}
