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

	printf("--- 신규회원 가입 --- \n");
	printf("ID 입력 : ");
	scanf_s("%s", member->ID, 80);

	printf("비밀번호 입력 : ");
	scanf_s("%s", member->PASS, 80);


	// 암호화
	int len = strlen(member->PASS);
	for (int i = 0; i < len; i++)
	{
		member->PASS[i] ^= KEY;  // 일단 고정
	}


	printf("이름 입력 : ");
	scanf_s("%s", member->NAME, 80);

	member->isUsed = true;


	int index = Hash(member->ID);

	InsertTail(member);  // 더블 링크드 리스트에 넣는다.
	Insert(index, member);

	printf("생성완료! \n");

	printf("Press any Key....");
	_getch();  // 아무 키나 1개 입력 받기
	puts("");
}

void Login() 
{
	system("cls");

	char LoginID[80];
	char LoginPASS[80];

	printf("ID 입력 : ");
	scanf_s("%s", LoginID , 80);

	printf("PASS 입력 : ");
	scanf_s("%s", LoginPASS, 80);


	// 아이디를 통해 index를 가져온다.
	int index = Hash(LoginID);
	
	// 위치를 찾아 비밀번호가 맞는지 확인
	CheckIDandPass(index, LoginID, LoginPASS);

	printf("Press any Key....");
	_getch();  // 아무 키나 1개 입력 받기
	puts("");
}

void ShowAllID()
{
	system("cls");
	PrintList();

	printf("Press any Key....");
	_getch();  // 아무 키나 1개 입력 받기
	puts("");

}

void SearchID() 
{
	printf("--회원검색--\n");
	char LoginID[80];

	system("cls");
	printf("아이디 입력 : ");
	scanf_s("%s", LoginID, 80);

	// 아이디를 통해 index를 가져온다.
	int index = Hash(LoginID);

	CheckID(index, LoginID);

	printf("Press any Key....");
	_getch();  // 아무 키나 1개 입력 받기
	puts("");
}

void QuitID() 
{
	system("cls");
	
	char LoginID[80];
	printf("삭제할 ID 입력 : ");
	scanf_s("%s", LoginID, 80);

	int index = Hash(LoginID);

	if (Delete(index, LoginID))
	{
		if (Delete(LoginID))
			printf("삭제 완료되었습니다.\n");
	}
	else
		printf("ID가 잘못되었습니다.\n");
	

	printf("Press any Key....");
	_getch();  // 아무 키나 1개 입력 받기
	puts("");
}

void Print()
{
	system("cls");
	printf("==MENU==\n");
	printf("1. 가입 \n");
	printf("2. 로그인\n");
	printf("3. 전체회원보기 \n");
	printf("4. ID검색\n");
	printf("5. 탈퇴\n");
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




