#pragma once
#include "Transform.h"
#include "ECS.h"
class PlayerWeapons
{
public:
	PlayerWeapons();
	void Shoot(Transform* trans);
	void AddAmmo(int type, int quantity);
	void ChangeWeapon(int weap);
private:
	int curWeap = 0;
	int ammPist=50;
	int ammShot=0;
	bool hasShot = false;

};