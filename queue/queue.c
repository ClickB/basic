/* 
	队列抽象模型 queue ADT
	特点：
		在一端（队尾rear）插入 元素，在另一端（队头front）删除元素。	
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef _QUEUE_H

typedef int ElementType;

struct QueueRrecord
{
	int Size;
	int Rear;
	int Front;
	int Capacity;
	ElementType *Array;
};

typedef struct QueueRrecord* Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( ElementType X, Queue Q );
ElementType Front( Queue Q );
void Dequeue( Queue Q );
ElementType FrontAndDequeue( Queue Q );

#endif // _QUEUE_H


int IsEmpty( Queue Q )
{
	return Q->Size == 0;
}

int IsFull( Queue Q )
{
	return Q->Size == Q->Capacity;
}

void MakeEmpty( Queue Q )
{
	Q->Size = 0;
	Q->Rear = 0;
	Q->Front = 1;
}


Queue CreateQueue( int MaxElements )
{
	Queue q = NULL;
	
	q = (Queue)malloc( sizeof(struct QueueRrecord) );
	if( q == NULL )
	{
		printf("queue: malloc failed\n");
		return NULL;
	}	
	q->Capacity = MaxElements;
	MakeEmpty( q );
	q->Array = (ElementType *)malloc(sizeof(ElementType) * q->Capacity);

	if(q->Array == NULL)
	{
		printf("array: malloc failed\n");
		free( q );
		return NULL;
	}

	return q; 
}

void DisposeQueue( Queue Q )
{
	free( Q->Array );
	free( Q );
}

/* 循环数组 */
static int Succ( int value, Queue Q )
{
	if( ++value == Q->Capacity )
	{
		value = 0;
	}
	return value;
}

void Enqueue( ElementType X, Queue Q )
{
	if( IsFull( Q ) )
	{
		printf("enqueue failed: full\n");
		return;
	}
	else
	{
		Q->Rear = Succ( Q->Rear, Q );
		Q->Size ++;
		Q->Array[Q->Rear] = X;                                    
	}
}

ElementType Front( Queue Q );
void Dequeue( Queue Q );
ElementType FrontAndDequeue( Queue Q );

int main(void)
{
	Queue q= NULL;
	
	q = CreateQueue( 10 );
	
	//Dequeue( q );

	return 0;
}

