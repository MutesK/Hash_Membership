#pragma once

#include "Node.h"


// �̱� ��ũ�� ����Ʈ��
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
void initialize(); // �ʱ�ȭ
void Insert(int index, Member* Data);
bool Delete(int index, char *ID);
bool CheckIDandPass(int index, char *ID, char *Pass);
bool CheckID(int index, char *ID);

