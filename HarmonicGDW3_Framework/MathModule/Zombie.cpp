#include "Zombie.h"

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
