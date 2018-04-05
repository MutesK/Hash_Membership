#include "stdafx.h"
#include "HashTable.h"

HashList HashTable[HASHINDEX];

void initialize() // �ʱ�ȭ
{
	for (int i = 0; i < HASHINDEX; i++)
	{
		HashTable[i].head = nullptr;
		HashTable[i].tail = nullptr;
		HashTable[i].numOfData = 0;
	}
}

void Insert(int index, Member* Data)
{
	HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
	newNode->Member = Data;
	newNode->next = nullptr;

	if (HashTable[index].head == nullptr)
	{
		HashTable[index].head = newNode;
		HashTable[index].tail = HashTable[index].head;
	}
	else
	{
		HashTable[index].tail->next = newNode;
		HashTable[index].tail = newNode;
	}

	HashTable[index].numOfData++;

}

bool Delete(int index, char *ID)
{
	HashNode *delNode = HashTable[index].head;
	HashNode *befNode = nullptr;
	bool ret = false;

	if (HashTable[index].numOfData > 0)
	{
		while (delNode != nullptr)
		{
			if (strcmp(delNode->Member->ID, ID) == 0)
			{
				ret = true;

				if (delNode == HashTable[index].head)
				{
					HashTable[index].head = HashTable[index].head->next;
				}
				else if (delNode == HashTable[index].tail)
				{
					befNode->next = nullptr;
					HashTable[index].tail = befNode;
				}
				else
				{
					befNode->next = delNode->next;
					delNode->next = nullptr;
				}

				free(delNode);
				HashTable[index].numOfData--;
				return ret;

			}

			befNode = delNode;
			delNode = delNode->next;
		}
	}

	return ret;
}




bool CheckIDandPass(int index, char *ID, char *Pass)
{
	HashNode *pNode = HashTable[index].head;

	if (HashTable[index].numOfData > 0)
	{
		while (pNode != nullptr)
		{
			if (strcmp(pNode->Member->ID, ID) == 0) // ���̵� ���ٸ�
			{
				int len = strlen(Pass);
				for (int i = 0; i < len; i++)
					*(Pass + i) ^= KEY;

				if (memcmp(Pass, pNode->Member->PASS, len) == 0)
				{
					printf("�α��� �����߽��ϴ�. \n");
					return true;
				}
				else
				{
					printf("�α��ο� ����. \n");
					return false;
				}
			}

			pNode = pNode->next;
		}
	}

	printf("�α��ο� ����. \n");
	return false;
}

bool CheckID(int index, char *ID)
{
	HashNode *pNode = HashTable[index].head;

	if (HashTable[index].numOfData > 0)
	{
		while (pNode != nullptr)
		{
			if (strcmp(pNode->Member->ID, ID) == 0) // ���̵� ���ٸ�
			{
				printf("���̵� ã�� ����!! \n");
				printf("���̵� : %s \n", pNode->Member->ID);
				printf("PASSWORD(ENC) : ");
				int len = strlen(pNode->Member->PASS);
				for (int i = 0; i < len; i++)
				{
					printf("%c", pNode->Member->PASS[i]);
				}
				printf("\n");
				return true;
			}
			pNode = pNode->next;
		}
		printf("���̵� �߸��Ǿ����ϴ�. \n");
	}

	return false;
}