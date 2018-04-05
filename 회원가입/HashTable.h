#pragma once

#include "Node.h"


// 싱글 링크드 리스트용
struct HashNode
{
	Member* Member;
	HashNode *next;
};

struct HashList
{
	HashNode *head;
	HashNode *tail;
	int numOfData;
};

/*
=============  Linked List ================
*/
void initialize(); // 초기화
void Insert(int index, Member* Data);
bool Delete(int index, char *ID);
bool CheckIDandPass(int index, char *ID, char *Pass);
bool CheckID(int index, char *ID);

