#include "Card.h"
#include "Tools.h"
#include "Pokemon.h"

vector<Position>& Card::executeCard(vector<vector<Pokemon*>>& map)
{
	cout << "ī�� " << name_ << "��� !" << '\n';
	return (executeFunc_)(map);
}
