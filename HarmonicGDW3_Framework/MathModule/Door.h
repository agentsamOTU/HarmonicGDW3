#pragma once
#include "PhysicsBody.h"
#include "AnimationController.h"
#include "ECS.h"
class Door {
public:
	Door();
	void DoorToggle(PhysicsBody* phys, AnimationController* anim);
	void DoorLock(bool red, bool blue, bool green, bool yellow);
	bool LockCheck();
private:
	bool doorOpen = false;
	bool reqRed = false;
	bool reqBlue = false;
	bool reqYell = false;
	bool reqGree = false;
};