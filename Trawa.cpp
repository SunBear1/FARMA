#include "Klasy.h"
Trawa::Trawa()
{
	SetSila(0);
	SetInicjatywa(0);
	SetID('T');
	SetWiek(0);
	SetImie("Trawa");
}
void Trawa::SetX(int x)
{
	this->x = x;
}
void Trawa::SetY(int y)
{
	this->y = y;
}
int Trawa::GetX()
{
	return x;
}
int Trawa::GetY()
{
	return y;
}
string Trawa::GetImie()
{
	return imie;
}
int Trawa::GetSila()
{
	return sila;
}
char Trawa::GetID()
{
	return id;
}
void  Trawa::SetImie(string imie)
{
	this->imie = imie;
}
void Trawa::SetSila(int sila)
{
	this->sila = sila;
}
int Trawa::GetInicjatywa()
{
	return inicjatywa;
}
void Trawa::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Trawa::GetWiek()
{
	return wiek;
}
void Trawa::SetID(char id)
{
	this->id = id;
}
void Trawa::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Trawa::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	bool brakruchu[4] = {};
	int rozsiew = rand() % 4;
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
						Organizm* New = new Trawa;
						New->SetX(x);
						New->SetY(y - 1);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsiala sie na pole " << New->GetX() << " " << New->GetY() << endl;
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
						Organizm* New = new Trawa;
						New->SetX(x);
						New->SetY(y + 1);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsiala sie na pole " << New->GetX() << " " << New->GetY() << endl;
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
						Organizm* New = new Trawa;
						New->SetX(x + 1);
						New->SetY(y);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsiala sie na pole " << New->GetX() << " " << New->GetY() << endl;
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
						Organizm* New = new Trawa;
						New->SetX(x - 1);
						New->SetY(y);
						plansza[New->GetX()][New->GetY()] = New;
						cout << New->GetImie() << " rozsiala sie na pole " << New->GetX() << " " << New->GetY() << endl;
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
Organizm* Trawa::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	return off;
}
void Trawa::rysowanie()
{
	cout << " " << GetID();
}
Trawa::~Trawa() {
	
}