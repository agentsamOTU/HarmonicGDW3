#pragma once
#include "EntityIdentifier.h"
#include "HealthArmour.h"
#include "PlayerWeapons.h"
#include "ECS.h"
class Pickup {
public:
	Pickup();
	void Collect();
	void SetAmmo(int pist, int shot, int giveShot);
	void SetHealth(int hea, int arm);
private:
	int ammPist=0;
	int ammShot=0;
	int armUp=0;
	int healthUp=0;
	int giveShot=0;
};