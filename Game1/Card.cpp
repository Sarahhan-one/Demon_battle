#include "Card.h"
#include "Tools.h"
#include "Pokemon.h"

void Card::executeCard(vector<vector<Pokemon*>>& map)
{
	cout << "ī�� " << name_ << "��� !" << '\n';
	(executeFunc_)(map);
}
