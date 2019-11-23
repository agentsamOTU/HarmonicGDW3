#pragma once
class HealthArmour
{
public:
	HealthArmour(int health, int armour=0);
	void TakeDamage(int dam);
	void AddHealth(int hea);
	void AddArmour(int arm);
private:
	int m_armour;
	int m_health;
};