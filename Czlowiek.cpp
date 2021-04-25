#include "Klasy.h"
Czlowiek::Czlowiek()
{
	SetSila(5);
	SetInicjatywa(4);
	SetID('C');
	SetWiek(0);
	SetImie("Czlowiek");
}
void Czlowiek::SetX(int x)
{
	this->x = x;
}
void Czlowiek::SetY(int y)
{
	this->y = y;
}
int Czlowiek::GetX()
{
	return x;
}
int Czlowiek::GetY()
{
	return y;
}
string Czlowiek::GetImie()
{
	return imie;
}
int Czlowiek::GetSila()
{
	return sila;
}
char Czlowiek::GetID()
{
	return id;
}
void Czlowiek::SetImie(string imie)
{
	this->imie = imie;
}
void Czlowiek::SetSila(int sila)
{
	this->sila = sila;
}
int Czlowiek::GetInicjatywa()
{
	return inicjatywa;
}
void Czlowiek::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Czlowiek::GetWiek()
{
	return wiek;
}
void Czlowiek::SetID(char id)
{
	this->id = id;
}
void Czlowiek::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Czlowiek::akcja(Organizm*** plansza,int * licznik, int*cooldown,bool *wlacz, int*szybkosc, int szerokosc, int wysokosc)
{
	int key = 0,szansa;
	if ((*licznik == 0) && (*wlacz == false))
		*cooldown += 1;
	if (*wlacz == true && *cooldown > 5)
	{
		if (*licznik < 4)
			*szybkosc = 2;
		else if (*licznik < 6)
		{
			szansa = rand() % 2;
			if (szansa == 0)
				*szybkosc = 2;
		}
		else
		{
			*wlacz = false;
			*licznik = 0;
			*cooldown = 0;
			*szybkosc = 1;
			cout << "ULT przestal dzialac " << endl;
		}
	}
	else
	{
		*szybkosc = 1;
		*cooldown += 1;
	}
	while (!(key == GORA || key == DOL || key == LEWO || key == PRAWO || key == ULT))
	{
		key = _getch();
		switch (key)
		{
		case GORA:
			if(x > *szybkosc - 1)
				SetX(x - *szybkosc);
			break;
		case DOL:
			if (x < wysokosc - *szybkosc)
				SetX(x + *szybkosc);
			break;
		case LEWO:
			if (y > *szybkosc - 1)
				SetY(y - *szybkosc);
			break;
		case PRAWO:
			if (y < szerokosc - *szybkosc)
			SetY(y + *szybkosc);
			break;
		case ULT:
			if (*cooldown < 6)
				cout << "ULT NIE GOTOWY " << endl;
			if (*wlacz == false && *cooldown > 5)
			{
				cout << "ULT wlaczony" << endl;
				*wlacz = true;
			}	
			break;
		}
	}
	cout << "Ruszasz sie na pole " << GetX() << " " << GetY() << endl;
}
Organizm* Czlowiek::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	if (def->GetID() == GetID()) //owca broni
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
	else if (off->GetID() == GetID()) //owca atakuje
	{
		if (off->GetSila() > def->GetSila())
		{
			if (off == def->kolizja(off, def, plansza, rozmnoz, zolwodparlatak, szerokosc, wysokosc)) //broniący sprawdza czy jego super skille go obroniły
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
void Czlowiek::rysowanie()
{
	cout << " " << GetID();
}
Czlowiek::~Czlowiek()
{

}