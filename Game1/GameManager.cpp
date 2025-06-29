#include "GameManager.h"
#include "Tools.h"

void GameManager::init()
{
}

void GameManager::menu()
{
    std::cout << "===== ���� �޴� =====\n";
    std::cout << "1. ���� ����\n";
    std::cout << "2. ���� ����\n";
    std::cout << "��ȣ�� �����ϼ���: ";

    int input = 0;
    cin >> input;

    switch (input) {
    case 1:
        gameState_ = GameState::BATTLE;
        selectCharacter();
        startBattle();
        system("cls");
        break;
    case 2:
        gameState_ = GameState::EXIT;
        break;
    default:
        std::cout << "�߸��� �Է��Դϴ�.\n";
        break;
    }
}

void GameManager::startBattle()
{
}

void GameManager::update()
{
    switch (gameState_) {
    case GameState::MENU:
        system("cls");
        menu();
        break;

    case GameState::BATTLE:
        battleManager_.printMap();
        (void)_getch();
        system("cls");
        break;

    case GameState::EXIT:
        std::cout << "������ �����մϴ�.\n";
        exit(0);  // ���α׷� ����
        break;
    }
}

void GameManager::endBattle()
{
}

void GameManager::selectCharacter()
{
}
