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
// 멤버 Data를 넣고 해당 Node*를 리턴
void InsertHead(Member* Data);
// 멤버 Data를 넣고 해당 Node*를 리턴
void InsertTail(Member* Data);
bool Delete(char * ID);
void PrintList();