/* link list (連結串列) */  
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
  
/* 定義結構型態 */  
typedef struct link_node{  
  // int data;  
   char data[30];
   struct link_node *link;  
} LINK_NODE;  
  
  char Buffer_Data[30];
  LINK_NODE *list=NULL;  
  
  
/* 產生新節點 */  
LINK_NODE *new_node(char * data){  
   LINK_NODE *node;  
   node=(LINK_NODE *) malloc(sizeof(LINK_NODE));/*<stdlib.h>*/  
     
   // 記憶體不足  
   if(node == NULL){ return NULL;}  
     
  // node->data=data;    
   strcpy(node->data,data);
   node->link=NULL;       
   return node;  
}  
  
  
/* 加入新的資料於最後 */  
LINK_NODE *push_node(LINK_NODE *list, char *  data) {  
   /*產生新節點*/  
   LINK_NODE *node=new_node(data);    
  
   // 加入第一個新節點  
   if(list==NULL){      
       list=node;  
   }else{  
       LINK_NODE *p=list;    
       // 取得最後一個節點  
       while(p->link!=NULL){p=p->link;}  
       p->link=node;  
   }     
  //usleep(1000000);
   
   return list;  
}  
  
  
/* 計算串列長度 */  
int get_length(LINK_NODE *list) {  
   LINK_NODE *p=list;  
   int count=0;    
   while(p!=NULL){      
       count++;    
       p=p->link;    
   }  
     
   return count;  
}  
  
  
 
/* 印出所有串列的所有資料 */  
int display(LINK_NODE *list) {  
   LINK_NODE *p=list;  
   while(p!=NULL){   
       printf("Time : %s\n",p->data);/*<stdio.h>*/  
       p=p->link;    
   }  
   
   //usleep(2000000);
   return 1;  
}  
 
  const char* current_time() {
    struct timeval now;
    static char str[30];
    char* ptr;

    if(gettimeofday(&now,NULL)<0)  {
        perror("gettimeofday");
        exit(-1);
    }

    ptr = ctime(&now.tv_sec);
    strcpy(str,ptr+11);
    snprintf(str+8,sizeof(str)-8,".%06ld",now.tv_usec);
    
    return str;
}


void *SaveData(void) {
    while(1){
       sprintf(Buffer_Data,"%s",current_time());
       list=push_node(list,Buffer_Data); 
       printf("------------threadId1----------\n");    
       usleep(1000000);
    }
    return NULL;
 
 }
 
  
 void *DisplayData(void) {
    while(1){
       
       display(list);
       printf("------------threadId2----------\n");    
       usleep(2000000);
    }
    return NULL;
 
 }


  
  
/*主程式*/  
int main(){  
   
    pthread_t threadId1,threadId2;

    pthread_create(&threadId1,NULL,&SaveData,NULL);
    pthread_create(&threadId2,NULL,&DisplayData,NULL);
       
    while(1){
                     ;
   }
   
   return 0;  
} 
