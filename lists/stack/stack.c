/*

 栈抽象数据类型  ADT
 单链表实现

 栈的特点：后进先出
 链表采取头插，头删，比尾插尾删可以减少遍历

 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _STACK_H

typedef int ElementType;

struct Node{
	ElementType Element;
	struct Node* Next;	
};

typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty( Stack S );
Stack CreateStack( void );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
ElementType Pop( Stack S );

#endif // _STACK_H



int IsEmpty( Stack S )
{
	return S->Next == NULL;
}

Stack CreateStack( void )
{
	Stack s = (Stack)malloc(sizeof(struct Node));
	if( s == NULL )
	{
		printf( "malloc failed\n" );	
	}
	s->Next = NULL;
	return s;
}

/* 销毁栈  */
void DisposeStack( Stack S )
{
	if( S != NULL )
	{
		free( S );
	}
}

void MakeEmpty( Stack S )
{
	if( S == NULL )
	{
		printf("Please create stack first\n");
		return;
	}
	else
	{
		while( !IsEmpty( S ) )
		{
			Pop( S );
		}
	}
}

void Push( ElementType X, Stack S )
{
	PtrToNode P = NULL;	

	P = (PtrToNode)malloc(sizeof(struct Node));
	if( P == NULL )
	{
		printf("malloc failed\n");
		return;
	}
	P->Element = X;
	P->Next = S->Next;
	S->Next = P;
	printf( "push %d\n", X );
}

ElementType Top( Stack S )
{
	if( IsEmpty( S ) )
	{
		printf("Empty stack\n");
        return -1;
	}
	return (S->Next)->Element;
}

ElementType Pop( Stack S )
{
	PtrToNode P = NULL;
	ElementType X = 0;
	if( IsEmpty( S ) )
	{
		printf("Empty stack\n");
        return -1;
	}
	P = S->Next;
	X = (S->Next)->Element;
	S->Next = (S->Next)->Next;
	free(P);
	printf("pop %d\n", X );
	return X;
}

int main( void )
{
	Stack S = NULL;

	S = CreateStack();	
	Push( 1, S );
	Push( 2, S );
	Push( 3, S );
	Push( 4, S );
	Push( 5, S );
	MakeEmpty( S );
	DisposeStack( S );
	return 0;
}
