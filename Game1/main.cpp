#include "Tools.h"
#include "GameManager.h"
#include "conio.h"

int main() {
	GameManager gameManager;


	cout << "����Ϸ��� �ƹ� Ű�� ��������...";
	(void)_getch();
	
	while (true) {
		gameManager.update();
	}

	return 0;
}