/*
	SINGLE LIST.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _List_H

typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node *Next;
};

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;


List CreateList(void);
List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
PtrToNode Find( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void Delete( Position P, List L );
PtrToNode Header( List L );
PtrToNode First( List L );
ElementType Retrieve( Position P );//检索

#endif  /* _List_H */

/* 创建空链表 */
List CreateList(void)
{
	PtrToNode Head = NULL;
	
	Head =(PtrToNode)malloc(sizeof(struct Node));
	if(Head == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	} 
	return Head;	
}

/* 清空链表 */
List MakeEmpty( List L )
{
	free( L->Next );
	memset( &(L -> Element), 0 ,sizeof(ElementType) );
	return L;
}

/* 判断是否是空链表 int */
int IsEmpty( List L )
{
	return L->Next == NULL;	
}

/* P是否是最后一个元素 */
int IsLast( Position P, List L )
{
	return P->Next == NULL;
}

PtrToNode Find( ElementType X, List L )
{
	PtrToNode tmpn = NULL:
	
	/* no good
	tmpn = L;
	while( tmpn->Next != NULL && tmpn=tmpn->Next ) // 注意地址是不一定连续的，所以不能 tmpn++
	{
		if( tmpn->Element == X)
		{
			return tmpn;
		}
	}
	return NULL;
	*/
	tmpn = L->Next;
	while( (tmpn->Next != NULL) && (tmpn->Element != X) )
	{
		tmpn = tmpn->Next;
	}
	return tmpn;
}

/* 插入元素X */
void Insert( ElementType X, List L, Position P )
{
	PtrToNode tmpn = L;
	
	while( tmpn->Next != NULL && tmpn->Next != P)
	{
		tmpn = tmpn->Next;
	}
	
	P = (Position)malloc(sizeof(struct Node));
	if(P == NULL)
	{
		printf("malloc failed\n");
		return;
	}
	P->Next = tmpn->Next;
	tmpn->Next = P;
}



void Delete( ElementType X, List L )
{
	PtrToNode tmpn = L;
	Position  tmpP = NULL:
	
	/* 找出前驱结点 */
	while( (tmpn->Next != NULL)&&((tmpn->Next)->Element != X) )
	{
		tmpn = tmpn->Next;
	}
	
	if( !(IsLast(tmpn)) )
	{
		tmpP = (Position)malloc(sizeof(struct Node));
		if(tmpP == NULL)
		{
			printf("malloc failed\n");
			return; 
		}
		tmpP = tmpP
	}
	
}

int main(void)
{
	int ret = 0;
	List L = NULL;

	if(( L = CreateList()) == NULL)
	{
		printf(" Create list failed\n");
		return -1;
	}
	printf("%p\n",L);

	if( IsEmpty(L) )
	{
		printf("It's an empty list\n");
	}	

	MakeEmpty(L);
	
	return 0;
}
