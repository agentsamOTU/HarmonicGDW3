#include "PlayerWeapons.h"

PlayerWeapons::PlayerWeapons()
{
}

void PlayerWeapons::Shoot(Transform* trans)
{
	if (curWeap == 0)//pistol
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
			CollisionIDs::Bullet(), (CollisionIDs::Environment() | CollisionIDs::Enemy()), true);
		Degrees angle = trans->GetRotationAngleZ();
		float x = sin(angle);
		float y = -cos(angle);
		tempPhsBody.SetVelocity(vec3(100*x,100*y,0.f));
		tempPhsBody.SetFriction(0.f);
		unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::PhysicsBit();
		ECS::SetUpIdentifier(entity, bitHolder, "bullet");
		ammPist -= 1;
	}
	else if (curWeap == 1)//shotgun
	{

	}

}

void PlayerWeapons::AddAmmo(int type, int quantity)
{
}

void PlayerWeapons::ChangeWeapon(int weap)
{
}

int PlayerWeapons::GetAmmo()
{
	if (curWeap == 0)
	{
		return ammPist;
	}
	else if (curWeap == 1)
	{
		return ammShot;
	}
}

void PlayerWeapons::SetAmmo(int pist, int shot)
{
	ammPist=pist;
	ammShot = shot;
}

int PlayerWeapons::GetPistol() const
{
	return ammPist;
}

int PlayerWeapons::GetShot() const
{
	return ammShot;
}

bool PlayerWeapons::GetHasShotgun() const
{
	return hasShot;
}

void PlayerWeapons::SetHasShotgun(bool has)
{
	hasShot = has;
}

void PlayerWeapons::AddPistol(int amm)
{
	ammPist += amm;
}

void PlayerWeapons::AddShotgun(int amm)
{
	ammShot += amm;
}
