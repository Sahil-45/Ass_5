#include <stdio.h>
#include <stdlib.h>

struct node {

    int num;
    struct node *preptr;
    struct node *nextptr;

}*stnode, *ennode;

void Dllistcreation(int n){
     
    int i=0, num;
    struct node *fnNode;
    if (n >= 1)
    {
       stnode = (struct node *)malloc(sizeof(struct node));

       if(stnode != NULL)
       {
           printf(" Input data for node 1: "); // assigning data in the first node
           scanf("%d", &num);

           stnode->num = num;
           stnode->preptr = NULL;
           stnode->nextptr = NULL;
           ennode = stnode;

    // putting data for rest of the nodes
           for ( i = 2; i <=n; i++)
           {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode!=NULL){
            
                  printf(" Input data for node %d :",i);
                  scanf("%d",&num);
                  fnNode->num=num;
                  fnNode->preptr=ennode;    //New Node is linked with the prev node
                  fnNode->nextptr=NULL;

                  ennode->nextptr=fnNode; 
                  ennode = fnNode;
                }
                else{
                    printf("Memory can not be allocated.");
                    break;
                }
           }
       }
       else{
            printf("Memory can not be allocated.");
       }
    }          
}

void displayDlList()
{

    struct node *tmp;
    int n = 1;
    if (stnode == NULL)
    {
         printf(" No data found in the List yet.");
    }
    else
    {
         tmp = stnode;
         printf("\n\n Data entered on the DoublyLlist are : \n");

         while(tmp != NULL)
         {
            printf(" Node %d: %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr;    // current pointer moves to the next node
         }
    }
}
int main()
{

    int n;
    stnode = NULL;
    ennode = NULL;
    printf("\n\n Doubly Linked List: Create and display a doubly linked list :\n"); 
    printf("------------------------------------------------------------------\n");
    printf("Input the number of nodes : ");
    scanf("%d", &n);
    Dllistcreation(n);
    displayDlList();
    return 0;
}
  

