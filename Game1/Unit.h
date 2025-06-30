#pragma once
#include "Tools.h"

enum class Race {
	NONE, PROTOSS, ZERG, TERRAN
};


class Unit
{
private:
	Race race_;
	int maxHp_;
	int hp_;
	int maxMana_;
	int mana_;
	int damage_;
	Position pos_;

	// �Լ� ������ �迭�� ������ ��? ���� �غ���. (���Ѵٸ� �׳� ����ؼ� ����)
	// �Ǵ� �������� ������ �ñ�
	void(*skillList_[4])(void);

public:
	Unit()
		: race_(Race::NONE), maxHp_(0), hp_(0), maxMana_(0), mana_(0), damage_(0), pos_(Position()), skillList_{nullptr} {
	}
	
	Unit(Race race, int maxHp, int hp, int maxMana, int mana, int damage, Position pos, void(**skillList)(void))
		: race_(race), maxHp_(maxHp), hp_(hp), maxMana_(maxMana), mana_(mana), damage_(damage), pos_(pos), 
		skillList_{ skillList[0], skillList[1], skillList[2], skillList[3] } {
	}

	Race getRace() { return race_; }
	int getHp() { return hp_; }
	void setHp(int hp) { hp_ = hp; }
	int getDamage() { return damage_; }
	void setDamage(int damage) { damage_ = damage; }
	Position getPos() { return pos_; }
	void setPos(Position pos) { pos_ = pos; }

	void move(Position pos);
	virtual void takeDamage();
	void attack();
	void heal(int amount);
	bool isAlive() const;

	// �Լ� ������ �迭, ��ȣ
	void skill(int skillNum);
};



