#include "stdafx.h"
#include "Management.h"

#include "HashTable.h"


void InitComponent()
{
	initialize();
	InitializeLL();
}

void Join()
{
	system("cls");

	Member *member = (Member *)malloc(sizeof(Member));

	printf("--- �ű�ȸ�� ���� --- \n");
	printf("ID �Է� : ");
	scanf_s("%s", member->ID, 80);

	printf("��й�ȣ �Է� : ");
	scanf_s("%s", member->PASS, 80);


	// ��ȣȭ
	int len = strlen(member->PASS);
	for (int i = 0; i < len; i++)
	{
		member->PASS[i] ^= KEY;  // �ϴ� ����
	}


	printf("�̸� �Է� : ");
	scanf_s("%s", member->NAME, 80);

	member->isUsed = true;


	int index = Hash(member->ID);

	InsertTail(member);  // ���� ��ũ�� ����Ʈ�� �ִ´�.
	Insert(index, member);

	printf("�����Ϸ�! \n");

	printf("Press any Key....");
	_getch();  // �ƹ� Ű�� 1�� �Է� �ޱ�
	puts("");
}

void Login() 
{
	system("cls");

	char LoginID[80];
	char LoginPASS[80];

	printf("ID �Է� : ");
	scanf_s("%s", LoginID , 80);

	printf("PASS �Է� : ");
	scanf_s("%s", LoginPASS, 80);


	// ���̵� ���� index�� �����´�.
	int index = Hash(LoginID);
	
	// ��ġ�� ã�� ��й�ȣ�� �´��� Ȯ��
	CheckIDandPass(index, LoginID, LoginPASS);

	printf("Press any Key....");
	_getch();  // �ƹ� Ű�� 1�� �Է� �ޱ�
	puts("");
}

void ShowAllID()
{
	system("cls");
	PrintList();

	printf("Press any Key....");
	_getch();  // �ƹ� Ű�� 1�� �Է� �ޱ�
	puts("");

}

void SearchID() 
{
	printf("--ȸ���˻�--\n");
	char LoginID[80];

	system("cls");
	printf("���̵� �Է� : ");
	scanf_s("%s", LoginID, 80);

	// ���̵� ���� index�� �����´�.
	int index = Hash(LoginID);

	CheckID(index, LoginID);

	printf("Press any Key....");
	_getch();  // �ƹ� Ű�� 1�� �Է� �ޱ�
	puts("");
}

void QuitID() 
{
	system("cls");
	
	char LoginID[80];
	printf("������ ID �Է� : ");
	scanf_s("%s", LoginID, 80);

	int index = Hash(LoginID);

	if (Delete(index, LoginID))
	{
		if (Delete(LoginID))
			printf("���� �Ϸ�Ǿ����ϴ�.\n");
	}
	else
		printf("ID�� �߸��Ǿ����ϴ�.\n");
	

	printf("Press any Key....");
	_getch();  // �ƹ� Ű�� 1�� �Է� �ޱ�
	puts("");
}

void Print()
{
	system("cls");
	printf("==MENU==\n");
	printf("1. ���� \n");
	printf("2. �α���\n");
	printf("3. ��üȸ������ \n");
	printf("4. ID�˻�\n");
	printf("5. Ż��\n");
}


unsigned Hash(char *key)
{
	int len = strlen(key);
	unsigned total = 0;
	int i;
	for (i = 0; i < len; i++)
		total += key[i];

	if (total < 0)
		total *= -1;

	return total % HASHINDEX;
}




