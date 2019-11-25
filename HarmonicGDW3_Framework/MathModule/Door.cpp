#pragma once
#include "Door.h"

Door::Door()
{
}

void Door::DoorToggle(PhysicsBody* phys, AnimationController* anim)
{
	if (doorOpen)
	{
		doorOpen = false;
		anim->GetAnimation(1).Reset();
		anim->SetActiveAnim(1);
		phys->SetBodyID(CollisionIDs::Environment());
		
	}
	else
	{
		doorOpen = true;
		anim->GetAnimation(0).Reset();
		anim->SetActiveAnim(0);
		phys->SetBodyID(0x0);
	}
}

void Door::DoorLock(bool red, bool blue, bool green, bool yellow)
{
	reqRed = red;
	reqBlue = blue;
	reqYell = yellow;
	reqGree = green;
}

bool Door::LockCheck()
{
	auto& playKeys = ECS::GetComponent<PlayerWeapons>(EntityIdentifier::MainPlayer());
	if (reqRed)
	{
		return playKeys.GetRed();
	}
	else if (reqBlue)
	{
		return playKeys.GetBlue();
	}
	else if (reqGree)
	{
		return playKeys.GetGreen();
	}
	else if (reqYell)
	{
		return playKeys.GetYellow();
	}
	else
	{
		return true;
	}
}

