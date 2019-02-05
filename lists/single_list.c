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
int IsLast( Position P);
PtrToNode Find( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void Delete( ElementType X, List L );
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
int IsLast( Position P)
{
	return P->Next == NULL;
}

PtrToNode Find( ElementType X, List L )
{
	PtrToNode tmpn = NULL;
	
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
	Position tmpm = NULL;

	/* 无需再前驱结点，P就是 */
	tmpm = (Position)malloc(sizeof(struct Node));
	if(tmpm == NULL)
	{
		printf("malloc failed\n");
		return;
	}
	tmpm->Element = X;
	tmpm->Next = P->Next;
	P->Next = tmpm;
}



void Delete( ElementType X, List L )
{
	PtrToNode tmpn = L;
	Position  tmpP = NULL;
	
	/* 找出前驱结点 */
	while( (tmpn->Next != NULL)&&((tmpn->Next)->Element != X) )
	{
		tmpn = tmpn->Next;
	}
	
	
	if( !(IsLast(tmpn)) )
	{
		tmpP = tmpn->Next;
		tmpn->Next = tmpP->Next;
		free( tmpP );
	}
}

PtrToNode Header( List L )
{
	return L;
}

PtrToNode First( List L )
{
	return L->Next;
}

ElementType Retrieve( Position P )
{
	return P->Element;
}

void Print( List L )
{
	Position tmp = L;
	int i = 0;
	
	/* 先走到下一个元素再打印，防止头节点被误处理 */
	while(tmp->Next != NULL)
	{
		tmp = tmp->Next;
		printf("Element%d: %d\n",i, tmp->Element);
		i++;
	}
}

int main(void)
{
	int ret = 0;
	List L = NULL;
	ElementType X1 = 2019;


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

	Insert( X1, L, (Position)L );
	Print( L );

	MakeEmpty(L);
	
	return 0;
}
