#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node 
{
int data ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail = NULL ;

void printfunc(int num)
{
  node *temp = head;
  int j= 0;
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  
}
void printout(int num)
{
  node *o  = head ;
  int y = 0 ;
  while(y!=num)
    {
      printf("%d ",o->data) ;
      o = o->next ;
      y++ ;
    }
  
}

static void reverse(struct node** head_ref , int num )
{
	struct node *prev = NULL;
	struct node *current = *head_ref;
	struct node *next = NULL;
	while (current != NULL) {
		// Store next
		next = current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	*head_ref = prev;
  printout(num) ;
}



void delete(int num , int k)
  {
    int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }
 // printf("length : %d",c) ;
  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    if(k==0)
    {
      node *front = head ;
      node *del = head ;
      head = front->next ;
      free(del) ;
    }
    else if(k==num)
    {
      node *ls = head  ;
      int kl = 0 ;
      while(kl!=(num-1))
        {
          ls = ls->next ;
          kl++ ;
        }
      node *o = tail  ;
      tail = ls ;
      free(o) ;
      ls->next = NULL ;
    }
    else 
    {
      node *p  = head ;
      int mn =1 ;
      while(mn!=(k-1))
        {
          p=p->next ;
          mn++ ;
        }
      node *nex =  p->next ;
      node *op = nex->next ;
      free(nex) ;
      p->next = op  ;
    }
  }
  printfunc(num-1) ;
    
  }
void  kthNode(int k)
{
  int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }

  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    node *max = head ;
    int m  = 1;
    while(m!=k)
      {
        max = max->next ;
        m++ ;
      }
    printf("%d ",max->data) ;
    
  }
}
int length()
{
  int count = 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      count = count +1  ;
      f= f->next ;
    }
  printf("%d",count) ;
}

void printnode(int num)
{
  node *temp = head;
  int j= 0;
  if(num==0||head == NULL)
      {
        printf("EMPTY") ;
      }
  else
  {
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  }
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  //printf("enter data for node ") ;
  scanf("%d",&ptr->data) ;
  if(head==NULL)
  {
    head = ptr ;
    tail  = ptr ;
  }
  else if (head == tail)
  {
    node *y = tail  ;
    y->next = ptr  ;
   tail = ptr  ;
   // ptr ->next = NULL  ;
  }
  else 
  {
    node *mx = tail  ;
    mx ->next = ptr  ;
    tail = ptr   ;
   // mx ->next=NULL ;
      
  }
}
int main()
{
  int num , query ;
  //printf("enter the length :") ;
  scanf("%d  %d",&num,&query) ;
  //printf("enter the query :") ;
  //scanf("%d",&query) ;
  int i = 0 ;
  while(i!=num)
    {
      create() ;
      i++ ;
    }

  if(query==1)
  {
    node *hj = NULL;
    reverse( &hj, num) ;
  }
  else if(query==2)
  {
     printnode(num) ;
  }
  else if(query==3)
  {
   
    length() ;
    
  }
  
  else if(query==4)
  {
    int k ;
    //printf("enter the k value :") ;
    scanf("%d",&k) ;
    kthNode(k) ;
    
  }
  else if(query==5)
  {
    int k ;
    //printf("enter the k value :") ;
    scanf("%d",&k) ; 
    delete(num , k) ;
  
  }
  return 0 ;
}
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node 
{
int data ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail = NULL ;

void printfunc(int num)
{
  node *temp = head;
  int j= 0;
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  
}
void printout(int num)
{
  node *o  = head ;
  int y = 0 ;
  while(y!=num)
    {
      printf("%d ",o->data) ;
      o = o->next ;
      y++ ;
    }
  
}



void delete(int num , int k)
  {
    int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }
 // printf("length : %d",c) ;
  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    if(k==0)
    {
      node *front = head ;
      node *del = head ;
      head = front->next ;
      free(del) ;
    }
    else if(k==num)
    {
      node *ls = head  ;
      int kl = 0 ;
      while(kl!=(num-1))
        {
          ls = ls->next ;
          kl++ ;
        }
      node *o = tail  ;
      tail = ls ;
      free(o) ;
      ls->next = NULL ;
    }
    else 
    {
      node *p  = head ;
      int mn =1 ;
      while(mn!=(k-1))
        {
          p=p->next ;
          mn++ ;
        }
      node *nex =  p->next ;
      node *op = nex->next ;
      free(nex) ;
      p->next = op  ;
    }
  }
  printfunc(num-1) ;
    
  }
void  kthNode(int k)
{
  int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }

  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    node *max = head ;
    int m  = 1;
    while(m!=k)
      {
        max = max->next ;
        m++ ;
      }
    printf("%d ",max->data) ;  
  }
}
int length()
{
  int count = 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      count = count +1  ;
      f= f->next ;
    }
  printf("%d",count) ;
}

void printnode(int num)
{
  node *temp = head;
  int j= 0;
  if(num==0||head == NULL)
      {
        printf("EMPTY") ;
      }
  else
  {
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  }
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  //printf("enter data for node ") ;
  scanf("%d",&ptr->data) ;
  if(head==NULL)
  {
    head = ptr ;
    tail  = ptr ;
  }
  else if (head == tail)
  {
    node *y = tail  ;
    y->next = ptr  ;
   tail = ptr  ;
   // ptr ->next = NULL  ;
  }
  else 
  {
    node *mx = tail  ;
    mx ->next = ptr  ;
    tail = ptr   ;
   // mx ->next=NULL ;
      
  }
}
int main()
{
  int num , query ;
  //printf("enter the length :") ;
  scanf("%d  %d",&num,&query) ;
  //printf("enter the query :") ;
  //scanf("%d",&query) ;
  int i = 0 ;
  while(i!=num)
    {
      create() ;
      i++ ;
    }

 if(query==1)
  {
     printnode(num) ;
  }
  else if(query==2)
  {
   
    length() ;
    
  }
  
  else if(query==3)
  {
    int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ;
    kthNode(k) ;
    
  }
  else if(query==4)
  {
    int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ; 
    delete(num , k) ;
  
  }
  return 0 ;
}


// code --->2 
#include <stdio.h>
#include<stdlib.h>
void checker(int num , int target , int array[])
{
  int counter ;
  for(int i = 0 ; i<num ; i++)
    {
      for(int j = 0 ;  j<num  ; j++)
        {
          if((array[i] + array[j]) == target)
          {
            printf("\n%d %d ",array[i] , array[j]) ;
            counter ++ ;
          }
          else
            {
              printf("\nnot possible ") ;
              break ;
            }
          }
        
    }
  printf("\n%d",counter);
}


int main()
{
  int num ;
  int target ;
  printf("enter the size") ;
  scanf("%d",&num) ;
  printf("enter target : ") ;
  scanf("%d",&target) ;
  int array[num] ;
  for(int i = 0 ; i<num  ; i++)
    {
      printf("enter data : ");
      scanf("%d",&array[i]) ;
    }
  printf("the array is : ") ;
  for(int i =  0 ; i<num ;  i++)
    {
      printf("%d-->",array[i]) ;
    }
  checker(num ,target, array) ;
}

// code -->3 wrong 
#include <stdio.h>
#include <stdlib.h>
void checkindex(int array , int query)
{
  
}
int main()
{
int size  ;
  int query ;
  printf("enter the array size") ;
  scanf("%d",&size) ;
  printf("enter the querey ")  ;
  scanf("%d",&query) ;
  int array[size] ;
  for(int i = 0 ; i<size ; i++)
    {
      printf("enter data :") ;
      scanf("%d",&array[i]) ;
    }
  for(int i  = 0 ; i<size ; i++)
    {
       printf("%d ",array[i]) ;
    }
  int array_query[size];
for(int i  = 0 ; i<size ; i++)
  {
    printf("enter query :") ;
    scanf("%d ",array_query[i]) ;
  }
  for(int i = 0 ; i<size ; i++)
    {
      printf("%d-->",query) ;
    }
checkindex(array , query) ;
}

// xor operation 
// conversion of int to binaery 

while (temp != NULL) {
        result ^= (temp->data ^ x);
        temp = temp->next;
    }
  


// code 5 

#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>
struct node 
{
int data ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail = NULL ;

void printfunc(int num)
{
  node *temp = head;
  int j= 0;
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  
}
void printout(int num)
{
  node *o  = head ;
  int y = 0 ;
  while(y!=num)
    {
      printf("%d ",o->data) ;
      o = o->next ;
      y++ ;
    }
  
}



void delete(int num )
  {
     
    int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }
 // printf("length : %d",c) ;
  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    if(k==0)
    {
      node *front = head ;
      node *del = head ;
      head = front->next ;
      free(del) ;
    }
    else if(k==num)
    {
      node *ls = head  ;
      int kl = 0 ;
      while(kl!=(num-1))
        {
          ls = ls->next ;
          kl++ ;
        }
      node *o = tail  ;
      tail = ls ;
      free(o) ;
      ls->next = NULL ;
    }
    else 
    {
      node *p  = head ;
      int mn =1 ;
      while(mn!=(k-1))
        {
          p=p->next ;
          mn++ ;
        }
      node *nex =  p->next ;
      node *op = nex->next ;
      free(nex) ;
      p->next = op  ;
    }
  }
  printfunc(num-1) ;
    
  }
void  kthNode()
{
    int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ;
  int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }

  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    node *max = head ;
    int m  = 1;
    while(m!=k)
      {
        max = max->next ;
        m++ ;
      }
    printf("%d ",max->data) ;  
  }
}
int length()
{
  int count = 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      count = count +1  ;
      f= f->next ;
    }
  printf("%d",count) ;
}

void printnode(int num)
{
  node *temp = head;
  int j= 0;
  if(num==0||head == NULL)
      {
        printf("EMPTY") ;
      }
  else
  {
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  }
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  //printf("enter data for node ") ;
  scanf("%d",&ptr->data) ;
  if(head==NULL)
  {
    head = ptr ;
    tail  = ptr ;
  }
  else if (head == tail)
  {
    node *y = tail  ;
    y->next = ptr  ;
   tail = ptr  ;
   // ptr ->next = NULL  ;
  }
  else 
  {
    node *mx = tail  ;
    mx ->next = ptr  ;
    tail = ptr   ;
   // mx ->next=NULL ;
      
  }
}
int main()
{
  int num , query ;
  //printf("enter the length :") ;
  scanf("%d  %d",&num,&query) ;
  //printf("enter the query :") ;
  //scanf("%d",&query) ;
  int i = 0 ;
  while(i!=num)
    {
      create() ;
      i++ ;
    }
  for(int i = 0 ; i<query ; i++)
    {
      char array[20] ; 
      int w ; 
      printf("enter : ") ;
      scanf("%s",array) ;
      scanf("%d",&w) ;
      if(strcmp(array, "Delete")== 0)
      {
        int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ;
        delete(k ) ;
      }
    }
}
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>
struct node 
{
int data ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail = NULL ;

void printfunc(int num)
{
  node *temp = head;
  int j= 0;
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  
}
void printout(int num)
{
  node *o  = head ;
  int y = 0 ;
  while(y!=num)
    {
      printf("%d ",o->data) ;
      o = o->next ;
      y++ ;
    }
  
}



void delete(int num , int k )
  {
     
    int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }
 // printf("length : %d",c) ;
  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    if(k==0)
    {
      node *front = head ;
      node *del = head ;
      head = front->next ;
      free(del) ;
    }
    else if(k==num)
    {
      node *ls = head  ;
      int kl = 0 ;
      while(kl!=(num-1))
        {
          ls = ls->next ;
          kl++ ;
        }
      node *o = tail  ;
      tail = ls ;
      free(o) ;
      ls->next = NULL ;
    }
    else 
    {
      node *p  = head ;
      int mn =1 ;
      while(mn!=(k-1))
        {
          p=p->next ;
          mn++ ;
        }
      node *nex =  p->next ;
      node *op = nex->next ;
      free(nex) ;
      p->next = op  ;
    }
  }
  printfunc(num-1) ;
    
  }
void  kthNode()
{
    int k ;
    printf("KthNode ") ;
    scanf("%d",&k) ;
  int c= 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      c++ ;
      f= f->next ;
    }

  if(k>c)
  {
    printf("-1") ;
  }
  else 
  {
    node *max = head ;
    int m  = 1;
    while(m!=k)
      {
        max = max->next ;
        m++ ;
      }
    printf("%d ",max->data) ;  
  }
}
int length()
{
  int count = 0 ;
  node *f = head  ;
  node *t = tail  ;
  while (f!=NULL)
    {
      count = count +1  ;
      f= f->next ;
    }
  printf("%d",count) ;
}

void printnode(int num)
{
  node *temp = head;
  int j= 0;
  if(num==0||head == NULL)
      {
        printf("EMPTY") ;
      }
  else
  {
  while(j!=num)
    {
      printf("%d ",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
  }
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  //printf("enter data for node ") ;
  scanf("%d",&ptr->data) ;
  if(head==NULL)
  {
    head = ptr ;
    tail  = ptr ;
  }
  else if (head == tail)
  {
    node *y = tail  ;
    y->next = ptr  ;
    // ptr ->next = NULL  ;
  }
  else 
  {
    node *mx = tail  ;
    mx ->next = ptr  ;
    tail = ptr   ;
   // mx ->next=NULL ;
      
  }
}
int main()
{
  int num , query ;
  //printf("enter the length :") ;
  scanf("%d  %d",&num,&query) ;
  //printf("enter the query :") ;
  //scanf("%d",&query) ;
  int i = 0 ;
  while(i!=num)
    {
      create() ;
      i++ ;
    }
  for(int i = 0 ; i<query ; i++)
    {
      char array[20] ; 
      int w ; 
      printf("enter : ") ;
      scanf("%s",array) ;
      scanf("%d",&w) ;
      if(strcmp(array, "Delete")== 0)
      {
        int k ;
      printf("KthNode ") ;
       scanf("%d",&k) ;
        delete(num , k) ;
      }
    }
}
//q->1 , 206leetcode
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data  ;
struct node *next ;

} ;
typedef struct node node ;
node *head =   NULL ;
node *tail = NULL ;
void createnode()
{
node *ptr = (node*)malloc(sizeof(node)) ;
scanf("%d",&ptr->data) ;
ptr->next =NULL ;
if(head ==NULL)
{
  head = ptr  ;
  tail = ptr ;
  
}
else if(head ==tail)
{
  node *move = tail  ;
  move->next = ptr  ;
  tail = ptr ;
  
}
else
{
  node *mover  = tail  ;
  mover->next = ptr  ;
  tail = ptr  ;
}
}
void printreverse(int num)
{
  int i = 0 ;
  node *m = tail ;
  while(i!=num)
    {
      printf("%d-->",m->data) ;
      i++ ;
      
    }
}

void printnode(int num)
{
  
  int i= 0;
  while(i!=num)
    {
      printf("%d-->",head->data) ;
      head= head->next ;
      i++ ;
      
    }
  
}

int main()
{
  printf("enter the number of elemnt in the linked list") ;
  int num  ;
  scanf("%d",&num) ;
  int i = 0 ;
  while(i!=num)
    {
      createnode() ;
      i++ ;
    }
  printnode(num) ;
  printf("\n") ;
  printreverse(num) ;
  
  return 0 ;
}

// questio -2 141 leet code 
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next  ;
} ;
typedef struct node node ; 
node *head = NULL ;
node *tail = NULL ;

int cyclecounter(int nums)
{
  node *last = tail  ;
  int count = 0 ;
  int pos  ;
  printf("\nenter the index") ;
  scanf("%d",&pos) ;
  if(pos<nums)
  {
  while(count!=pos)
    {
      last = last->next ;
      count++ ;
      
    }
  printf("\nthe data is : %d",last->data) ;
  if(count<nums)
  {
    printf("\ntrue the cycle is possible") ;
    
  }
  else  
  {
    printf("\nFalse the cycle is not possible") ;
  }
  }
  else 
  {
    printf("errror!!! the number of element are less than the index  ");
  }
  
  
  
}


void printfunc(int num)
{
  printf("PRINTING DATA ") ;
  int i = 0 ;
  node *p = head ;
  while(i!=num)
    {
        printf("%d ",p->data)  ;
        i++ ;
        p = p->next  ;
    }

  
}
void createnode()
{
  node *ptr = (node*)malloc(sizeof(node));
  printf("enter the node data ") ;
  scanf("%d", &ptr->data) ;
  ptr->next = NULL ;
  if(head==NULL)
  {
    head = ptr  ; 
    tail = ptr  ;
    ptr->next = head  ;
    
  }
  else if (head == tail)
  {
    node *move =  tail ;
    head->next = ptr  ;
    tail = ptr ;
    ptr->next  = head  ; 
  }
  else 
  {
    node *temp  = tail ;
    temp->next = ptr  ;
    tail = ptr ;
    ptr->next  = head ;
  }
}
int main()
{
  int num  ;
  printf("enter the numebr of element in the linked list :") ;
  scanf("%d",&num) ;
  int i = 0  ;
  while(i!=num)
    {
      createnode() ;
      i++ ;
      
    }
  printfunc(num) ;
  cyclecounter(num) ;
  
  
}

// question3 
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next  ;
} ;
typedef struct node node  ;
node *head = NULL ;
node *tail = NULL ;

void printfunc(int num)
{
  node *d  = head ;
  int i = 0 ;
  while(i!=num)
    {
      printf("%d ",d->data) ;
      i++ ;
      d = d->next  ;  
    }
  
  
}

void compare(int num)
{
  int k = 0 ;
  node *compare = head  ;
  
  while(k!=num)
    {
      if(compare->data>compare->next->data)
      {
        int temp =0  ;
        temp = compare->data ;
        compare->data = compare ->next->data ;
        compare->next->data= temp  ;
        compare = compare->next ;

      }
      k++ ;
    }
  
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data for the linked list : ") ;
  scanf("%d",&ptr->data) ;
  node *t = head  ;
  if(head ==NULL)
  {
    head = ptr ;
    tail  = ptr ;
    
  }
  else if (head == tail)
  {
    head->next = ptr  ;
    tail = ptr ;

    ptr->next = NULL ;
    
  }
  else
  {
    node *new = tail ;
    new->next = ptr  ;
    tail = ptr ;
    ptr->next = NULL; 
    
  }
  
}
int main()
{
  int num  ;
  printf("enter the elements for the first linked list") ;
  scanf("%d",&num) ;
  int z =0 ;
  while(z!=num)
    {
      create() ;
      z++ ;
    }
  printfunc(num) ;
    printf("\n") ;
  compare(num) ;
  printf("\n") ;
  printfunc(num) ;
}
// code for merge two linked list  -> ERROR !!
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next  ;
} ;
typedef struct node node  ;
node *head = NULL ;
node *tail = NULL ;
// print->second linked list 
void printsec(int s )
{
  node *ptr = head  ;
  int im = 0 ;
  while(im!=s)
    {
     printf("%d ",ptr->data) ;
      ptr= ptr->next ;
    im++ ;
      
    }
}
// print first linked list 
void printfunc(int x)
{
  node *d  = head ;
  int i = 0 ;
  while(i!=x)
    {
      printf("%d ",d->data) ;
      i++ ;
      d = d->next  ;  
    }
  
  
}
void compare(int num)
{
  int i = 0 ;
  
  node *com = head  ;
  node *end = tail  ;
  while(i!=num)
    {
      if(com->data >com->next->data)
      {
        int temp = 0 ;
        temp = com->data  ;
        com->data = com->next ->data  ;
        com ->next->data = temp  ;
        com = com->next  ;
      }
      i++ ;
    }
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data for the linked list : ") ;
  scanf("%d",&ptr->data) ;
  node *t = head  ;
  if(head ==NULL)
  {
    head = ptr ;
    tail  = ptr ;
    
  }
  else if (head == tail)
  {
    head->next = ptr  ;
    tail = ptr ;

    ptr->next = NULL ;
    
  }
  else
  {
    node *new = tail ;
    new->next = ptr  ;
    tail = ptr ;
    ptr->next = NULL; 
    
  }
  
}
int main()
{
  int num  ;
  printf("enter the elements for the first linked list") ;
  scanf("%d",&num) ;
  int z =0 ;
  while(z!=num)
    {
      create() ;
      z++ ;
    }
  printfunc(num) ;
    printf("\n") ;
  compare(num) ;
  printf("\n") ;
  printfunc(num) ;
  printf("\n the second linked list :") ;
  int s ;
  printf("\nenter the number :") ;
  scanf("%d",&s) ;
  int m = 0;
  while(m!=s)
    {
      create(s) ;
      m++ ;
      
    }
  printf("\n") ;
  printsec(s) ;
  
  
}


// geeks for geeks q-->1

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data  ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL;
node *tail = NULL ;
void printfunc(int  num)
{
  node *temp  = head  ;
  int z  = 0 ;
  while(z!=num/2)
    {
      printf("%d--",temp->data) ;
      temp = temp ->next ;
      z++ ;
    }
  
  
}
void createnode()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data ") ;
  scanf("%d",&ptr->data) ;
  if(head == NULL)
  {
    head = ptr  ;
    tail = ptr  ;
    
  }
  else if(head == tail)
  {
    node *temp = tail ;
    temp->next = ptr  ;
    tail = ptr  ;
  }
  else 
  {
    node *y  = tail  ;
    y->next = ptr ;
    tail = ptr  ;
    
  }
  
  
}
int main()
{
  int num ; 
  printf("enter the number :") ;
  scanf("%d",&num) ;
  int i = 0;
  while(i!=num)
    {
      createnode() ;
      i++ ;
      
    }
  printfunc(num);
  return 0 ;
}
//middle element of the linekd list 

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data  ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL;
node *tail = NULL ;
void printfunc(int  num)
{
  node *temp = head  ;
  int j = 0 ;
  while(j!=((num/2)-1))
    {
      temp = temp ->next  ;
      j++ ;
    }
  printf("the middle elemtn of the linked list is :%d ",temp->next->data);
  
  
  
}
void createnode()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data ") ;
  scanf("%d",&ptr->data) ;
  if(head == NULL)
  {
    head = ptr  ;
    tail = ptr  ;
    
  }
  else if(head == tail)
  {
    node *temp = tail ;
    temp->next = ptr  ;
    tail = ptr  ;
  }
  else 
  {
    node *y  = tail  ;
    y->next = ptr ;
    tail = ptr  ;
    
  }
  
  
}
int main()
{
  int num ; 
  printf("enter the number :") ;
  scanf("%d",&num) ;
  int i = 0;
  while(i!=num)
    {
      createnode() ;
      i++ ;
      
    }
  printfunc(num);
  return 0 ;
}


// geek for geeks counter calculator not working properly 

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data  ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL;
node *tail = NULL ;
int counter(int nums , int num)
{
  int count = 0 ;
  node *ytr = head ;
  for(int  j = 0 ; j<num ; j++)
    {
      if(ytr->data == nums)
      {
        count++ ;
        ytr=ytr->next ;
      }  
    }
  printf("%d is the count  ", count) ;
}
void createnode()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data ") ;
  scanf("%d",&ptr->data) ;
  if(head == NULL)
  {
    head = ptr  ;
    tail = ptr  ;
    
  }
  else if(head == tail)
  {
    node *temp = tail ;
    temp->next = ptr  ;
    tail = ptr  ;
  }
  else 
  {
    node *y  = tail  ;
    y->next = ptr ;
    tail = ptr  ;
    
  }
  
  
}
int main()
{
  int num ; 
  printf("enter the number :") ;
  scanf("%d",&num) ;
  int i = 0;
  while(i!=num)
    {
      createnode() ;
      i++ ;
      
    }
  int nums  ;
  printf("enter the number that you want ot count") ;
  scanf("%d",&nums) ;
  counter(nums , num ) ;
  return 0 ;
  
  
}
 //circular linked list check 
 #include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next ;
} ;
typedef struct node node  ;
node *head = NULL ;
node *tail = NULL ;
int cir()
{
  node *s = head  ;
  node *l = tail  ;
  if(l->next == s){
    printf("True  the linked list is circular ") ;
    
  }
  else 
  {
    printf("False the linked list is not ciruclar") ;
  }
}
void printfunc(int num)
{
  node *g = head ;
  int j = 0 ;
  while(j!=num)
    {
      printf("%d-->",g->data) ;
      g= g->next ;
      j++ ;
    }
  
}
void createnode()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data ") ;
  scanf("%d",&ptr->data) ;
  if(head== NULL)
  {
    head = ptr ;
    tail= ptr  ;
    //ptr->next = head ;
    
  }
  else if (head == tail)
  {
    node *temp = tail  ;
    temp->next = ptr ;
    tail = ptr ;
    //ptr->next = head  ;
  }
  else 
  {
    node *tem = tail  ;
    tem ->next = ptr  ;
    tail = ptr  ;
    //ptr->next = head  ;
    
  }
}
int main()
{
  int num  ;
  printf("enter the number ") ;
  scanf("%d",&num) ;
  int i = 0 ;
  while(i!=num)
    {
      createnode() ;
      i++ ;
      
    }
  printfunc(num) ;
  printf("\n");
  cir() ;
  
  return 0;
}
// node calculator 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next ;
} ;
typedef struct node node  ;
node *head = NULL ;
node *tail = NULL ;
int  nodecounter(int num)
{
  int i = 0 ; 
  int count =0  ;
  while(i!=num)
    {
      count ++ ;
      i++ ;
    }
  printf("\nthe counter value is %d", count) ;
}
int cir()
{
  node *s = head  ;
  node *l = tail  ;
  if(l->next == s){
    printf("True  the linked list is circular ") ;
    
  }
  else 
  {
    printf("False the linked list is not ciruclar") ;
  }
}
void printfunc(int num)
{
  node *g = head ;
  int j = 0 ;
  while(j!=num)
    {
      printf("%d-->",g->data) ;
      g= g->next ;
      j++ ;
    }
  
}
void createnode()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data ") ;
  scanf("%d",&ptr->data) ;
  if(head== NULL)
  {
    head = ptr ;
    tail= ptr  ;
    ptr->next = head ;
    
  }
  else if (head == tail)
  {
    node *temp = tail  ;
    temp->next = ptr ;
    tail = ptr ;
    ptr->next = head  ;
  }
  else 
  {
    node *tem = tail  ;
    tem ->next = ptr  ;
    tail = ptr  ;
    ptr->next = head  ;
    
  }
}
int main()
{
  int num  ;
  printf("enter the number ") ;
  scanf("%d",&num) ;
  int i = 0 ;
  while(i!=num)
    {
      createnode() ;
      i++ ;
      
    }
  printfunc(num) ;
  printf("\n");
  cir() ;
  nodecounter(num) ;
  
  return 0;
}

// conversion of singly to ciruclkar linked list 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next ;
} ;
typedef struct node node  ;
node *head = NULL ;
node *tail = NULL ;
int cir()
{
  node *s = head  ;
  node *l = tail  ;
  if(tail->next = head ){
    printf("\nTrue  the linked list is circular ") ;
    
  }
  else if(tail->next != head)
  {
    printf("\nFalse the linked list is not ciruclar") ;
  }
  else
  {
    return 0 ;
  }
}
void convert()
{
  node *x = tail  ;
  node *h = head ;
  if(tail==NULL)
  {
    tail->next = head  ;
    
  }
}

void createnode()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data ") ;
  scanf("%d",&ptr->data) ;
  if(head== NULL)
  {
    head = ptr ;
    tail= ptr  ;
    tail->next = NULL; 
    
  }
  else if (head == tail)
  {
    node *temp = tail  ;
    temp->next = ptr ;
    tail = ptr ;
    tail->next = NULL ;
  }
  else 
  {
    node *tem = tail  ;
    tem ->next = ptr  ;
    tail = ptr  ;
    tail ->next = NULL ;
    
  }
}
int main()
{
  int num  ;
  printf("enter the number  for the singly linked list :") ;
  scanf("%d",&num) ;
  int i = 0 ;
  while(i!=num)
    {
      createnode() ;
      i++ ;
      
    }
  
  cir() ;
  
  convert()  ;
  
  cir() ;
  return 0 ;
  
  
}

// head --->exchneage with tail 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node 
{
int data ;
struct node *next ;
} ;
typedef struct node node  ;
node *head = NULL; 
node *tail = NULL ;
void print(int n )
{
  node *r= head ;
  int i =0 ;
  while(i!=n)
    {
      printf("%d-->",r->data) ;
      r= r->next ;
      i++ ;
    }
}
void exchange()
{
  node *s = head  ;
  node *l = tail  ;
  if(l->next == s)
  {
    int tle  ;
    tle = s->data ;
    s->data = l->data ;
    l->data = tle ;
  }
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data element") ;
  scanf("%d",&ptr->data) ;
    ptr ->next = NULL ;
  if(head == NULL)
  {  
    head = ptr  ;
    tail = ptr  ;
    ptr->next = head ;
  }
  else if(head == tail)
  {
    node *temp = tail  ;
    temp->next = ptr  ;
    tail = ptr ;
    ptr->next  = head  ;
    
  }
  else 
  {
    node *tem = tail ;
    tem->next = ptr  ;
    tail = ptr  ;
    ptr->next = head  ;
    
  }
}
int main()
{
  int n ;
  printf("enter data ") ;
  scanf("%d",&n) ;
  int i = 0;
  while(i!=n)
    {
      create() ;
      i++ ;
    }
  exchange() ;
  print(n) ;
  return 0 ;
  
  
}

// reverse of a doubly linked list 
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct node 
{
int data ;
struct node *next  ;
struct node *prev ;
} ;
typedef struct node node  ;
node *head = NULL ;
node *tail = NULL ;
void reverse(int x )
{
  node *y = tail  ;
  int j = 0 ;
  while(j!=x)
    {
      printf("%d --> ",y->data) ;
      y = y->prev ;
      j++ ;
    }
}
void print(int x)
{
  node *te = head  ;
  int i = 0 ;
  while(i!=x)
    {
      printf("%d-->",te->data);
      te = te->next ;
      i++ ;
    }
  
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data  for the doubly ") ;
scanf("%d",&ptr->data) ;
ptr->next =  NULL ;
ptr->prev = NULL; 
  if(head == NULL)
  {
    head  = ptr  ;
    tail = ptr  ;
    ptr->next = NULL ;
    ptr ->prev = NULL ;
    
  }
  else if(head == tail)
  {
    node *temp = tail  ;
    temp->next = ptr  ;
    tail = ptr  ;
    ptr->next = NULL ;
    ptr ->prev = temp  ; 
  }
  else 
  {
    node *t = tail  ;
    t->next = ptr  ;
    tail = ptr  ;
    ptr ->next = NULL ;
    ptr->prev = t ;
    
  }
}
int main()
{
  int x  ;
  printf("total element for the doubly linked list :") ;
  scanf("%d",&x) ;
  int i = 0 ;
  while(i!=x)
    {
      create() ;
      i++ ;
    }
  print(x) ;
  printf("\n");
  reverse(x) ;
  
  
}

// size of doubly linked list 
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct node 
{
int data ;
struct node *next  ;
struct node *prev ;
} ;
typedef struct node node  ;
node *head = NULL ;
node *tail = NULL ;
int counter(count)
{
  printf("\n size of the doubly linked list is %d ",count) ;
}
int print(int x)
{
  node *te = head  ;
  int i = 0 ;
  int count=0;
  while(i!=x)
    {
      printf("%d-->",te->data);
      te = te->next ;
      i++ ;
      count ++ ;
      
    }
  counter(count) ;
  
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data  for the doubly ") ;
scanf("%d",&ptr->data) ;
ptr->next =  NULL ;
ptr->prev = NULL; 
  if(head == NULL)
  {
    head  = ptr  ;
    tail = ptr  ;
    ptr->next = NULL ;
    ptr ->prev = NULL ;
    
  }
  else if(head == tail)
  {
    node *temp = tail  ;
    temp->next = ptr  ;
    tail = ptr  ;
    ptr->next = NULL ;
    ptr ->prev = temp  ; 
  }
  else 
  {
    node *t = tail  ;
    t->next = ptr  ;
    tail = ptr  ;
    ptr ->next = NULL ;
    ptr->prev = t ;
    
  }
}
int main()
{
  int x  ;
  printf("total element for the doubly linked list :") ;
  scanf("%d",&x) ;
  int i = 0 ;
  while(i!=x)
    {
      create() ;
      i++ ;
    }
  print(x) ;
  printf("\n");
  
}

// code --->ERROR !!!!!
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next  ;
} ;
typedef struct node node  ;
node *head = NULL ; 
node *tail = NULL; 
void del(int p , int x)
{
  node *h = head  ;
  node *t = tail ;
  int q =  0 ;
  while(q!=x)
    {
      if(h->data == p)
      {
        
        free(h) ; // free adn deletion logic 
        
        int z = 0;
        h= h->next ;
        
      }
      q++ ;
    }
  
}
void print(int x)
{
  int i = 0 ;
  node *ty = head  ;
  while(i!=x)
    {
      printf("%d-->",ty->data) ;
      ty = ty->next  ;
      i++ ;
    }
}
void create()
{
  node *temp = (node*)malloc(sizeof(node)) ;
  printf("enter the data ") ;
  scanf("%d",&temp->data);
  if(head==NULL)
  {
    head = temp  ;
    tail = temp  ;
    
  }
  else if(head == tail)
  {
    node *ptr = tail  ;
    ptr->next = temp  ;
    tail = temp  ;
    temp ->next = NULL ;
  }
  else
  {
    node *r = tail  ;
    r->next = temp ;
    tail = temp  ;
    
  }
}
int main()
{
  int x  ;
  printf("enter the size ") ;
  scanf("%d",&x);
  int i =0 ;
  while(i!=x)
    {
      create() ;
      i++  ;
      
    }

  print(x) ;
  printf("\n") ;
  int p ;
  printf("enter the number u wish to remove ") ;
  scanf("%d",&p) ;
  del(p,x) ;
  printf("\n") ;
  print(x) ;
  
}

#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next  ;
} ;
typedef struct node node  ;
// head and tail 
node *head = NULL ;
node *tail = NULL ;

// print->second linked list 
void printsec(int s )
{
  node *ptr = head  ;
  int im = 0 ;
  while(im!=s)
    {
     printf("%d ",ptr->data) ;
      ptr= ptr->next ;
    im++ ;
      
    }
}
// merger two  sorted  linked list 
void printfunc(int x)
{
  node *d  = head ;
  int i = 0 ;
  while(i!=x)
    {
      printf("%d ",d->data) ;
      i++ ;
      d = d->next  ;  
    }  
}
void compare(int num)
{
  int i = 0 ;

  for(int j = 0 ; j<num-1 ;j++)
    {
      node *com = head  ;
      for(int k = 0   ; k<num-1-j  ; k++)
        {
        
          if(com->data >com->next->data)
      {
        int temp = 0 ;
        temp = com->data  ;
        com->data = com->next ->data  ;
        com ->next->data = temp  ;
        
      }
      com = com->next  ;
      
      }
    }
  //node *end = tail  ;
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter the data for the linked list : ") ;
  scanf("%d",&ptr->data) ;
  node *t = head  ;
  if(head==NULL)
  {
    head = ptr ;
    tail  = ptr ;
    
  }
  else if (head == tail)
  {
    head->next = ptr  ;
    tail = ptr ;
    ptr->next = NULL ;
    
  }
  else
  {
    node *new = tail ;
    new->next = ptr  ;
    tail = ptr ;
    ptr->next = NULL; 
    
  }
  
}
int main()
{
  int num  ;
  printf("enter the elements for the first linked list") ;
  scanf("%d",&num) ;
  int z =0 ;
  while(z!=num)
    {
      create() ;
      z++ ;
    }
  printfunc(num) ;
  printf("\n") ;
  compare(num) ;
  printf("\n") ;
  printfunc(num) ;
  printf("\n the second linked list :") ;
  int s ;
  printf("\nenter the number :") ;
  scanf("%d",&s) ;
  int m = 0;
  while(m!=s)
    {
      create(s) ;
      m++ ;
      
    }
  printf("\n") ;
  printsec(s) ;
  
  
}

// code --->
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next  ;
} ;
typedef struct node node  ;
node *head = NULL ; 
node *tail = NULL; 

void del(int p , int x)
{
  node *h = head  ;
  node *pn = head ;
  node *t = tail ;
  int q =  0 ;
  while(q!=x)
    {
      if(h->data==p)
      {
        break ;
      }
      pn= h  ;
      h = h ->next ;
      q++ ;
    }
   
  pn->next = h->next  ;
  free(h) ;
  
}

void print(int x)
{
  int i = 0 ;
  node *ty = head  ;
  while(i!=x)
    {
      printf("%d-->",ty->data) ;
      ty = ty->next  ;
      i++ ;
    }
}
void create()
{
  node *temp = (node*)malloc(sizeof(node)) ;
  printf("enter the data ") ;
  scanf("%d",&temp->data);
  if(head==NULL)
  {
    head = temp  ;
    tail = temp  ;
    
  }
  else if(head == tail)
  {
    node *ptr = tail  ;
    ptr->next = temp  ;
    tail = temp  ;
    temp ->next = NULL ;
  }
  else
  {
    node *r = tail  ;
    r->next = temp ;
    tail = temp  ;
    
  }
}
int main()
{
  int x  ;
  printf("enter the size ") ;
  scanf("%d",&x);
  int i =0 ;
  while(i!=x)
    {
      create() ;
      i++  ;
      
    }

  print(x) ;
  printf("\n") ;
  int p ;
  printf("enter the number u wish to remove ") ;
  scanf("%d",&p) ;
  del(p,x) ;
  printf("\n") ;
  print(x-1) ;
  
}

// SORTED ARRYA MADE FROM 0,1,2
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node 
{
int data  ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail = NULL  ;

void sort(int num)
{
  
  int i = 0 ;

  for(int j = 0 ; j<num-1 ;j++)
    {
      node *com = head  ;
      for(int k = 0   ; k<num-1-j  ; k++)
        {
        
          if(com->data >com->next->data)
      {
        int temp = 0 ;
        temp = com->data  ;
        com->data = com->next ->data  ;
        com ->next->data = temp  ;
        
      }
      com = com->next  ;
      
      }
    
  //node *end = tail  ;
}
}
void printfunc(int num )
{
  int i = 0 ;
  node *j = head ;
  while(i!=num)
    {
      printf("%d-->",j->data) ;
      j= j->next ;
      i++ ; 
    }
}
void create()
{
  node *ptr =(node *)malloc(sizeof(node)) ;
  printf("enter the data within [0,2] :");
  scanf("%d",&ptr->data) ;
  if(head == NULL) 
  {
    head = ptr  ;
    tail = ptr   ;
  }
  else   if(head == tail)
  {
    node *y = tail  ;
   y ->next = ptr  ;
    tail = ptr ;
    ptr->next = NULL ;
  }
  else {
    node *g = tail  ;
    g ->next = ptr  ;
    tail = ptr  ;
    ptr->next = NULL ;
  }
  
}
int main()
{
  int num  ;
  printf("enter the number of data elemtns :");
  scanf("%d",&num) ;
  int i = 0 ;
  while(i!=num)
    {
      create() ;
      i++ ;
    }
  printfunc(num) ;
  printf("\n") ;
  sort(num) ;
  printfunc(num) ;
  
  
}

// SOTRED LIST MULTIPLICATION  GEEK FOR GEEKS Q-->130
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <math.h>
struct node 
{
int data ;
struct node *next ;
} ;
typedef struct node node  ;
node *head = NULL;
node *tail = NULL ;
// second linked list
void printnew(int n)
{
  node *val = head ;
  for(int i = 0 ; i<n  ; i++)
    {
      printf("%d",val->data) ;
      val = val->next ; 
    }
}
// second linked list
void createnew(){
  node *head = NULL ;
  node *tail = NULL ; 
   node *z =(node*)malloc(sizeof(node)) ;
  printf("enter data : ") ;
  scanf("%d",&z->data) ;
  if(head == NULL)
  {
    head = z  ;
    tail = z   ;
  }
  else if(head == tail)
  {
    node *m = tail  ;
    m->next = z ;
    tail = z ;
    z ->next = NULL ;
  }
  else{
    node *y  = tail  ;
    y->next= z  ;
    tail = z ;
    z->next = NULL ; 
  }
}
void createnum(int array[] , int num )
{
  node *p= head ;
  for (int i = 0  ; i<num  ; i++)
  {
    array[i] = p->data ;
    p = p->next ;
    
  }
  
}
void printnode(int num)
{
  node *ptr = head ;
  for(int i = 0 ; i<num ; i++)
    {
      printf("%d-->",ptr->data) ;
      ptr = ptr->next ;
    }
}
void create()
{
  node *temp =(node*)malloc(sizeof(node)) ;
  printf("enter data : ") ;
  scanf("%d",&temp->data) ;
  if(head == NULL)
  {
    head = temp  ;
    tail = temp   ;
  }
  else if(head == tail)
  {
    node *m = tail  ;
    m->next = temp  ;
    tail = temp ;
    temp ->next = NULL ;
  }
  else{
    node *y  = tail  ;
    y->next= temp  ;
    tail = temp ;
    temp ->next = NULL ; 
  }
}
int main()
{
  int num  ;
  printf("enter the data for the 1st linked list : ") ;
  scanf("%d",&num) ;
  for(int i = 0 ; i<num ; i++)
    {
    create() ;
    }
  printnode(num) ;
  int array[num] ;
  createnum(array ,num) ;
  printf("\n") ;
  for(int i = 0 ; i<num ; i++)
    {
      printf("%d",array[i]) ;
    }
  // num creation 
  int sum = 0 ;
  int x  = num-1 ;
  int i = 0 ;
  while(i!=num)
    {
      sum = sum + array[i]*pow(10,x);
      i++ ;
      x = x-1 ;
    }
  printf("\nthe number we got is %d ",sum) ;
  int z  = sum  ;
  int n ;
  printf("\nenter data for the second linked list : ") ;
  scanf("%d",&n) ;
  for(int j = 0 ; j<n ; j++)
    {
      createnew() ;
    }
  printf("\n") ;
  printnew(n) ;
  int newarray[n] ;
  createnum(newarray , n) ;
  int ne = 0 ;
  int q  = n-1 ;
  int l = 0 ;
  while(l!=n)
    {
      ne = ne + array[l]*pow(10,q);
      l++ ;
      q = q-1 ;
    }
  printf("\n%d is the value of the number",ne) ;
  int ms = ne*sum ;

  printf("\n") ;
  printf("the multiplication of the two linked list is %d ",ms) ;
  return 0 ;
}

// REORDERED LINKED LIST LEETCODE Q-143
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct node 
{
int data  ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail = NULL ;
void relate(int array[] , int num)
{
  printf("\nREORDERING THE LINKED LIST ");
  printf("\n") ;
  node *tx = head ;
  printf("%d-->",tx->data) ;
  for(int j = num-1 ; j>=0 ; j--)
    {
      printf("%d-->",array[j]) ;
    }
  
}
void save(int array[], int num)
  {
    
    node *p =head->next ;
    for(int i = 0 ; i<=num-1  ; i++ )
      {
        array[i] = p->data ;
        p= p->next ;
      }
    relate(array,num) ;
      
  }
void printout(int num)
{
  printf("\n");
  
  int i = 0 ;
  node *max = head->next ;
  node *min = tail ;
  node *tempo = tail ;
  printf("%d-->",head->data) ;
  while(i!=num-1)
    {
    
      printf("%d-->",max->data) ;
      max = max->next ;
      i++ ;
  
    }
  int array[num-1] ;
  save(array , num-1) ;
}
void create()
{
  node *temp = (node*)malloc(sizeof(node)) ;
  printf("enter data : ") ;
  scanf("%d",&temp->data) ;
  if(head == NULL)
  {
    head= temp  ;
    tail = temp  ;
  }
  else if (head == tail)
  {
    node *te = tail ;
    te->next = temp  ;
    tail = temp  ;
    temp ->next = NULL ;
  }
  else{
    node *tm = tail  ;
    tm ->next = temp ;
    tail = temp  ;
    temp ->next = NULL; 
    
  }
}
int main()
{
  int num  ;
  printf("the size of the linked list : ") ;
  scanf("%d",&num) ;
  for(int i = 0 ; i<num ; i++)
    {
      create() ;
    }
  printout(num) ;
}
//Y->point interection detection q-134 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node 
{
int data  ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail = NULL ;
node *head_setter = NULL ;
node *tail_setter = NULL ;
void checker(int num , int r)
{
  node *f = tail_setter  ;
  node *mi = head->next ;
  if(f->next==mi)
  {
    printf("\nTRUE !!") ;
  }
  else {
    printf("\nFALSE ") ;
  }
}
void printnew(int r)
{
  int m = 0  ;
  node *h = head_setter ;
  while(m!=r)
    {
      printf("%d--->",h->data) ;
      h = h->next ;
      m++ ;
    }
}
void createx()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
printf("data :") ;
  scanf("%d",&ptr->data) ;
  if(head_setter == NULL) 
  {
    head_setter = ptr  ;
    tail_setter  = ptr  ;
    
  }
  else if (head_setter == tail_setter)
  {
    node *b = tail_setter  ;
    b ->next  = ptr  ;
    tail_setter = ptr  ;
    ptr->next = head ->next ;
    
  }
  else{
    node *u  = tail_setter;  ;
    u->next  = ptr  ;
    tail_setter = ptr  ;
    ptr ->next  = head->next ;
  }
   
}
void print(int num)
{
  node *n = head  ;
  int i = 0 ;
  while(i!=num)
    {
      printf("%d--->",n->data) ;
      n = n->next ;
      i++ ;
      
    }
  
}
void create()
{
  node *temp = (node*)malloc(sizeof(node)) ;
  printf("data :") ;
  scanf("%d",&temp->data) ;
  if(head == NULL)
  {
    head = temp  ;
    tail = temp  ;
    
  }
  else if(head == tail)
  {
    node *x  = tail  ;
    x->next = temp  ;
    tail = temp ;  ;
    //temp->next =NULL ;
  }
  else 
  {
    node *g = tail  ;
    g->next = temp ;
    tail = temp ;
    //temp ->next  = NULL; 
  }
}
int main()
{
  int num  ;
  printf("enter the data : ") ;
  scanf("%d",&num) ;
   for(int i = 0 ; i<num ; i++)
     {
       create() ;
       
     }
  print(num) ;
  // 2nd linked list 
  int r  ;
  printf("\nenter the data for 2nd linked list")  ;
    scanf("%d",&r);
  int j = 0 ;
  while(j!=r) 
    {
      createx();
      j++ ;
    }
  printnew(r) ;
  checker(num , r) ;
  
}
// code for segrating the odd and even element in the linked list 
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
struct node 
{
int data ;
struct node *next ;
} ;
typedef struct node node ;
node *head = NULL ;
node *tail =  NULL ;

int checker(int num)
{
  int even[num] ;
  int odd[num] ;
  node *mal = head ;
  node *tal = tail ;
  //int i = 0 ;
  for(int i = 0 ; i<num ; i++)
    {
     
      if((mal->data)%2==0)
      {
        even[i] = mal->data ;
      
      }
      else
      {
        odd[i] = mal->data ;
        
      }
       mal = mal ->next ;
    }
  int ch ;
  printf("\nenter the choice ") ;
  scanf("%d",&ch) ;
  if(ch==1)
  {
  for(int i = 0 ; i<num ; i++)
    {
      printf("%d-->",even[i]) ;
    }
  }
  else if (ch==2)
  {
    for(int i = 0 ; i<num ; i++)
    {
      printf("%d-->",odd[i]) ;
    }
  }
  else {
    printf("wrong choice ") ;
  }
}
void printnode(int num)
{
  node *temp = head;
  int j= 0;
  while(j!=num)
    {
      printf("%d-->",temp->data) ;
      temp = temp->next ;
      j++ ;
    }
}
void create()
{
  node *ptr = (node*)malloc(sizeof(node)) ;
  printf("enter data for node ") ;
  scanf("%d",&ptr->data) ;
  if(head==NULL)
  {
    head = ptr ;
    tail  = ptr ;
  }
  else if (head == tail)
  {
    node *y = tail  ;
    y->next = ptr  ;
   tail = ptr  ;
   // ptr ->next = NULL  ;
  }
  else 
  {
    node *mx = tail  ;
    mx ->next = ptr  ;
    tail = ptr   ;
   // mx ->next=NULL ;
      
  }
}
int main()
{
  int num ;
  printf("enter the size for the linked list : ") ;
  scanf("%d",&num) ;
  int w = 0;
  while(w!=num)
    {
      create() ;
      w++ ;
    }
  printnode(num) ;
  checker(num) ;
  
