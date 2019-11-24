#include "Zombie.h"
#include "ECS.h"

Zombie::Zombie()
{
}

bool Zombie::GetActive()
{
	return active;
}

void Zombie::SetActive(bool act)
{
	active = act;
}

bool Zombie::GetShoot()
{
	return inShoot;
}

void Zombie::SetShoot(bool shot)
{
	inShoot = shot;
	shotDone = !shot;
}

void Zombie::AddTime(float delta)
{
	shootTime += delta;
}

float Zombie::GetTime()
{
	return shootTime;
}

void Zombie::ResetShoot()
{
	shootTime = 0.f;
	inShoot = false;
}

vec2 Zombie::GetDirection()
{
	return shotDir;
}

void Zombie::SetDirection(float x, float y)
{
	shotDir.x = x;
	shotDir.y = y;
}

void Zombie::Shoot(Transform* trans)
{
	auto entity = ECS::CreateEntity();
	ECS::AttachComponent<Sprite>(entity);
	ECS::AttachComponent<Transform>(entity);
	ECS::AttachComponent<PhysicsBody>(entity);
	std::string fileName = "DoomGuy_Walk.png";
	ECS::GetComponent<Sprite>(entity).LoadSprite(fileName, 1, 5, true);
	ECS::GetComponent<Transform>(entity).SetPosition(trans->GetPosition());
	ECS::GetComponent<Transform>(entity).SetRotationAngleZ(trans->GetRotationAngleZ());
	auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
	auto& tempSpr = ECS::GetComponent<Sprite>(entity);
	tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
		vec2(0.f, 0.f),
		CollisionIDs::Bullet(), (CollisionIDs::Environment() | CollisionIDs::Player()), true);
	Degrees angle = trans->GetRotationAngleZ();
	vec2 tempVec = shotDir.Normalize();
	tempPhsBody.SetVelocity(vec3(tempVec.x *100.f, tempVec.y*100.f, 0.f));
	tempPhsBody.SetFriction(0.f);
	unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::PhysicsBit();
	ECS::SetUpIdentifier(entity, bitHolder, "bullet");
	shotDone = true;
}

bool Zombie::GetShotDone()
{
	return shotDone;
}
