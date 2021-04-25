#include "Klasy.h"
Antylopa::Antylopa()
{
	SetSila(4);
	SetInicjatywa(4);
	SetID('A');
	SetWiek(0);
	SetImie("Antylopa");
}
void Antylopa::SetX(int x)
{
	this->x = x;
}
void Antylopa::SetY(int y)
{
	this->y = y;
}
int Antylopa::GetX()
{
	return x;
}
int Antylopa::GetY()
{
	return y;
}
string Antylopa::GetImie()
{
	return imie;
}
int Antylopa::GetSila()
{
	return sila;
}
char Antylopa::GetID()
{
	return id;
}
void Antylopa::SetImie(string imie)
{
	this->imie = imie;
}
void Antylopa::SetSila(int sila)
{
	this->sila = sila;
}
int Antylopa::GetInicjatywa()
{
	return inicjatywa;
}
void Antylopa::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Antylopa::GetWiek()
{
	return wiek;
}
void Antylopa::SetID(char id)
{
	this->id = id;
}
void Antylopa::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Antylopa::Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc)
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
					Organizm* dziecko = new Antylopa;
					dziecko->SetX(rodzic->GetX());
					dziecko->SetY(rodzic->GetY() - 1);
					plansza[rodzic->GetX()][rodzic->GetY() - 1] = dziecko;
					cout << dziecko->GetImie() << " rozmnozyla się na " << dziecko->GetX() << " " << dziecko->GetY() << endl;
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
					Organizm* dziecko = new Antylopa;
					dziecko->SetX(rodzic->GetX());
					dziecko->SetY(rodzic->GetY() + 1);
					plansza[rodzic->GetX()][rodzic->GetY() + 1] = dziecko;
					cout << dziecko->GetImie() << " rozmnozyla się na " << dziecko->GetX() << " " << dziecko->GetY() << endl;
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
					Organizm* dziecko = new Antylopa;
					dziecko->SetX(rodzic->GetX() + 1);
					dziecko->SetY(rodzic->GetY());
					plansza[rodzic->GetX() + 1][rodzic->GetY()] = dziecko;
					cout << dziecko->GetImie() << " rozmnozyla się na " << dziecko->GetX() << " " << dziecko->GetY() << endl;
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
					Organizm* dziecko = new Antylopa;
					dziecko->SetX(rodzic->GetX() - 1);
					dziecko->SetY(rodzic->GetY());
					plansza[rodzic->GetX() - 1][rodzic->GetY()] = dziecko;
					cout << dziecko->GetImie() << " rozmnozyla się na " << dziecko->GetX() << " " << dziecko->GetY() << endl;
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
void Antylopa::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	while (1)
	{
		int kierunek = rand() % 4;
		if (kierunek == 0)
		{
			if (y > 1)
			{
				SetY(y - 2);
				break;
			}
			else
				kierunek = rand() % 4;
		}
		else if (kierunek == 1)
		{
			if (y < szerokosc - 2)
			{
				SetY(y + 2);
				break;
			}
			else
				kierunek = rand() % 4;

		}
		else if (kierunek == 2)
		{
			if (x < wysokosc - 2)
			{
				SetX(x + 2);
				break;
			}
			else
				kierunek = rand() % 4;
		}
		else
		{
			if (x > 1)
			{
				SetX(x - 2);
				break;
			}
			else
				kierunek = rand() % 4;
		}
	}
	cout << GetImie() << " poruszyła się na " << GetX() << " " << GetY() << endl;
}
Organizm* Antylopa::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	int ucieczka = rand() % 2;
	if (def->GetID() == off->GetID())
	{
		*rozmnoz = true;
		Rozmnazanie(def,plansza,szerokosc,wysokosc);
		return off;
	}
	else if (ucieczka == 1 && dynamic_cast<Zwierze*>(def) != nullptr)
	{
		bool brakruchu[4] = {};
		while (1)
		{
			if (brakruchu[0] && brakruchu[1] && brakruchu[2] && brakruchu[3])
				break;
			int kierunek = rand() % 4;
			if (kierunek == 0)
			{
				if (y > 0 && dynamic_cast<Organizm*>(plansza[x][y - 1]) == nullptr)
				{
					SetY(y - 1);
					if (def->GetID() == GetID())
					{
						plansza[x][y] = def;
						cout << GetImie() << " ucieka przed "<<off->GetImie()<<" na pole " << GetX() << " " << GetY() << endl;
						return off;
					}
					else
					{
						plansza[x][y] = off;
						cout << GetImie() << " ucieka przed " << def->GetImie() << " na pole " << GetX() << " " << GetY() << endl;
						return def;
					}
				}
				else
				{
					brakruchu[kierunek] = 1;
					kierunek = rand() % 4;
				}
					
			}
			else if (kierunek == 1)
			{
				if (y < szerokosc - 1 && dynamic_cast<Organizm*>(plansza[x][y + 1]) == nullptr)
				{
					SetY(y + 1);
					if (def->GetID() == GetID())
					{
						plansza[x][y] = def;
						cout << GetImie() << " ucieka przed " << def->GetImie() << " na pole " << GetX() << " " << GetY() << endl;
						return off;
					}
					else
					{
						plansza[x][y] = off;
						cout << GetImie() << " ucieka przed " << def->GetImie() << " na pole " << GetX() << " " << GetY() << endl;
						return def;
					}
				}
				else
				{
					brakruchu[kierunek] = 1;
					kierunek = rand() % 4;
				}

			}
			else if (kierunek == 2)
			{
				if (x < wysokosc - 1 && dynamic_cast<Organizm*>(plansza[x + 1][y]) == nullptr)
				{
					SetX(x + 1);
					if (def->GetID() == GetID())
					{
						plansza[x][y] = def;
						cout << GetImie() << " ucieka przed " << def->GetImie() << " na pole " << GetX() << " " << GetY() << endl;
						return off;
					}
					else
					{
						plansza[x][y] = off;
						cout << GetImie() << " ucieka przed " << def->GetImie() << " na pole " << GetX() << " " << GetY() << endl;
						return def;
					}
				}
				else
				{
					brakruchu[kierunek] = 1;
					kierunek = rand() % 4;
				}
			}
			else if (kierunek == 3)
			{
				if (x > 0 && dynamic_cast<Organizm*>(plansza[x - 1][y]) == nullptr)
				{
					SetX(x - 1);
					if (def->GetID() == GetID())
					{
						plansza[x][y] = def;
						cout << GetImie() << " ucieka przed " << def->GetImie() << " na pole " << GetX() << " " << GetY() << endl;
						return off;
					}
					else
					{
						plansza[x][y] = off;
						cout << GetImie() << " ucieka przed " << def->GetImie() << " na pole " << GetX() << " " << GetY() << endl;
						return def;
					};
				}
				else
				{
					brakruchu[kierunek] = 1;
					kierunek = rand() % 4;
				}
			}
		}
	}
	else if (def->GetID() == GetID()) //antylopa broni
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
	else if (off->GetID() == GetID()) //antylopa atakuje
	{
		if (off->GetSila() > def->GetSila())
		{
			if (off == def->kolizja(off, def, plansza, rozmnoz,zolwodparlatak,szerokosc,wysokosc))
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
void Antylopa::rysowanie()
{
	cout << " " << GetID();
}
Antylopa::~Antylopa()
{
	
}