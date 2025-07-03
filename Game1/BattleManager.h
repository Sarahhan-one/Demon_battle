#pragma once
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

enum class BattleResult { NONE, PLAYER_WIN, COMPUTER_WIN };

class BattleManager
{
private:
	// ~_ ������ google, tensorflow ���� modern c++ style �̶�� �ؼ� ����غý��ϴ�.
	Player* humanPlayer_;
	Player* computerPlayer_;
	vector<vector<Pokemon*>> map_;
	vector<int> humanCardList_;
	vector<int> computerCardList;
	int currentTurn_;
	bool isBattleEnd_;
	BattleResult lastResult_ = BattleResult::NONE;

public:
	BattleManager() : currentTurn_(0), isBattleEnd_(false),
		humanPlayer_(new HumanPlayer()), computerPlayer_(new ComputerPlayer()),
		map_(vector<vector<Pokemon*>>(MAX_Y, vector<Pokemon*>(MAX_X))) {
	};
	~BattleManager() { delete humanPlayer_;  delete computerPlayer_; }

	void init();
	void executeBattle();
	void selectCardsForStage();
	bool getIsBattleEnd();
	void setIsBattleEnd(bool isBattleEnd);

	// move, attack ���� effect �� print
	void showEffect(vector<Position> poss, CardType cardType, string effectName, string userName);

	void printMap();
	void printMap(vector<vector<char>> effectMap);

	void setHumanPokemon(Pokemon* const pokemon) { humanPlayer_->selectPokemon(pokemon); }
	void setComputerPokemon(Pokemon* const pokemon) { computerPlayer_->selectPokemon(pokemon); }
	BattleResult getLastResult() const { return lastResult_; }
};

