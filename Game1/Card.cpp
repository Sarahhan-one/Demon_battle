#include "Card.h"
#include "Tools.h"

void Card::executeCard()
{
	cout << "ī�� " << name_ << "��� !" << '\n';
	(*executeFunc_)();
}
