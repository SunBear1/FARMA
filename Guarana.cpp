#include "Klasy.h"
Guarana::Guarana()
{
	SetSila(0);
	SetInicjatywa(0);
	SetID('G');
	SetWiek(0);
	SetImie("Guarana");
}
void Guarana::SetX(int x)
{
	this->x = x;
}
void Guarana::SetY(int y)
{
	this->y = y;
}
int Guarana::GetX()
{
	return x;
}
int Guarana::GetY()
{
	return y;
}
string Guarana::GetImie()
{
	return imie;
}
int Guarana::GetSila()
{
	return sila;
}
char Guarana::GetID()
{
	return id;
}
void Guarana::SetImie(string imie)
{
	this->imie = imie;
}
void Guarana::SetSila(int sila)
{
	this->sila = sila;
}
int Guarana::GetInicjatywa()
{
	return inicjatywa;
}
void Guarana::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Guarana::GetWiek()
{
	return wiek;
}
void Guarana::SetID(char id)
{
	this->id = id;
}
void Guarana::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Guarana::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	bool brakruchu[4] = {};
	int rozsiew = rand() % 50;
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
						Organizm* New = new Guarana;
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
						Organizm* New = new Guarana;
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
						Organizm* New = new Guarana;
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
						Organizm* New = new Guarana;
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
Organizm* Guarana::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	SetSila(GetSila() + 3);
	cout << def->GetImie() << " zwieksza sile " << off->GetImie() << " o 3 pkt. Obecna sila " << off->GetImie() << " wynosi " << off->GetSila() <<endl;
	return off;
}
void Guarana::rysowanie()
{
	cout << " " << GetID();
}
Guarana::~Guarana() {

}