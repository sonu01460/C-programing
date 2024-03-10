#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <inttypes.h>

int getint(char *str)
{
    int val =0, res =0;
    while(*str)
    {
        if(*str>= '0' && *str <= '9')
        {
             res = *str & 0x0F;
            val = res + val*10;
            printf("%d %x\n",val, res);
        }
       str++; 
    }
    return val;
}

void revrsesrting(char* str)
{
    //int len = strlen(str);
     char *end = str + strlen(str) -1;
     char temp;
     char *start = str;
     
     
     printf("%d\n", strlen(str));
     while(end > start)
     {
          printf("s= %c e= %c t= %c\n",*str, *end, temp);
         temp = *start;
         *start = *end;
         *end = temp;
         end --;
         start++;
         printf("s= %c e= %c t= %c\n",*str, *end, temp);
     }
     printf("%s\n",str);
     
}

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

//typedef Node
Node * InserNode(Node *head, int val)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    
    NewNode->data = val;
    NewNode->next =head;
    return NewNode;
    
}

void displaylist(Node *head)
{
    while(head !=NULL)
    {
        printf("->%d",head->data);
        head =head->next;
    }
}

Node* fintmid(Node *head)
{
    Node *slow = head;
    Node *fast =head;
    while(fast != NULL && fast->next != NULL)
    {
       slow =slow->next;
       fast =fast->next->next;
    }
    return slow;
}

Node * ReverseList(Node * head)
{
   Node *current = head;
    Node *Next = NULL;
    Node *previous =NULL;
    
    while(current !=NULL)
    {
        Next = current->next;
        current->next = previous;
        previous = current;
        current = Next;
        
    }
    return previous;
    
}
int main(void)
{
    Node *head =NULL;
    head = InserNode(head,10);
    head = InserNode(head,20);
    head = InserNode(head,30);
    head = InserNode(head,40);
    //head = InserNode(head,30);
    //head = InserNode(head,20);
    //head = InserNode(head,10);
    displaylist(head);
    
   Node *mid = fintmid(head);
   head = ReverseList(head);
   displaylist(head);
    printf("%d\n", mid->data);
    //char Instr[] = "as123";
    //int val = getint(Instr);
    //printf("getInt = %d\n",val);
    char mystr[] ="my name is sonu";
    revrsesrting(mystr);
    int u32RawData;
    char *pu8CheckData;
    u32RawData = 0x11223344; //Assign data
    pu8CheckData = (char *)&u32RawData; //Type cast
    //printf("%d",*pu8CheckData);
    if (*pu8CheckData == 0x44) //check the value of lower address
    {
        printf("little-Endian");
    }
    else if (*pu8CheckData == 0x11) //check the value of lower address
    {
        printf("big-Endian");
    }
}
