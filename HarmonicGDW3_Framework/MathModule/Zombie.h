#pragma once
#include "Vector.h"
#include "Transform.h"
class Zombie {
public:
	Zombie();
	bool GetActive();
	void SetActive(bool act);
	bool GetShoot();
	void SetShoot(bool shot);
	void AddTime(float delta);
	float GetTime();
	void ResetShoot();
	vec2 GetDirection();
	void SetDirection(float x, float y);
	void Shoot(Transform* trans);
	bool GetShotDone();
private:
	bool active=true;
	bool inShoot = false;
	float shootTime = 0.f;
	vec2 shotDir;
	bool shotDone;
};