#include "GameManager.h"
#include "Pokemon/Pikachu.h"
#include "Pokemon/Kkobugi.h"
#include "Pokemon/Pairi.h"
#include "Pokemon/Naong.h"
#include "Pokemon/Majayong.h"
#include "Pokemon/Ttodogas.h"
#include "Tools.h"

void GameManager::init()
{
    gameState_ = GameState::MENU; 
    stageNumber_ = 1; 
    battleManager_.init();
}

void GameManager::menu()
{
    std::cout << "===== ���� �޴� =====\n";
    std::cout << "1. ���� ����\n";
    std::cout << "2. ���� ����\n";
    std::cout << "��ȣ�� �����ϼ���: ";

    int input = 0;
    std::cin >> input;

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
    battleManager_.init();
}

void GameManager::update()
{
    switch (gameState_) {
    case GameState::MENU:
        system("cls");
        menu();
        break;

    case GameState::BATTLE:
        std::cout << "���� ����!!\n";
        Sleep(1000);
        battleManager_.executeBattle();
        if (battleManager_.getLastResult() == BattleResult::COMPUTER_WIN) {
            std::cout << "Game Over! You lost.\n";
            Sleep(2000);
            gameState_ = GameState::MENU;
        } else if (battleManager_.getLastResult() == BattleResult::PLAYER_WIN) {
            std::cout << "You Win! Proceeding to next stage...\n";
            Sleep(2000);
            // Advance to next stage

   
        }
        break;

    case GameState::EXIT:
        std::cout << "������ �����մϴ�.\n";
        Sleep(2000);
        exit(0);
        break;
    }
}

void GameManager::selectCharacter()
{
    Pokemon* playerPokemon = nullptr;
    Pokemon* opponentPokemon = new Naong(Position(1, 3));

    unsigned int choice = 3;
    while (choice > 2) {

        system("cls");
        cout << "ĳ���͸� �����ϼ���.\n";
        cout << "\
0. Pikachu\n\
1. Kkobugi\n\
2. Pairi\n";
        cin >> choice;

        Position playerStPos = Position(1, 0);

        switch (choice) {
        case 0:
            playerPokemon = new Pikachu(playerStPos);
            break;
        case 1:
            playerPokemon = new Kkobugi(playerStPos);
            break;
        case 2:
            playerPokemon = new Pairi(playerStPos);
            break;
        default:
            system("cls");
            cout << "��ȿ���� ���� �Է� �Դϴ�.\n";
            Sleep(2000);
            break;
        }
    }

    string name = typeid(*playerPokemon).name();
    cout << "\nSelected Pokemon : " << name << endl;
    Sleep(1000);

    battleManager_.setHumanPokemon(playerPokemon);
    battleManager_.setComputerPokemon(opponentPokemon);
}
