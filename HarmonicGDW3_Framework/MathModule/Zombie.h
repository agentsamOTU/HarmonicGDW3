#pragma once
class Zombie {
public:
	Zombie();
	bool GetActive();
	void SetActive(bool act);
private:
	bool active=true;
};