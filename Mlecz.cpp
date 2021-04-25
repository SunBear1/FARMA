#include "Klasy.h"
Mlecz::Mlecz()
{
	SetSila(0);
	SetInicjatywa(0);
	SetID('M');
	SetWiek(0);
	SetImie("Mlecz");
}
void Mlecz::SetX(int x)
{
	this->x = x;
}
void Mlecz::SetY(int y)
{
	this->y = y;
}
int Mlecz::GetX()
{
	return x;
}
int Mlecz::GetY()
{
	return y;
}
string Mlecz::GetImie()
{
	return imie;
}
int Mlecz::GetSila()
{
	return sila;
}
char Mlecz::GetID()
{
	return id;
}
void  Mlecz::SetImie(string imie)
{
	this->imie = imie;
}
void Mlecz::SetSila(int sila)
{
	this->sila = sila;
}
int Mlecz::GetInicjatywa()
{
	return inicjatywa;
}
void Mlecz::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Mlecz::GetWiek()
{
	return wiek;
}
void Mlecz::SetID(char id)
{
	this->id = id;
}
void Mlecz::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Mlecz::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	int proby = 0;
	bool brakruchu[4] = {};
	while (proby != 3)
	{
		int rozsiew = rand() % 4;
		if (rozsiew == 0)
		{
			proby = 3;
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
							Organizm* New = new Mlecz;
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
							Organizm* New = new Mlecz;
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
							Organizm* New = new Mlecz;
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
							Organizm* New = new Mlecz;
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
		else
			proby++;
	}
	
}
Organizm* Mlecz::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	return off;
}
void Mlecz::rysowanie()
{
	cout << " " << GetID();
}
Mlecz::~Mlecz() {

}