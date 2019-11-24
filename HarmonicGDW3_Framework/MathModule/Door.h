#pragma once
#include "PhysicsBody.h"
#include "AnimationController.h"
class Door {
public:
	Door();
	void DoorToggle(PhysicsBody* phys, AnimationController* anim);
private:
	bool doorOpen = false;
};