#include "Klasy.h"
Lis::Lis()
{
	SetSila(3);
	SetInicjatywa(7);
	SetID('L');
	SetWiek(0);
	SetImie("Lis");
}
void Lis::SetX(int x)
{
	this->x = x;
}
void Lis::SetY(int y)
{
	this->y = y;
}
int Lis::GetX()
{
	return x;
}
int Lis::GetY()
{
	return y;
}
string Lis::GetImie()
{
	return imie;
}
int Lis::GetSila()
{
	return sila;
}
char Lis::GetID()
{
	return id;
}
void Lis::SetImie(string imie)
{
	this->imie = imie;
}
void Lis::SetSila(int sila)
{
	this->sila = sila;
}
int Lis::GetInicjatywa()
{
	return inicjatywa;
}
void Lis::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Lis::GetWiek()
{
	return wiek;
}
void Lis::SetID(char id)
{
	this->id = id;
}
void Lis::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Lis::Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc)
{
	bool brakruchu[4] = {};
	Organizm* dziecko;
	while (1)
	{
		if (brakruchu[0] && brakruchu[1] && brakruchu[2] && brakruchu[3])
			break;
		int kierunek = rand() % 4;
		if (kierunek == 0)
		{
			if (rodzic->GetY() > 0)
			{
				if (dynamic_cast<Organizm*>(plansza[rodzic->GetX()][rodzic->GetY() - 1]) == nullptr)
				{
					Organizm* dziecko = new Lis;
					dziecko->SetX(rodzic->GetX());
					dziecko->SetY(rodzic->GetY() - 1);
					plansza[rodzic->GetX()][rodzic->GetY() - 1] = dziecko;
					cout << dziecko->GetImie() << " rozmnozyl się na " << dziecko->GetX() << " " << dziecko->GetY() << endl;
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
			if (rodzic->GetY() < szerokosc + 1)
			{
				if (dynamic_cast<Organizm*>(plansza[rodzic->GetX()][rodzic->GetY() + 1]) == nullptr)
				{
					Organizm* dziecko = new Lis;
					dziecko->SetX(rodzic->GetX());
					dziecko->SetY(rodzic->GetY() + 1);
					plansza[rodzic->GetX()][rodzic->GetY() + 1] = dziecko;
					cout << dziecko->GetImie() << " rozmnozyl się na " << dziecko->GetX() << " " << dziecko->GetY() << endl;
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
			if (rodzic->GetX() < wysokosc + 1)
			{
				if (dynamic_cast<Organizm*>(plansza[rodzic->GetX() + 1][rodzic->GetY()]) == nullptr)
				{
					Organizm* dziecko = new Lis;
					dziecko->SetX(rodzic->GetX() + 1);
					dziecko->SetY(rodzic->GetY());
					plansza[rodzic->GetX() + 1][rodzic->GetY()] = dziecko;
					cout << dziecko->GetImie() << " rozmnozyl się na " << dziecko->GetX() << " " << dziecko->GetY() << endl;
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
			if (rodzic->GetX() > 0)
			{
				if (dynamic_cast<Organizm*>(plansza[rodzic->GetX() - 1][rodzic->GetY()]) == nullptr)
				{
					Organizm* dziecko = new Lis;
					dziecko->SetX(rodzic->GetX() - 1);
					dziecko->SetY(rodzic->GetY());
					plansza[rodzic->GetX() - 1][rodzic->GetY()] = dziecko;
					cout << dziecko->GetImie() << " rozmnozyl się na " << dziecko->GetX() << " " << dziecko->GetY() << endl;
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
void Lis::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	bool brakruchu[4] = {};
	while (1)
	{
		if (brakruchu[0] && brakruchu[1] && brakruchu[2] && brakruchu[3])
			break;
		int kierunek = rand() % 4;
		if (kierunek == 0)
		{
			if (y > 0)
			{
				if (dynamic_cast<Zwierze*>(plansza[x][y - 1]) != nullptr)
				{
					if (plansza[x][y - 1]->GetSila() < this->GetSila())
					{
						SetY(y - 1);
						break;
					}
					else
						brakruchu[kierunek] = 1;
				}
				else
				{
					SetY(y - 1);
					break;
				}
				
			}
			else
				kierunek = rand() % 4;
		}
		else if (kierunek == 1)
		{
			if (y < szerokosc - 1)
			{
				if (dynamic_cast<Zwierze*>(plansza[x][y + 1]) != nullptr)
				{
					if (plansza[x][y + 1]->GetSila() < this->GetSila())
					{
						SetY(y + 1);
						break;
					}
					else
						brakruchu[kierunek] = 1;
				}
				else
				{
					SetY(y + 1);
					break;
				}
			}
			else
				kierunek = rand() % 4;

		}
		else if (kierunek == 2)
		{
			if (x < wysokosc - 1)
			{
				if (dynamic_cast<Zwierze*>(plansza[x + 1][y]) != nullptr)
				{
					if (plansza[x + 1][y]->GetSila() < this->GetSila())
					{
						SetX(x + 1);
						break;
					}
					else
						brakruchu[kierunek] = 1;
				}
				else
				{
					SetX(x + 1);
					break;
				}
			}
			else
				kierunek = rand() % 4;
		}
		else
		{
			if (x > 0)
			{
				if (dynamic_cast<Zwierze*>(plansza[x - 1][y]) != nullptr)
				{
					if (plansza[x - 1][y]->GetSila() < this->GetSila())
					{
						SetX(x - 1);
						break;
					}
					else
						brakruchu[kierunek] = 1;
				}
				else
				{
					SetX(x - 1);
					break;
				}
			}
			else
				kierunek = rand() % 4;
		}
	}
	cout << GetImie() << " poruszył się na " << GetX() << " " << GetY() << endl;
}
Organizm* Lis::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	if (def->GetID() == off->GetID())
	{
		*rozmnoz = true;
		Rozmnazanie(def, plansza, szerokosc, wysokosc);
		return def;
	}
	else if (def->GetID() == GetID()) //Lis broni
	{
		if (def->GetSila() > off->GetSila())
		{
			cout << def->GetImie() << " wygyrwa z " << off->GetImie() << endl;
			return def;
		}
		else
		{
			cout << def->GetImie() << " przegrywa z " << off->GetImie() << endl;
			return off;
		}

	}
	else if (off->GetID() == GetID()) //Lis atakuje
	{
		if (off->GetSila() > def->GetSila())
		{
			if (off == def->kolizja(off, def, plansza, rozmnoz, zolwodparlatak,szerokosc, wysokosc)) //broniący sprawdza czy jego super skille go obroniły
			{
				cout << off->GetImie() << " wygyrwa z " << def->GetImie() << endl;
				return off;
			}
		}
		else
		{
			cout << off->GetImie() << " przegrywa z " << def->GetImie() << endl;
			return def;
		}
	}
}
void Lis::rysowanie()
{
	cout << " " << GetID();
}
Lis::~Lis()
{

}