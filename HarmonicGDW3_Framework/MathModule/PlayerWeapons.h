#pragma once
#include "Transform.h"
#include "ECS.h"
class PlayerWeapons
{
public:
	PlayerWeapons();
	void Shoot(Transform* trans);
	void AddAmmo(int type, int quantity);
	void ChangeWeapon(int weap);
	int GetAmmo();
	void SetAmmo(int pist,int shot);
	int GetPistol() const;
	int GetShot() const;
	bool GetHasShotgun() const;
	void SetHasShotgun(bool has);
	void AddPistol(int amm);
	void AddShotgun(int amm);
	float GetAcid();
	float GetShotTime();
	void AddAcidTime(float f);
	void ResetAcid();
private:
	int curWeap = 0;
	int ammPist=50;
	int ammShot=0;
	bool hasShot = false;
	float acidTime = 0.f;
	float shotTime = 0.f;

};
inline void from_json(const nlohmann::json& j, PlayerWeapons& playWeap)
{
	playWeap.SetAmmo(j["Pistol"],j["Shotgun"]);
	playWeap.SetHasShotgun(j["HasShot"]);
}
inline void to_json(nlohmann::json& j, const PlayerWeapons playWeap)
{
	j["Pistol"] = playWeap.GetPistol();
	j["Shotgun"] = playWeap.GetShot();
	j["HasShot"] = playWeap.GetHasShotgun();
}