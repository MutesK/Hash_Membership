#pragma once

struct Member
{
	char ID[80];
	char PASS[80];
	char NAME[80];
	bool isUsed;
};

struct Node
{
	Member member;
	Node *next;
	Node *prev;
};


/*
============= Double Linked List ================
*/
void InitializeLL();
// ��� Data�� �ְ� �ش� Node*�� ����
void InsertHead(Member* Data);
// ��� Data�� �ְ� �ش� Node*�� ����
void InsertTail(Member* Data);
bool Delete(char * ID);
void PrintList();