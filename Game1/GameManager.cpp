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
        }
        else if (battleManager_.getLastResult() == BattleResult::PLAYER_WIN) {
            stageNumber_++; // Advance to next stage
            if (stageNumber_ > 3) { // FINAL WIN
                std::cout << "You Won all the stages!!! Congrats!!! \n";
                Sleep(2000);
                gameState_ = GameState::MENU;

            }
            else { // WIN PER STAGE
                std::cout << "You Won! Proceeding to next stage... \n";
                Sleep(2000);

                // Restore HP and reset map for next stage
                // Player's Pokemon stays, only opponent changes
                Pokemon& playerPokemon = battleManager_.getHumanPlayer()->getPokemon();
                playerPokemon.setPos(Position(1, 0));

                while (playerPokemon.getHp() < playerPokemon.getMaxHp()) {
                    playerPokemon.takeDamage(-1); // Heal by 1 until full
                }

                Pokemon* nextOpponent = createOpponentForStage(stageNumber_);
                nextOpponent->setPos(Position(1, 3));
                battleManager_.setComputerPokemon(nextOpponent);

                battleManager_.init();
                gameState_ = GameState::BATTLE;
            }
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

Pokemon* GameManager::createOpponentForStage(int stage) {
    Position OpponentStPos = Position(1, 3);
    switch (stage) {
    case 1:
        return new Majayong(OpponentStPos);
    case 2:
        return new Ttodogas(OpponentStPos);
    default:
        return nullptr;
    }
}

void GameManager::main()
{
    GameManager gameManager;

    cout << "����Ϸ��� �ƹ� Ű�� ��������...";
    (void)_getch();

    while (true) {
        gameManager.update();
    }
}

void GameManager::exitGame()
{
    exit(0);
}