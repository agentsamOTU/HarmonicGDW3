#pragma once
#include"ECS.h"
class HealthArmour
{
public:
	HealthArmour();
	void TakeDamage(int dam);
	void AddHealth(int hea);
	void AddArmour(int arm);
	bool GetDamaged();
	void SetDamaged(bool dam);
	int GetArmour() const;
	int GetHealth() const;
	void SetArmour(int arm);
	void SetHealth(int hea);
private:
	int m_armour=0;
	int m_health;
	bool inDamage=false;
};
inline void from_json(const nlohmann::json& j, HealthArmour& health)
{
	health.SetArmour(j["armour"]);
	health.SetHealth(j["health"]);
}
inline void to_json(nlohmann::json& j, const HealthArmour health)
{
	j["armour"] = health.GetHealth();
	j["health"] = health.GetArmour();
}