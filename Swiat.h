#pragma once
#include <iostream>
#include "Organizm.h"
using namespace std;
class Swiat
{
private:
	Organizm plansza[20][20];
private:
	Swiat();
	void WykonajTure();
	void DodajOrganizm(int x, int y, Organizm New);
	void RysujSwiat();
	~Swiat();
public:
	void Start();
};

