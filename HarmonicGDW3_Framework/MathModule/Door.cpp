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

