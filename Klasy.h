#pragma once
#include "Pakiety.h"

class Organizm
{
protected:
	int sila=0, inicjatywa=0, x=0, y=0,wiek=0,a=0,b=0,d=1;
	char id=' ';
	bool c = 0;
	bool* wlacz = &c;
	int* licznik = &a;
	int* cooldown = &b;
	int* szybkosc = &d;
	string imie;
public:
	virtual void akcja(Organizm***plansza, int* licznik, int* cooldown,bool* wlacz, int* szybkosc, int szerokosc, int wysokosc);
	virtual Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz,bool* zolwodparlatak, int szerokosc, int wysokosc);
	virtual void rysowanie();
	virtual void SetX(int x);
	virtual void SetY(int y);
	virtual void SetID(char id);
	virtual void SetImie(string imie);
	virtual void SetSila(int sila);
	virtual void SetWiek(int wiek);
	virtual void SetInicjatywa(int inicjatywa);
	virtual string GetImie();
	virtual char GetID();
	virtual int GetSila();
	virtual int GetInicjatywa();
	virtual int GetWiek();
	virtual int GetX();
	virtual int GetY();
	~Organizm();
};

class Swiat
{
private:
	Swiat* Ziemia;
	vector <Organizm*> Gra;
	void Sortowanie();
	void ZakonczTure();
	void Generuj();
	void Zapisz(int* licznik, int* cooldown, bool* wlacz, int* szybkosc);
	void Wczytaj(int* licznik, int* cooldown, bool* wlacz, int* szybkosc);
	void WykonajTure(int* licznik, int* cooldown, bool* wlacz, int* szybkosc);
	Organizm* DodajOrganizm(int x, int y, char id);
	void RysujSwiat();
public:
	Swiat(int szerokosc, int wysokosc);
	int szerokosc;
	int wysokosc;
	Organizm*** plansza;
	void Start();
	~Swiat();
};

class Zwierze : public Organizm
{
protected:
	virtual void Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc);
public:
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz,
		bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Zwierze();
};

class Roslina : public Organizm
{
public:
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz,
		bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Roslina();
};

class Antylopa : public Zwierze
{
public:
	Antylopa();
private:
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	Organizm* kolizja(Organizm* off,Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Antylopa();
};

class Owca : public Zwierze
{
public:
	Owca();
private:
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Owca();
};

class Lis : public Zwierze
{
public:
	Lis();
private:
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Lis();
};

class Zolw : public Zwierze
{
public:
	Zolw();
private:
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Zolw();
};

class Wilk : public Zwierze
{
public:
	Wilk();
private:
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Wilk();
};

class Trawa : public Roslina
{
public:
	Trawa();
private:
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Trawa();
};

class Mlecz : public Roslina
{
public:
	Mlecz();
private:
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Mlecz();
};

class Guarana : public Roslina
{
public:
	Guarana();
private:
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Guarana();
};

class WilczeJagody : public Roslina
{
public:
	WilczeJagody();
private:
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~WilczeJagody();
};

class Barszcz : public Roslina
{
public:
	Barszcz();
private:
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	void Eksterminacja(Organizm*** plansza, int szerokosc, int wysokosc);
	void SetX(int x) override;
	void SetY(int y) override;
	string GetImie() override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	void rysowanie() override;
	~Barszcz();
};

class Czlowiek : public Zwierze
{
public:
	Czlowiek();
private:
	void akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc) override;
	Organizm* kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc) override;
	void SetX(int x) override;
	void SetY(int y) override;
	char GetID()override;
	int GetSila()override;
	int GetX() override;
	int GetY() override;
	void SetImie(string imie) override;
	void SetID(char id) override;
	void SetSila(int sila) override;
	void SetWiek(int wiek) override;
	void SetInicjatywa(int inicjatywa) override;
	int GetInicjatywa() override;
	int GetWiek() override;
	string GetImie() override;
	void rysowanie() override;
	~Czlowiek();
};
