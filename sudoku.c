#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n)
{
   
   int num;
   // Primero revisar que no se repitan los numeros en la fila
   for (int i = 0; i < 9; i++)
      {
         int arrayFilas[10] = {0};
         for(int j = 0; j < 9; j++)
            {
               num = n->sudo[i][j];
               if (num == 0) continue;
               if (num < 1 || num > 9) return 0;
               if (arrayFilas[num] != 0) return 0;
               
               arrayFilas[num] = 1;

            }
      }
   // columnas
   for (int j = 0; j < 9; j++)
      {
         int arrayColumnas[10] = {0};
         for (int i = 0; i < 9; i++)
            {
               num = n->sudo[i][j];
               if (num < 1 || num > 9) return 0;
               if (arrayColumnas[num] != 0) return 0;

               arrayColumnas[num] = 1;
               
            }
      }
   // SubMatrices

    for (int k = 0; k < 9; k++) {
        int arrayMatrices[10] = {0};  
        for (int p = 0; p < 9; p++) {
           
            int i = 3 * (k / 3) + (p / 3);  
            int j = 3 * (k % 3) + (p % 3);  
            int num = n->sudo[i][j];  

            if (num < 1 || num > 9) return 0;  
            if (arrayMatrices[num] != 0) return 0;  

            arrayMatrices[num] = 1;  
        }
    }

   return 1;
   
   
}


List* get_adj_nodes(Node* n)
{
   List* list=createList();
   for (int i = 0; i<9; i++)
      {
         for (int j = 0; j<9 ; j++)
            {
               if (n->sudo[i][j] == 0)
               {
                  // pos tengo que hacer las 9 alternativas posibles
                  for (int k = 1; k <= 9; k++)
                     {
                        Node* newNode = copy(n);
                        newNode->sudo[i][j] = k;
                        pushBack(list, newNode);
                        
                     }
                  return list;
               }
               
            }
      }

   return list;
}


int is_final(Node* n){
   int num;
   // Primero revisar que no se repitan los numeros en la fila
   for (int i = 0; i < 9; i++)
      {
         int arrayFilas[10] = {0};
         for(int j = 0; j < 9; i++)
            {
               num = n->sudo[i][j];
               if (arrayFilas[num] != 0) return 0;
               arrayFilas[num] = 1;
               
            }
      }
    return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/