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
	void SetLocks(int red, int blue, int green, int yellow);
private:
	int ammPist=0;
	int ammShot=0;
	int armUp=0;
	int healthUp=0;
	int giveShot=0;
	int giveRed = 0;
	int giveBlue = 0;
	int giveGree = 0;
	int giveYell = 0;
};