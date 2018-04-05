#include "stdafx.h"
#include "Management.h"
#include "Node.h"

int main()
{
	InitComponent();

	while (true)
	{

		int sel = 0;
		Print();
		printf("ют╥б : ");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1:
			Join();
			break;
		case 2:
			Login();
			break;
		case 3:
			ShowAllID();
			break;
		case 4:
			SearchID();
			break;
		case 5:
			QuitID();
			break;
		}

	}
    return 0;
}
