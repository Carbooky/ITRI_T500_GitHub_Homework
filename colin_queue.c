#include <stdio.h>
#include <stdlib.h>
#define NUM 5           //定義佇列大小

void addQueue(int);      //宣告addQueue副程式
int deletQueue(void);      //宣告deletQueue副程式
void printQueue(void);  //宣告列印目前環形佇列的內容之副程式

typedef struct queue {
  int CQueue[NUM];
  int Rear;
  int Front;
} Queue;
Queue qu;

int main(void) {  //主程式

    int op=0,item;
    qu.Rear = 0;
    qu.Front = 0;
        printf("===============程式描述===========================\n");
        printf("= 程式目的：環形佇列進行Add Queue以及Delet Queue =\n"); 
        printf("==================================================\n");   
    while(1) {
        printf("==============================================\n");
        printf("=   1.Add Queue(加入)                        =\n");
        printf("=   2.Delete Queue(刪除)                     =\n");
        printf("=   3.顯示目前環形佇列的內容                 =\n");
        printf("=   4.結束                                   =\n");    
        printf("==============================================\n");
        printf("請輸入你的操作：");
        scanf("%d",&op);
        switch(op) {
            case 1: printf("請輸入你要加入的資料:");
                scanf("%d",&item);
                addQueue(item);
                break;
            case 2: item = deletQueue( );
                if(item != -1)
                    printf("%d 是從環形佇列刪除的資料\n",item);
                break;
            case 3: printQueue( );
                break;
            case 4: printf("\n");       //結束
                return (0);  
       }
    }
  system("pause");     //使程式暫停在執行畫面讓我們看到結果
  return 0;
}

void addQueue(int item) {  //加入item到佇列中的副程式

  qu.Rear = (qu.Rear+1)%NUM;
  if((qu.Rear)%NUM == qu.Front) {
    printf("環形佇列是滿的!\n");
    system("pause");
    exit(1);
  } else
    qu.CQueue[qu.Rear] = item;
}

int deletQueue(void) { //從佇列中刪除item

  if(qu.Front == qu.Rear) {
    printf("環形佇列是空的!\n");
    system("pause");
    exit(1);
  } else {
    qu.Front = (qu.Front+1)%NUM;
    return qu.CQueue[qu.Front];
  }  
}

void printQueue(void)   //顯示目前環形佇列的內容之副程式
{
  int i;
  printf("目前環形佇列的內容：");
  for(i=qu.Rear;i!=qu.Front;i=(i+NUM-1)%NUM)
    printf("%d ",qu.CQueue[i]);
  printf("\n");  
}
