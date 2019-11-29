#include "Pickup.h"

Pickup::Pickup()
{
}

void Pickup::Collect()
{
	auto& health = ECS::GetComponent<HealthArmour>(EntityIdentifier::MainPlayer());
	auto& weap = ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer());
	health.AddHealth(healthUp);
	health.AddArmour(armUp);
	weap.AddPistol(ammPist);
	weap.AddShotgun(ammShot);
	if (giveShot == 1)
	{
		weap.SetHasShotgun(true);
	}
	if (giveRed == 1)
	{
		weap.SetRed();
	}
	if (giveBlue==1)
	{
		weap.SetBlue();
	}
	if (giveGree == 1)
	{
		weap.SetGreen();
	}
	if (giveYell == 1)
	{
		weap.SetYellow();
	}
}

void Pickup::SetAmmo(int pist, int shot, int giveShotgun)
{
	ammPist = pist;
	ammShot = shot;
	giveShot = giveShotgun;
}

void Pickup::SetHealth(int hea, int arm)
{
	healthUp = hea;
	armUp = arm;
}

void Pickup::SetLocks(int red, int blue, int green, int yellow)
{
	giveRed = red;
	giveBlue = blue;
	giveGree = green;
	giveYell = yellow;
}
