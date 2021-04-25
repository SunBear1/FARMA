#include "Klasy.h"
Barszcz::Barszcz()
{
	SetSila(10);
	SetInicjatywa(0);
	SetID('B');
	SetWiek(0);
	SetImie("Barszcz Sosnowskiego");
}
void Barszcz::SetX(int x)
{
	this->x = x;
}
void Barszcz::SetY(int y)
{
	this->y = y;
}
int Barszcz::GetX()
{
	return x;
}
int Barszcz::GetY()
{
	return y;
}
string Barszcz::GetImie()
{
	return imie;
}
int Barszcz::GetSila()
{
	return sila;
}
char Barszcz::GetID()
{
	return id;
}
void Barszcz::SetImie(string imie)
{
	this->imie = imie;
}
void Barszcz::SetSila(int sila)
{
	this->sila = sila;
}
int Barszcz::GetInicjatywa()
{
	return inicjatywa;
}
void Barszcz::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Barszcz::GetWiek()
{
	return wiek;
}
void Barszcz::SetID(char id)
{
	this->id = id;
}
void Barszcz::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Barszcz::Eksterminacja(Organizm*** plansza, int szerokosc, int wysokosc)
{
	cout << "Barszcz przeprowadza eksterminacje sasiednich pol... " << endl;
	if (GetX() > 0 && dynamic_cast<Zwierze*>(plansza[GetX() - 1][GetY()]) != nullptr && plansza[GetX() - 1][GetY()]->GetID() != 'B')
	{
		cout << plansza[GetX() - 1][GetY()]->GetImie() << " umiera w meczarniach przez Barszcz Sosnowskiego" << endl;
		plansza[GetX() - 1][GetY()] = NULL;
	}

	if (GetX() < wysokosc - 1 && dynamic_cast<Zwierze*>(plansza[GetX() + 1][GetY()]) != nullptr && plansza[GetX() + 1][GetY()]->GetID() != 'B')
	{
		cout << plansza[GetX() + 1][GetY()]->GetImie() << " umiera w meczarniach przez Barszcz Sosnowskiego" << endl;
		plansza[GetX() + 1][GetY()] = NULL;
	}

	if (GetY() > 0 && dynamic_cast<Zwierze*>(plansza[GetX()][GetY() - 1]) != nullptr && plansza[GetX()][GetY() - 1]->GetID() != 'B')
	{
		cout << plansza[GetX()][GetY() - 1]->GetImie() << " umiera w meczarniach przez Barszcz Sosnowskiego" << endl;
		plansza[GetX()][GetY() - 1] = NULL;
	}

	if (GetY() < szerokosc - 1 && dynamic_cast<Zwierze*>(plansza[GetX()][GetY() + 1]) != nullptr && plansza[GetX()][GetY() + 1]->GetID() != 'B')
	{
		cout << plansza[GetX()][GetY() + 1]->GetImie() << " umiera w meczarniach przez Barszcz Sosnowskiego" << endl;
		plansza[GetX()][GetY() + 1] = NULL;
	}
}
void Barszcz::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	Eksterminacja(plansza,szerokosc,wysokosc);
	bool brakruchu[4] = {};
	int rozsiew = rand() % 100;
	if (rozsiew == 0)
	{
		while (1)
		{
			if (brakruchu[0] && brakruchu[1] && brakruchu[2] && brakruchu[3])
				break;
			int kierunek = rand() % 4;
			if (kierunek == 0)
			{
				if (y > 0)
				{
					if (dynamic_cast<Organizm*>(plansza[x][y - 1]) == nullptr)
					{
						Organizm* New = new Barszcz;
						New->SetX(x);
						New->SetY(y - 1);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsial sie na pole " << New->GetX() << " " << New->GetY() << endl;
						break;
					}
					else
						brakruchu[kierunek] = 1;
				}
				else
				{
					brakruchu[kierunek] = 1;
					kierunek = rand() % 4;
				}
			}
			else if (kierunek == 1)
			{
				if (y < szerokosc - 1)
				{
					if (dynamic_cast<Organizm*>(plansza[x][y + 1]) == nullptr)
					{
						Organizm* New = new Barszcz;
						New->SetX(x);
						New->SetY(y + 1);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsial sie na pole " << New->GetX() << " " << New->GetY() << endl;
						break;
					}
					else
						brakruchu[kierunek] = 1;
				}
				else
				{
					brakruchu[kierunek] = 1;
					kierunek = rand() % 4;
				}

			}
			else if (kierunek == 2)
			{
				if (x < wysokosc - 1)
				{
					if (dynamic_cast<Organizm*>(plansza[x + 1][y]) == nullptr)
					{
						Organizm* New = new Barszcz;
						New->SetX(x + 1);
						New->SetY(y);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsial sie na pole " << New->GetX() << " " << New->GetY() << endl;
						break;
					}
					else
						brakruchu[kierunek] = 1;
				}
				else
				{
					brakruchu[kierunek] = 1;
					kierunek = rand() % 4;
				}
			}
			else
			{
				if (x > 0)
				{
					if (dynamic_cast<Organizm*>(plansza[x - 1][y]) == nullptr)
					{
						Organizm* New = new Barszcz;
						New->SetX(x - 1);
						New->SetY(y);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsial sie na pole " << New->GetX() << " " << New->GetY() << endl;
						break;
					}
					else
						brakruchu[kierunek] = 1;
				}
				else
				{
					brakruchu[kierunek] = 1;
					kierunek = rand() % 4;
				}
			}
		}
	}
}
Organizm* Barszcz::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	return def;
}
void Barszcz::rysowanie()
{
	cout << " " << GetID();
}
Barszcz::~Barszcz() {

}