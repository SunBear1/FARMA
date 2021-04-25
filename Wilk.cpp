#include "Klasy.h"
Wilk::Wilk()
{
	SetSila(9);
	SetInicjatywa(5);
	SetID('W');
	SetWiek(0);
	SetImie("Wilk");
}
void Wilk::SetX(int x)
{
	this->x = x;
}
void Wilk::SetY(int y)
{
	this->y = y;
}
int Wilk::GetX()
{
	return x;
}
int Wilk::GetY()
{
	return y;
}
string Wilk::GetImie()
{
	return imie;
}
int Wilk::GetSila()
{
	return sila;
}
char Wilk::GetID()
{
	return id;
}
void Wilk::SetImie(string imie)
{
	this->imie = imie;
}
void Wilk::SetSila(int sila)
{
	this->sila = sila;
}
int Wilk::GetInicjatywa()
{
	return inicjatywa;
}
void Wilk::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Wilk::GetWiek()
{
	return wiek;
}
void Wilk::SetID(char id)
{
	this->id = id;
}
void Wilk::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Wilk::Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc)
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
					Organizm* dziecko = new Wilk;
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
					Organizm* dziecko = new Wilk;
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
					Organizm* dziecko = new Wilk;
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
					Organizm* dziecko = new Wilk;
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
void Wilk::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	while (1)
	{
		int kierunek = rand() % 4;
		if (kierunek == 0)
		{
			if (y > 0)
			{
				SetY(y - 1);
				break;
			}
			else
				kierunek = rand() % 4;
		}
		else if (kierunek == 1)
		{
			if (y < szerokosc - 1)
			{
				SetY(y + 1);
				break;
			}
			else
				kierunek = rand() % 4;

		}
		else if (kierunek == 2)
		{
			if (x < wysokosc - 1)
			{
				SetX(x + 1);
				break;
			}
			else
				kierunek = rand() % 4;
		}
		else
		{
			if (x > 0)
			{
				SetX(x - 1);
				break;
			}
			else
				kierunek = rand() % 4;
		}
	}
	cout << GetImie() << " poruszył się na " << GetX() << " " << GetY() << endl;
}
Organizm* Wilk::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	if (def->GetID() == off->GetID())
	{
		*rozmnoz = true;
		Rozmnazanie(def, plansza, szerokosc, wysokosc);
		return def;
	}
	else if (def->GetID() == GetID()) //wilk broni
	{
		if (def->GetSila() > off->GetSila())
		{
			cout << def->GetImie() << " wygyrwa z " << off->GetImie() <<endl;
			return def;
		}
		else
		{
			cout << def->GetImie() << " przegrywa z " << off->GetImie() << endl;
			return off;
		}
			
	}
	else if (off->GetID() == GetID()) //wilk atakuje
	{
		if (off->GetSila() > def->GetSila())
		{
			if (off == def->kolizja(off, def, plansza, rozmnoz, zolwodparlatak,szerokosc,wysokosc)) //broniący sprawdza czy jego super skille go obroniły
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
void Wilk::rysowanie()
{
	cout << " " << GetID();
}
Wilk::~Wilk()
{

}