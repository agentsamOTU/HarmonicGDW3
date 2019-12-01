#pragma once
#include "Transform.h"
#include "ECS.h"
class PlayerWeapons
{
public:
	PlayerWeapons();
	void Shoot(Transform* trans);
	void AddAmmo(int type, int quantity);
	void ChangeWeapon();
	int GetAmmo();
	void SetAmmo(int pist,int shot);
	int GetPistol() const;
	int GetShot() const;
	bool GetHasShotgun() const;
	void SetHasShotgun(bool has);
	void AddPistol(int amm);
	void AddShotgun(int amm);
	float GetAcid();
	float GetGunTime();
	void AddGunTime(float time);
	void ResetGunTime();
	void AddAcidTime(float f);
	void ResetAcid();
	bool GetBlue();
	bool GetRed();
	bool GetGreen();
	bool GetYellow();
	void SetBlue();
	void SetRed();
	void SetGreen();
	void SetYellow();
	int GetWeapon();
	bool GetActive();
	void EndGame();
private:
	bool active = true;
	int curWeap = 0;
	int ammPist=50;
	int ammShot=0;
	bool hasShot = false;
	float acidTime = 0.f;
	float shotTime = 0.f;
	float pistTime = 0.f;
	bool hasRed = false;
	bool hasGreen = false;
	bool hasYellow = false;
	bool hasBlue = false;

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