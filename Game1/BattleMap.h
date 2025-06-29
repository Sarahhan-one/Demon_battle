#pragma once
#include "Tools.h"

class BattleMap
{
private:
	Position pos_;
	// ���׿��� ����ϴ� vector �� ����߽��ϴ�. ���߿� enum ���� �ٲ㵵 ���� �� �մϴ�.
	vector<vector<int>> grid_;

public:
	BattleMap(): pos_(Position(5,5)), grid_() {}
	BattleMap(Position pos);

	void setTile(Position pos, int value) { grid_[pos.y][pos.x] = value; }
	int getTile(Position pos) { return grid_[pos.y][pos.x]; }
	bool isWalkable(Position pos);
	void printMap();
};

