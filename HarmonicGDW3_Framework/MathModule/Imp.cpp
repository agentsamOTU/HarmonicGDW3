#include "Imp.h"
#include "ECS.h"

Imp::Imp()
{
}

bool Imp::GetActive()
{
	return active;
}

void Imp::SetActive(bool act)
{
	active = act;
}

bool Imp::GetShoot()
{
	return inShoot;
}

void Imp::SetShoot(bool shot)
{
	inShoot = shot;
	shotDone = !shot;
}

void Imp::AddTime(float delta)
{
	shootTime += delta;
}

float Imp::GetTime()
{
	return shootTime;
}

void Imp::ResetShoot()
{
	shootTime = 0.f;
	inShoot = false;
}

vec2 Imp::GetDirection()
{
	return shotDir;
}

void Imp::SetDirection(float x, float y)
{
	shotDir.x = x;
	shotDir.y = y;
}

void Imp::Shoot(Transform* trans)
{
	auto entity = ECS::CreateEntity();
	ECS::AttachComponent<Sprite>(entity);
	ECS::AttachComponent<Transform>(entity);
	ECS::AttachComponent<PhysicsBody>(entity);
	ECS::AttachComponent<AnimationController>(entity);

	//Sets up components
	std::string FireBall = "FireBall.png";
	auto& animController = ECS::GetComponent<AnimationController>(entity);
	animController.InitUVs(FireBall);
	//Adds first animation
	animController.AddAnimation(Animation());
	//Sets active animation
	animController.SetActiveAnim(0);

	//gets first animation
	auto& anim = animController.GetAnimation(0);
	anim.AddFrame(vec2(140.f, 199.f), vec2(211.f, 70.f));
	anim.AddFrame(vec2(480.f, 199.f), vec2(549.f, 70.f));
	anim.AddFrame(vec2(819.f, 199.f), vec2(889.f, 70.f));

	//Makes it repeat
	anim.SetRepeating(true);
	//Sets the time between frames
	anim.SetSecPerFrame(0.1667f);

	ECS::GetComponent<Sprite>(entity).LoadSprite(FireBall, 10, 15, true, &animController);
	ECS::GetComponent<Transform>(entity).SetPosition(trans->GetPosition());
	ECS::GetComponent<Transform>(entity).SetRotationAngleZ(trans->GetRotationAngleZ());
	auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);
	auto& tempSpr = ECS::GetComponent<Sprite>(entity);
	tempPhsBody = PhysicsBody(float(tempSpr.GetWidth()), float(tempSpr.GetHeight()),
		vec2(0.f, 0.f),
		CollisionIDs::Bullet(), (CollisionIDs::Environment() | CollisionIDs::Player()), true);
	Degrees angle = trans->GetRotationAngleZ();
	vec2 tempVec = shotDir.Normalize();
	tempPhsBody.SetVelocity(vec3(tempVec.x * 100.f, tempVec.y * 100.f, 0.f));
	tempPhsBody.SetFriction(0.f);
	unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::PhysicsBit();
	ECS::SetUpIdentifier(entity, bitHolder, "fireball");
	shotDone = true;
}

bool Imp::GetShotDone()
{
	return shotDone;
}
