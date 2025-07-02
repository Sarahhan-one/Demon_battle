#pragma once
#include "Tools.h"
#include <functional>

// buff: ���� ��ȭ
// debuff: ��� ��ȭ
// ultimate: �ñر�
// �� �ʿ��Ͻø� �߰� ���ּ���
enum class CardType {
	MOVE, ATTACK, HEAL, SHIELD, BUFF, DEBUFF, ULTIMATE
};

class Pokemon;

class Card
{
private:
	string name_;
	CardType type_;
	function<vector<Position> (vector<vector<Pokemon*>>&)> executeFunc_;

public:
	Card(string name, CardType type, function<vector<Position> (vector<vector<Pokemon*>>& map)> executeFunc)
		: name_(name), type_(type), executeFunc_(executeFunc) {
	}

	string getName() const { return name_; }
	CardType getType() const { return type_; }
	vector<Position> executeCard(vector<vector<Pokemon*>>& map) const;
};

