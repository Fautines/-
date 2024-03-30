#include <iostream>
#include <stdlib.h>
#include <io.h>
#include <cmath>
#include <time.h>


using namespace std;


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 11 //初始容量

typedef int Status;
typedef int QElemType;//定义数据类型

//循环队列的顺序存储结构
typedef struct {
	QElemType data[MAXSIZE];
	int front; //头指针
	int rear;//尾指针，队列非空时，指向队尾元素的下一个位置
}SqQueue;

Status visit(QElemType item) {
	printf("%d", item);
	return OK;
}

//初始化空队列
Status InitQueue(SqQueue* sQ) {
	sQ->front = 0;
	sQ->rear = 0;
	return OK;
}

//将队列清空
Status ClearQueue(SqQueue* Q) {
	Q->front = Q->rear = 0;
	return OK;
}

//判断队列是否为null
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

//返回队列中的元素个数
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//返回队头元素
Status GetHead(SqQueue Q, QElemType* e) {
	if (Q.front == Q.rear)//是否为空队列
		return ERROR;
	*e = Q.data[Q.front];
	return OK;
}

//在队尾插入元素
Status EnQueue(SqQueue* Q, QElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)//队列已满
		return ERROR;

	Q->data[Q->rear] = e;//插入队尾
	Q->rear = (Q->rear + 1) % MAXSIZE;//尾部指针后移，如果到最后则转到头部
	return OK;
}

//元素出队
Status DeQueue(SqQueue* Q, QElemType* e) {
	if (Q->front == Q->rear)//队列空
		return ERROR;
	*e = Q->data[Q->front];//返回队头元素
	Q->front = (Q->front + 1) % MAXSIZE;//队头指针后移，如到最后转到头部
	return OK;
}

//遍历队列元素
Status QueueTraverse(SqQueue Q) {
	int i = Q.front;
	while ((i + Q.front) != Q.rear) {
		visit(Q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
	return OK;
}

int main() {

	Status j;
	int i = 0, l;
	QElemType d;
	SqQueue Q;
	InitQueue(&Q);

	//入队１０个元素
	for (int i = 0;i < MAXSIZE - 1; i++) {
		EnQueue(&Q, i);
	}
	QueueTraverse(Q);

	printf("依次出队:");
	for (l = 1;l <= MAXSIZE;l++)
	{
		DeQueue(&Q, &d);
		printf("d= %d,", d);
	}

	return 0;
}