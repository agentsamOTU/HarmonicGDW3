#include "PlayerWeapons.h"

PlayerWeapons::PlayerWeapons()
{
}

void PlayerWeapons::Shoot(Transform* trans)
{
	if (curWeap == 0)//pistol
	{
		if (GetGunTime() > 0.5f)
		{
			auto entity = ECS::CreateEntity();
			ECS::AttachComponent<Sprite>(entity);
			ECS::AttachComponent<Transform>(entity);
			ECS::AttachComponent<PhysicsBody>(entity);
			ECS::AttachComponent<AnimationController>(entity);
			std::string Potion = "bulletanim.png";
			auto& animController = ECS::GetComponent<AnimationController>(entity);
			animController.InitUVs(Potion);
			//Adds first animation
			animController.AddAnimation(Animation());
			//Sets active animation
			animController.SetActiveAnim(0);

			//gets first animation
			auto& anim = animController.GetAnimation(0);
			anim.AddFrame(vec2(149.f, 199.f), vec2(179.f, 120.f));
			anim.AddFrame(vec2(490.f, 199.f), vec2(520.f, 120.f));
			ECS::GetComponent<Sprite>(entity).LoadSprite(Potion, 3, 6, true, &animController);
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
			tempPhsBody.SetVelocity(vec3(100 * x, 100 * y, 0.f));
			tempPhsBody.SetFriction(0.f);
			unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::PhysicsBit();
			ECS::SetUpIdentifier(entity, bitHolder, "bullet");
			ammPist -= 1;
			ResetGunTime();
		}
	}
	else if (curWeap == 1)//shotgun
	{
		if (GetGunTime() > 1.f)
		{
			auto entity = ECS::CreateEntity();
			ECS::AttachComponent<Sprite>(entity);
			ECS::AttachComponent<Transform>(entity);
			ECS::AttachComponent<PhysicsBody>(entity);
			ECS::AttachComponent<AnimationController>(entity);
			std::string Potion = "bulletanim.png";
			auto& animController = ECS::GetComponent<AnimationController>(entity);
			animController.InitUVs(Potion);
			//Adds first animation
			animController.AddAnimation(Animation());
			//Sets active animation
			animController.SetActiveAnim(0);

			//gets first animation
			auto& anim = animController.GetAnimation(0);
			anim.AddFrame(vec2(149.f, 199.f), vec2(179.f, 120.f));
			anim.AddFrame(vec2(490.f, 199.f), vec2(520.f, 120.f));
			ECS::GetComponent<Sprite>(entity).LoadSprite(Potion, 3, 6, true, &animController);
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
			tempPhsBody.SetVelocity(vec3(100 * x, 100 * y, 0.f));
			tempPhsBody.SetFriction(0.f);
			unsigned int bitHolder = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::PhysicsBit();
			ECS::SetUpIdentifier(entity, bitHolder, "bullet");
			ammShot -= 1;
			auto entity2 = ECS::CreateEntity();
			ECS::AttachComponent<Sprite>(entity2);
			ECS::AttachComponent<Transform>(entity2);
			ECS::AttachComponent<PhysicsBody>(entity2);
			ECS::AttachComponent<AnimationController>(entity2);
			auto& animController2 = ECS::GetComponent<AnimationController>(entity2);
			animController2.InitUVs(Potion);
			//Adds first animation
			animController2.AddAnimation(Animation());
			//Sets active animation
			animController2.SetActiveAnim(0);

			//gets first animation
			auto& anim2 = animController2.GetAnimation(0);
			anim2.AddFrame(vec2(149.f, 199.f), vec2(179.f, 120.f));
			anim2.AddFrame(vec2(490.f, 199.f), vec2(520.f, 120.f));
			ECS::GetComponent<Sprite>(entity2).LoadSprite(Potion, 3, 6, true, &animController2);
			ECS::GetComponent<Transform>(entity2).SetPosition(trans->GetPosition());
			ECS::GetComponent<Transform>(entity2).SetRotationAngleZ(trans->GetRotationAngleZ() + 0.26f);
			auto& tempPhsBody2 = ECS::GetComponent<PhysicsBody>(entity2);
			auto& tempSpr2 = ECS::GetComponent<Sprite>(entity2);
			tempPhsBody2 = PhysicsBody(float(tempSpr2.GetWidth()), float(tempSpr2.GetHeight()),
				vec2(0.f, 0.f),
				CollisionIDs::Bullet(), (CollisionIDs::Environment() | CollisionIDs::Enemy()), true);
			Degrees angle2 = trans->GetRotationAngleZ();
			float x2 = sin(angle2 + 0.26f);
			float y2 = -cos(angle2 + 0.26f);
			tempPhsBody2.SetVelocity(vec3(100 * x2, 100 * y2, 0.f));
			tempPhsBody2.SetFriction(0.f);
			unsigned int bitHolder2 = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::PhysicsBit();
			ECS::SetUpIdentifier(entity2, bitHolder2, "bullet");
			ammShot -= 1;
			auto entity3 = ECS::CreateEntity();
			ECS::AttachComponent<Sprite>(entity3);
			ECS::AttachComponent<Transform>(entity3);
			ECS::AttachComponent<PhysicsBody>(entity3);
			ECS::AttachComponent<AnimationController>(entity3);
			auto& animController3 = ECS::GetComponent<AnimationController>(entity3);
			animController3.InitUVs(Potion);
			//Adds first animation
			animController3.AddAnimation(Animation());
			//Sets active animation
			animController3.SetActiveAnim(0);

			//gets first animation
			auto& anim3 = animController3.GetAnimation(0);
			anim3.AddFrame(vec2(149.f, 199.f), vec2(179.f, 120.f));
			anim3.AddFrame(vec2(490.f, 199.f), vec2(520.f, 120.f));
			ECS::GetComponent<Sprite>(entity3).LoadSprite(Potion, 3, 6, true, &animController3);
			ECS::GetComponent<Transform>(entity3).SetPosition(trans->GetPosition());
			ECS::GetComponent<Transform>(entity3).SetRotationAngleZ(trans->GetRotationAngleZ() - 0.26f);
			auto& tempPhsBody3 = ECS::GetComponent<PhysicsBody>(entity3);
			auto& tempSpr3 = ECS::GetComponent<Sprite>(entity3);
			tempPhsBody3 = PhysicsBody(float(tempSpr3.GetWidth()), float(tempSpr3.GetHeight()),
				vec2(0.f, 0.f),
				CollisionIDs::Bullet(), (CollisionIDs::Environment() | CollisionIDs::Enemy()), true);
			Degrees angle3 = trans->GetRotationAngleZ();
			float x3 = sin(angle3 - 0.26f);
			float y3 = -cos(angle3 - 0.26f);
			tempPhsBody3.SetVelocity(vec3(100 * x3, 100 * y3, 0.f));
			tempPhsBody3.SetFriction(0.f);
			unsigned int bitHolder3 = EntityIdentifier::SpriteBit() | EntityIdentifier::TransformBit() | EntityIdentifier::PhysicsBit();
			ECS::SetUpIdentifier(entity3, bitHolder3, "bullet");
			ammShot -= 1;
			ResetGunTime();
		}
	}

}

void PlayerWeapons::AddAmmo(int type, int quantity)
{
}

void PlayerWeapons::ChangeWeapon()
{
	if (curWeap == 0)
	{
		if (hasShot == true)
		{
			printf("curWeap is 1 shotgun");
			curWeap = 1;
		}
	}
	else if (curWeap == 1)
	{
		curWeap = 0;
	}
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

float PlayerWeapons::GetAcid()
{
	return acidTime;
}

float PlayerWeapons::GetGunTime()
{
	if (curWeap == 1)
	{
		return shotTime;
	}
	else if (curWeap == 0)
	{
		return pistTime;
	}
}

void PlayerWeapons::AddGunTime(float time)
{
	pistTime += time;
	shotTime += time;
}

void PlayerWeapons::ResetGunTime()
{
	if (curWeap == 1)
	{
		shotTime = 0.f;
	}
	else if (curWeap == 0)
	{
		pistTime = 0.f;
	}
}

void PlayerWeapons::AddAcidTime(float f)
{
	acidTime += f;
}

void PlayerWeapons::ResetAcid()
{
	acidTime = 0.f;
}

bool PlayerWeapons::GetBlue()
{
	return hasBlue;
}

bool PlayerWeapons::GetRed()
{
	return hasRed;
}

bool PlayerWeapons::GetGreen()
{
	return hasGreen;
}

bool PlayerWeapons::GetYellow()
{
	return hasYellow;
}

void PlayerWeapons::SetBlue()
{
	hasBlue = true;
}

void PlayerWeapons::SetRed()
{
	hasRed = true;
}

void PlayerWeapons::SetGreen()
{
	hasGreen = true;
}

void PlayerWeapons::SetYellow()
{
	hasYellow = true;
}
