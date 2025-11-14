#pragma once

#include "mystd.h"

class Warrior;

class Skill
{
public:
	virtual void execute(Warrior* w) = 0;
};

class Gun
{
public:
	virtual void shoot(Warrior* w) = 0;
};

class Warrior
{
	int hp;
	List<Skill*> skills;
	List<Gun*> guns;

public:
	Warrior(int hp, Skill* skill = nullptr, Gun* gun = nullptr) : hp(hp)
	{
		if (skill)
			skills.push_back(skill);
		if (gun)
			guns.push_back(gun);
	}

	Skill* getSkill()
	{
		if (skills.get_size() > 0)
			return skills[rand() % skills.get_size()];
		return nullptr;
	}

	Gun* getGun()
	{
		if (guns.get_size() > 0)
			return guns[rand() % guns.get_size()];
		return nullptr;
	}

	int getHP() { return hp; }
	void setHP(int hp) { this->hp = hp; }
	void changeHP(int delta) { this->hp += delta; }

	virtual void skill(Warrior* w) = 0;
	virtual void gun(Warrior* w) = 0;

	virtual ostream& print(ostream& out) const
	{
		out << "(HP: " << hp << ")";
		return out;
	}

	friend ostream& operator<<(ostream& out, const Warrior* w);
};

void imitateProcess(int s = 10) {
	for (size_t i = 0; i < s; i++)
	{
		cout << "--";
		Sleep(500);
	}
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int end = csbi.dwCursorPosition.X;
	gotoxy(0, csbi.dwCursorPosition.Y);
	for (size_t i = 0; i < end; i++) cout << " ";
	gotoxy(0, csbi.dwCursorPosition.Y);
}

class TauGauss : public Gun
{
public:
	virtual void shoot(Warrior* w) override {
		cout << "Shooting by TauGauss:" << endl;
		imitateProcess();
		cout << "Сomplete destruction! -999" << endl;
		w->changeHP(-999);
	}
};

class PulseRifleM41A : public Gun
{
public:
	virtual void shoot(Warrior* w) override {
		cout << "Shooting by PulseRifleM41A:" << endl;
		imitateProcess();
		cout << "Execution! -75" << endl;
		w->changeHP(-75);
	}
};

class AtomicBlaster : public Gun
{
public:
	virtual void shoot(Warrior* w) override {
		cout << "Shooting by AtomicBlaster:" << endl;
		imitateProcess();
		cout << "Nuclear explosion! -999" << endl;
		w->changeHP(-999);
	}
};

class Poison : public Skill
{
public:
	virtual void execute(Warrior* w) override
	{
		cout << "Using skill Poison:" << endl;
		imitateProcess();
		cout << "Poisoning target! -35" << endl;
		w->changeHP(-35);
	}
};

class Fireball : public Skill
{
public:
	virtual void execute(Warrior* w) override
	{
		cout << "Using skill Fireball:" << endl;
		imitateProcess();
		cout << "Burning target! -40" << endl;
		w->changeHP(-40);
	}
};

class IceBlast : public Skill
{
public:
	virtual void execute(Warrior* w) override
	{
		cout << "Using skill IceBlast:" << endl;
		imitateProcess();
		cout << "Target slowed! -25" << endl;
		w->changeHP(-25);
	}
};

class LightningStrike : public Skill
{
public:
	virtual void execute(Warrior* w) override
	{
		cout << "Using skill LightningStrike:" << endl;
		imitateProcess();
		cout << "Electric shock! -30" << endl;
		w->changeHP(-30);
	}
};

class AcidSpit : public Skill
{
public:
	virtual void execute(Warrior* w) override
	{
		cout << "Using skill AcidSpit:" << endl;
		imitateProcess();
		cout << "Corrosive damage! -28" << endl;
		w->changeHP(-28);
	}
};

class DarkSlash : public Skill
{
public:
	virtual void execute(Warrior* w) override
	{
		cout << "Using skill DarkSlash:" << endl;
		imitateProcess();
		cout << "Shadow attack! -45" << endl;
		w->changeHP(-45);
	}
};

ostream& operator<<(ostream& out, const Warrior* w)
{
	return w->print(out);
}

class Light : public Warrior
{
public:
	Light(int hp, Skill* skill = nullptr) : Warrior(hp, skill) {}
};

class Alien : public Warrior
{
public:
	Alien(int hp, Gun* gun = nullptr) : Warrior(hp, nullptr, gun) {}
};

class Dark : public Warrior
{
public:
	Dark(int hp, Skill* skill = nullptr) : Warrior(hp, skill) {}
};

class Martian : public Alien
{
public:
	Martian(int hp, Gun* gun = nullptr) : Alien(hp, gun) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Martian"; return Warrior::print(out); cout << endl; }
};

class Xenomorph : public Alien
{
public:
	Xenomorph(int hp, Gun* gun = nullptr) : Alien(hp, gun) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Xenomorph"; return Warrior::print(out); cout << endl; }
};

class Predator : public Alien
{
public:
	Predator(int hp, Gun* gun = nullptr) : Alien(hp, gun) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Predator"; return Warrior::print(out); cout << endl; }
};

class Swordsman : public Light
{
public:
	Swordsman(int hp, Skill* skill = nullptr) : Light(hp, skill) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Swordsman"; return Warrior::print(out); cout << endl; }
};

class Rider : public Light
{
public:
	Rider(int hp, Skill* skill = nullptr) : Light(hp, skill) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Rider"; return Warrior::print(out); cout << endl; }
};

class Archer : public Light
{
public:
	Archer(int hp, Skill* skill = nullptr) : Light(hp, skill) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Archer"; return Warrior::print(out); cout << endl; }
};

class Zombi : public Dark
{
public:
	Zombi(int hp, Skill* skill = nullptr) : Dark(hp, skill) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Zombi"; return Warrior::print(out); cout << endl; }
};

class Ork : public Dark
{
public:
	Ork(int hp, Skill* skill = nullptr) : Dark(hp, skill) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Ork"; return Warrior::print(out); cout << endl; }
};

class Skeleton : public Dark
{
public:
	Skeleton(int hp, Skill* skill = nullptr) : Dark(hp, skill) {}
	virtual void skill(Warrior* w) override {}
	virtual void gun(Warrior* w) override {}
	virtual ostream& print(ostream& out) const { cout << "Skeleton"; return Warrior::print(out); cout << endl; }
};


class WarOfWorld
{
	List<Alien*> aliens;
	List<Light*> lightes;
	List<Dark*> darkes;

public:
	WarOfWorld(int count)
	{
		for (size_t i = 0; i < count; i++)
		{
			int r = rand() % 3;
			Light* l = nullptr;
			switch (r)
			{
			case 0: l = new Swordsman(rand() % 30 + 50, new Fireball()); break;
			case 1: l = new Rider(rand() % 30 + 50, new Poison()); break;
			case 2: l = new Archer(rand() % 30 + 50, new LightningStrike()); break;
			}
			lightes.push_back(l);
		}

		for (size_t i = 0; i < count; i++)
		{
			int r = rand() % 3;
			Dark* d = nullptr;
			switch (r)
			{
			case 0: d = new Ork(rand() % 30 + 50, new IceBlast()); break;
			case 1: d = new Skeleton(rand() % 30 + 50, new AcidSpit()); break;
			case 2: d = new Zombi(rand() % 30 + 25, new DarkSlash()); break;
			}
			darkes.push_back(d);
		}

		for (size_t i = 0; i < count; i++)
		{
			int r = rand() % 3;
			Alien* a = nullptr;
			switch (r)
			{
			case 0: a = new Martian(rand() % 30, new AtomicBlaster()); break;
			case 1: a = new Xenomorph(rand() % 15 + 20, new PulseRifleM41A()); break;
			case 2: a = new Predator(rand() % 30 + 5, new TauGauss()); break;
			}
			aliens.push_back(a);
		}
	}

	void printTeams() {
		system("cls");
		cout << "------ LIGHT ------" << endl;
		lightes.print();

		gotoxy(25, 0);
		cout << "------ DARK ------" << endl;
		darkes.print(26, 1);

		gotoxy(51, 0);
		cout << "------ ALIEN ------" << endl;
		aliens.print(52, 1);
		cout << endl;
	}

	Warrior* fight(Warrior* war1, Warrior* war2)
	{
		int ms = max(lightes.get_size(), max(darkes.get_size(), aliens.get_size()));
		gotoxy(0, ms + 2);

		int r = rand() % 2;

		cout << " -------- Fight -------- " << endl;

		Warrior* attacker = (r == 0 ? war1 : war2);
		Warrior* defender = (r == 0 ? war2 : war1);

		int hp_attacker_before = attacker->getHP();
		int hp_defender_before = defender->getHP();

		cout << "Attacker -> Defender" << endl;
		cout << attacker << " -> " << defender << endl;

		Skill* s_attacker = attacker->getSkill();
		Gun* g_attacker = attacker->getGun();

		Sleep(500);

		if (s_attacker) s_attacker->execute(defender);
		if (g_attacker) g_attacker->shoot(defender);

		if (defender->getHP() <= 0) {
			cout << "Defender DIED (HP: " << hp_defender_before << " -> " << defender->getHP() << ")" << endl;
			return defender;
		}
		else {
			cout << "Defender(HP: " << hp_defender_before << " -> " << defender->getHP() << ")" << endl;
		}

		cout << endl;

		cout << "Defender -> Attacker" << endl;
		cout << defender << " -> " << attacker << endl;

		Skill* s_defender = defender->getSkill();
		Gun* g_defender = defender->getGun();

		Sleep(500);

		if (s_defender) s_defender->execute(attacker);
		if (g_defender) g_defender->shoot(attacker);

		if (attacker->getHP() <= 0) {
			cout << "Attacker DIED (HP: " << hp_attacker_before << " -> " << attacker->getHP() << ")" << endl << endl;
			return attacker;
		}
		else {
			cout << "Attacker(HP: " << hp_attacker_before << " -> " << attacker->getHP() << ")" << endl << endl;
		}

		return nullptr;
	}

	void game()
	{
		printTeams();
		system("pause");

		while (true)
		{
			printTeams();

			int szL = lightes.get_size();
			int szD = darkes.get_size();
			int szA = aliens.get_size();

			int nonEmpty = (szL > 0) + (szD > 0) + (szA > 0);
			if (nonEmpty < 2) {
				cout << "Игра окончена. Победила команда: ";
				if (szL > 0) cout << "LIGHT" << endl;
				else if (szD > 0) cout << "DARK" << endl;
				else if (szA > 0) cout << "ALIEN" << endl;
				break;
			}

			int ran;
			do {
				ran = rand() % 3;
			} while ((ran == 0 && (szL == 0 || szD == 0))
				||  ( ran == 1 && (szL == 0 || szA == 0))
				||  ( ran == 2 && (szD == 0 || szA == 0)));

			Warrior* lose;
			if (ran == 0) {
				int ind_l = rand() % szL;
				int ind_d = rand() % szD;
				lose = fight(lightes[ind_l], darkes[ind_d]);
				if (lose == lightes[ind_l]) lightes.remove(ind_l);
				else darkes.remove(ind_d);
			}
			else if (ran == 1) {
				int ind_l = rand() % szL;
				int ind_a = rand() % szA;
				lose = fight(lightes[ind_l], aliens[ind_a]);
				if (lose == lightes[ind_l]) lightes.remove(ind_l);
				else aliens.remove(ind_a);
			}
			else {
				int ind_d = rand() % szD;
				int ind_a = rand() % szA;
				lose = fight(darkes[ind_d], aliens[ind_a]);
				if (lose == darkes[ind_d]) darkes.remove(ind_d);
				else aliens.remove(ind_a);
			}

			system("pause");
		}

	}
};