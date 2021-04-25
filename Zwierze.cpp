#include "Klasy.h"
void Zwierze::SetX(int x)
{
	this->x = x;
}
void Zwierze::SetY(int y)
{
	this->y = y;
}
int Zwierze::GetX()
{
	return x;
}
int Zwierze::GetY()
{
	return y;
}
int Zwierze::GetSila()
{
	return sila;
}
char Zwierze::GetID()
{
	return id;
}
string Zwierze::GetImie()
{
	return imie;
}
void Zwierze::SetImie(string imie)
{
	this->imie = imie;
}
void Zwierze::SetSila(int sila)
{
	this->sila = sila;
}
void Zwierze::Rozmnazanie(Organizm* rodzic, Organizm*** plansza, int szerokosc, int wysokosc)
{

}
int Zwierze::GetInicjatywa()
{
	return inicjatywa;
}
void Zwierze::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Zwierze::GetWiek()
{
	return wiek;
}
void Zwierze::SetID(char id)
{
	this->id = id;
}
void Zwierze::SetWiek(int wiek)
{
	this->wiek = wiek;
}
void Zwierze::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{

}
Organizm* Zwierze::kolizja(Organizm* off, Organizm* def, Organizm*** plansza,bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	return def;
}
void Zwierze::rysowanie()
{

}
Zwierze::~Zwierze()
{

}