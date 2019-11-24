#include "HealthArmour.h"

HealthArmour::HealthArmour()
{

}

void HealthArmour::TakeDamage(int dam)
{
	int armTook=0;
	if (m_armour > 0)
	{
		m_armour -= dam / 3;
		armTook = dam / 3;
	}
	if (m_armour < 0)
	{
		armTook = dam / 3 + m_armour;
		m_armour = 0;
	}
	m_health -= dam + armTook;
}

void HealthArmour::AddHealth(int hea)
{
	m_health += hea;
}

void HealthArmour::AddArmour(int arm)
{
	m_armour += arm;
}

bool HealthArmour::GetDamaged()
{
	return inDamage;
}

void HealthArmour::SetDamaged(bool dam)
{
	inDamage = dam;
}

int HealthArmour::GetArmour() const
{
	return m_armour;
}

int HealthArmour::GetHealth() const
{
	return m_health;
}

void HealthArmour::SetArmour(int arm)
{
	m_armour = arm;
}

void HealthArmour::SetHealth(int hea)
{
	m_health = hea;
}
