#include "Klasy.h"
WilczeJagody::WilczeJagody()
{
	SetSila(99);
	SetInicjatywa(0);
	SetID('J');
	SetWiek(0);
	SetImie("Wilcze Jagody");
}
void WilczeJagody::SetX(int x)
{
	this->x = x;
}
void WilczeJagody::SetY(int y)
{
	this->y = y;
}
int WilczeJagody::GetX()
{
	return x;
}
int WilczeJagody::GetY()
{
	return y;
}
string WilczeJagody::GetImie()
{
	return imie;
}
int WilczeJagody::GetSila()
{
	return sila;
}
char WilczeJagody::GetID()
{
	return id;
}
void  WilczeJagody::SetImie(string imie)
{
	this->imie = imie;
}
void  WilczeJagody::SetSila(int sila)
{
	this->sila = sila;
}
int  WilczeJagody::GetInicjatywa()
{
	return inicjatywa;
}
void  WilczeJagody::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int  WilczeJagody::GetWiek()
{
	return wiek;
}
void  WilczeJagody::SetID(char id)
{
	this->id = id;
}
void  WilczeJagody::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void WilczeJagody::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
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
						Organizm* New = new WilczeJagody;
						New->SetX(x);
						New->SetY(y - 1);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsialy sie na pole " << New->GetX() << " " << New->GetY() << endl;
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
						Organizm* New = new WilczeJagody;
						New->SetX(x);
						New->SetY(y + 1);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsialy sie na pole " << New->GetX() << " " << New->GetY() << endl;
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
						Organizm* New = new WilczeJagody;
						New->SetX(x + 1);
						New->SetY(y);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsialy sie na pole " << New->GetX() << " " << New->GetY() << endl;
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
						Organizm* New = new WilczeJagody;
						New->SetX(x - 1);
						New->SetY(y);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsialy sie na pole " << New->GetX() << " " << New->GetY() << endl;
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
Organizm* WilczeJagody::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	cout << off->GetImie() << "wchodzi na " << def->GetImie() << " i umiera :< " << endl;
	return def;
}
void WilczeJagody::rysowanie()
{
	cout << " " << GetID();
}
WilczeJagody::~WilczeJagody() {

}