#include "HealthArmour.h"

HealthArmour::HealthArmour(int health, int armour)
{
	m_health = health;
	m_armour = armour;
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
