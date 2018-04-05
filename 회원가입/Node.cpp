#include "stdafx.h"
#include "Node.h"

Node Head, Tail;

void InitializeLL()
{
	Head.next = nullptr;
	Head.next = &Tail;
	Tail.next = nullptr;
	Tail.prev = &Head;
}

void InsertHead(Member* Data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->member = *Data;

	newNode->prev = &Head;
	newNode->next = Head.next;

	newNode->next->prev = newNode;
	Head.prev = newNode;

}

void InsertTail(Member* Data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->member = *Data;

	newNode->prev = Tail.prev;
	newNode->next = &Tail;

	newNode->prev->next = newNode;
	Tail.prev = newNode;

}

bool Delete(char * ID)
{
	Node *pStart = Head.next;

	while (pStart != &Tail) // pStart != &Tail
	{
		if (strcmp(pStart->member.ID, ID) == 0)
		{
			Node *delNode = pStart;

			pStart->prev->next = pStart->next;
			pStart->next->prev = pStart->prev;

			printf("삭제가 완료되었습니다. \n");

			free(delNode);
			return true;
		}
		else
			pStart = pStart->next;
	}
	return false;
}

void PrintList()
{
	Node *pStart = Head.next;
	int i = 0;


	while (pStart != &Tail) // pStart != &Tail
	{
		i++;

		char decPass[80];
		int len = strlen(pStart->member.PASS);
		for (int i = 0; i <len; i++)
		{
			decPass[i] = pStart->member.PASS[i] ^ KEY;
		}
		decPass[len] = '\0';

		printf("# %d \n", i);
		printf("아이디 : %s \n", pStart->member.ID);
		printf("PASSWORD(ENC) : ");

		for (int i = 0; i < len; i++)
		{
			printf("%c", pStart->member.PASS[i]);
		}
		printf("\n");
		printf("PASSWORD(DEC) : %s \n", decPass);
		printf("이름 : %s \n\n\n", pStart->member.NAME);
		printf("\n\n");


		pStart = pStart->next;
	}

	printf("총회원 : %d \n", i);
}