#include "Klasy.h"
Swiat::Swiat(int szerokosc,int wysokosc)
{
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;
	plansza = new Organizm **[wysokosc];
	for (int i = 0; i < wysokosc; i++)
	{
		plansza[i] = new Organizm*[szerokosc];
	}	
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			plansza[i][j] = NULL;
		}	
	}
}
Organizm* Swiat::DodajOrganizm(int x, int y,char id)
{
	if (id == 'A')
	{
		Organizm* New = new Antylopa;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if (id == 'O')
	{
		Organizm* New = new Owca;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if (id == 'W')
	{
		Organizm* New = new Wilk;
		New->SetX(x);
		New->SetY(y);
		return New;
	}	
	else if (id == 'L')
	{
		Organizm* New = new Lis;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if (id == 'Z')
	{
		Organizm* New = new Zolw;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if (id == 'T')
	{
		Organizm* New = new Trawa;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if (id == 'M')
	{
		Organizm* New = new Mlecz;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if (id == 'J')
	{
		Organizm* New = new WilczeJagody;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if (id == 'G')
	{
		Organizm* New = new Guarana;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if (id == 'B')
	{
		Organizm* New = new Barszcz;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
	else if(id == 'C')
	{
		Organizm* New = new Czlowiek;
		New->SetX(x);
		New->SetY(y);
		return New;
	}
}
void Swiat::Wczytaj(int* licznik, int* cooldown, bool* wlacz, int* szybkosc)
{
	int wiek, inicjatywa, sila, x, y, a, b, d ,iloscorganizmow;
	char id;
	bool c = 0;
	string nazwa;
	cout << "Wpisz nazwe swiata do wczytywania: " << endl;
	cin >> nazwa;
	ifstream plik(nazwa += ".txt");
	plik >> szerokosc >> wysokosc;
	for ( int i = 0; i < wysokosc; i++)
	{
		delete[] plansza[i];
	}
	delete[] plansza;
	plansza = new Organizm **[wysokosc];
	for (int i = 0; i < wysokosc; i++)
	{
		plansza[i] = new Organizm *[szerokosc];
	}
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			plansza[i][j] = NULL;
		}
	}
	plik >> iloscorganizmow;
	for (int i = 0; i < iloscorganizmow; i++)
	{
		plik >> id >> x >> y >> wiek >> sila;
		if (id == 'C')
		{
			plik >> *cooldown >> *licznik >> *szybkosc >> *wlacz;
			plansza[x][y] = DodajOrganizm(x, y, id);
			plansza[x][y]->SetWiek(wiek);
			plansza[x][y]->SetSila(sila);
		}
		else
		{
			plansza[x][y] = DodajOrganizm(x, y, id);
			plansza[x][y]->SetWiek(wiek);
			plansza[x][y]->SetSila(sila);
		}
	}
}
void Swiat::Generuj()
{
	int randx, randy,i = 0;
	while(i < 15)
	{
		randy = rand() % szerokosc;
		randx = rand() % wysokosc;
		if (plansza[randx][randy] == NULL)
		{
			if (i < 2)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'W');
			else if (i < 4)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'O');
			else if (i < 6)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'A');
			else if (i < 8)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'L');
			else if (i < 9)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'Z');
			else if (i < 10)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'T');
			else if (i < 11)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'M');
			else if (i < 12)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'J');
			else if (i < 13)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'B');
			else if (i < 14)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'C');
			else if (i < 15)
				plansza[randx][randy] = DodajOrganizm(randx, randy, 'G');
			i++;
		}
	}
		
}
void Swiat::Start()
{
	int a = 0, b = 6,d = 1;
	bool c = 0;
	bool* wlacz = &c;
	int* licznik = &a;
	int* cooldown = &b;
	int* szybkosc = &d;
	bool czlowiekzyje = true;
	cout << "Naciscij l aby zaladowac zapisany stan rozgrywki. W przeciwnym wypadku nacisnij dowolny przycisk " << endl;
	int key = _getch();
	if (key == WCZYTAJ)
	{
		system("cls");
		Wczytaj(licznik, cooldown, wlacz, szybkosc);
	}
	else
	{
		Generuj();
		/*plansza[2][2] = DodajOrganizm(2, 2, 'C');
		//plansza[18][19] = DodajOrganizm(18, 19, 'O');
		plansza[0][0] = DodajOrganizm(0, 0, 'O');
		plansza[1][0] = DodajOrganizm(1, 0, 'O');
		*/	
	}
	while(1)
	{
		ZakonczTure();
		cout << endl;
		system("cls");
		WykonajTure(licznik, cooldown, wlacz, szybkosc);
		RysujSwiat();
		czlowiekzyje = false;
		for (int j = 0; j < Gra.size(); j++)
		{
			if (Gra[j] != NULL && Gra[j]->GetID() == 'C')
				czlowiekzyje = true;
		}
		if (czlowiekzyje == false)
		{
			system("cls");
			cout << endl<<endl<<endl<<"          YOU DIED";
			break;
		}
		int key = _getch();
		if (key == ZAPISZ)
			Zapisz(licznik, cooldown, wlacz, szybkosc);
	}
}
void Swiat::RysujSwiat()
{
	for (int i = -1; i < wysokosc + 1; i++)
	{
		for (int j = -1; j < szerokosc + 1; j++)
		{
			if (i < 0)
				cout << "# ";
			else if(i > wysokosc - 1)
				cout << "# ";
			else if (j > szerokosc - 1)
				cout << " #";
			else if (j < 0)
				cout << "#";
			else if (plansza[i][j] != NULL)
				plansza[i][j]->rysowanie();
			else
				cout <<"  ";
		}
		cout << endl;
	}
}

void Swiat::WykonajTure(int* licznik, int* cooldown, bool* wlacz, int* szybkosc) {
	int x1,y1;
	Organizm* t; 
	for (int i = Gra.size()-1; i >= 0; i--)
	{
		if (Gra[i] != NULL)
		{
			x1 = Gra[i]->GetX();
			y1 = Gra[i]->GetY();
			if (Gra[i]->GetID() == 'Z')
			{
				int ruchzolwia = rand() % 4;
				if (ruchzolwia == 3)
				{
					Gra[i]->akcja(plansza,licznik,cooldown,wlacz,szybkosc,szerokosc,wysokosc);
					if (plansza[Gra[i]->GetX()][Gra[i]->GetY()] == NULL)
					{
						plansza[Gra[i]->GetX()][Gra[i]->GetY()] = Gra[i];
						plansza[x1][y1] = NULL;
					}
				}
				else
					cout << Gra[i]->GetImie() << " nie poruszyl sie " << endl;
			}
			else
			{
				Gra[i]->akcja(plansza, licznik, cooldown,wlacz,szybkosc, szerokosc, wysokosc);
				if (Gra[i]->GetID() == 'C' && *wlacz == true)
				{
					*licznik += 1;
				}
				if (plansza[Gra[i]->GetX()][Gra[i]->GetY()] == plansza[x1][y1])
					plansza[Gra[i]->GetX()][Gra[i]->GetY()] = Gra[i];
				else if (plansza[Gra[i]->GetX()][Gra[i]->GetY()] == NULL)
				{
					plansza[Gra[i]->GetX()][Gra[i]->GetY()] = Gra[i];
					plansza[x1][y1] = NULL;
				}
				else if(dynamic_cast<Roslina*>(Gra[i]) == nullptr)
				{
					bool f = false,g = false;
					bool* rozmnoz = &g;
					bool* zolwodparlatak = &f;
					Organizm* obronca = plansza[Gra[i]->GetX()][Gra[i]->GetY()];
					char atakujacy = Gra[i]->GetID();
					plansza[Gra[i]->GetX()][Gra[i]->GetY()] = Gra[i]->kolizja(Gra[i], plansza[Gra[i]->GetX()][Gra[i]->GetY()], plansza,rozmnoz,zolwodparlatak, szerokosc, wysokosc);
					if (*rozmnoz == true && obronca->GetWiek() > 3)
					{
						*rozmnoz = false;
					}
					else if (*rozmnoz == true && obronca->GetWiek() < 4)
					{
						*rozmnoz = false;
					}
					else if (atakujacy == plansza[Gra[i]->GetX()][Gra[i]->GetY()]->GetID())
					{
						for (int j = 0; j < Gra.size(); j++)
						{
							if (Gra[j] != NULL && obronca == Gra[j])
								Gra[j] = NULL;
						}
						//if (obronca->id != 'Z' && *zolwodparlatak == false)
							plansza[x1][y1] = NULL; //sprawdzić czy można to wywalić
					}	
					else
					{
						if (obronca->GetID() != 'Z' && *zolwodparlatak == false)
						{
							Gra[i] = NULL;
							plansza[x1][y1] = NULL;
						}
						else
						{
							Gra[i]->SetX(x1);
							Gra[i]->SetY(y1);
						}
					}	
				}
			}
		}	
	}
}
void Swiat::Sortowanie()
{
	for (int i = 0; i < Gra.size()-1; i++)
	{
		for (int j = 0; j < Gra.size() - i - 1; j++)
		{
			if (Gra[j]->GetInicjatywa() == Gra[j+1]->GetInicjatywa())
			{
				if (Gra[j]->GetWiek() > Gra[j+1]->GetWiek())
				{
					swap(Gra[j], Gra[j + 1]);
				}
			}
			else if (Gra[j]->GetInicjatywa() > Gra[j+1]->GetInicjatywa())
			{
				swap(Gra[j], Gra[j + 1]);
			}
		}
	}
}
void Swiat::Zapisz(int* licznik, int* cooldown, bool* wlacz, int* szybkosc)
{
	int iloscorganizmow = 0;
	system("cls");
	cout << "Wpisz nazwe pliku ";
	string nazwa;
	cin >> nazwa;
	ofstream plik(nazwa+=".txt");
	cout << "Nazwa pliku: ";
	plik << szerokosc <<" "<< wysokosc << endl;
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			if (plansza[i][j] != NULL)
				iloscorganizmow++;
		}
	}
	plik << iloscorganizmow<<endl;
	for (int j = 0; j < wysokosc; j++)
	{
		for (int i = 0; i < szerokosc; i++) {
			if (plansza[i][j] != NULL)
			{
				plik << plansza[i][j]->GetID() << " ";
				plik << plansza[i][j]->GetX() << " " << plansza[i][j]->GetY() << " ";
				plik << plansza[i][j]->GetWiek() << " ";
				plik << plansza[i][j]->GetSila() << " ";
				if (plansza[i][j]->GetID() == 'C') {
					plik << *cooldown << " ";
					plik << *licznik << " ";
					plik << *szybkosc << " ";
					plik << *wlacz << " ";
				}
				plik << endl;
			}
		}
	}
	plik.close();
	cout << "Plik " << nazwa << " zostal koncertowo zapisany. Kliknij jakikoliwke przycisk aby wznowic rozgrywke!" << endl;
	if (_getch() == 224)
		_getch();
	system("cls");
}
void Swiat::ZakonczTure()
{
	if(!Gra.empty())
		Gra[0] = NULL;

	Gra.clear();

	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			if (dynamic_cast<Organizm*>(plansza[i][j]) != nullptr)
				Gra.push_back(plansza[i][j]);
		}
	}
	if(!Gra.empty())
		Sortowanie();
	for (int i = 0; i < Gra.size(); i++)
	{
		Gra[i]->SetWiek(Gra[i]->GetWiek() + 1);
	}
}
Swiat::~Swiat()
{
	cout << endl <<"          Łukasz Niedźwiadek 180102" << endl << endl << endl;
}