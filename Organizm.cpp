#include "Klasy.h"
void Organizm::SetX(int x)
{
	this->x = x;
}
int Organizm::GetX()
{
	return x;
}
void Organizm::SetY(int y)
{
	this->y = y;
}
int Organizm::GetY()
{
	return y;
}
char Organizm::GetID()
{
	return id;
}
string Organizm::GetImie()
{
	return imie;
}
void Organizm::SetImie(string imie)
{
	this->imie = imie;
}
int Organizm::GetSila()
{
	return sila;
}
void Organizm::SetSila(int sila)
{
	this->sila = sila;
}
int Organizm::GetInicjatywa()
{
	return inicjatywa;
}
void Organizm::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
int Organizm::GetWiek()
{
	return wiek;
}
void Organizm::SetID(char id)
{
	this->id = id;
}
void Organizm::SetWiek(int wiek)
{
	this->wiek = wiek;
}

void Organizm::akcja(Organizm*** plansza, int* licznik, int* cooldown, bool* wlacz, int* szybkosc, int szerokosc, int wysokosc)
{
	
}
Organizm* Organizm::kolizja(Organizm* off, Organizm* def, Organizm*** plansza, bool* rozmnoz, bool* zolwodparlatak, int szerokosc, int wysokosc)
{
	return def;
}
void Organizm::rysowanie()
{
	
}
Organizm::~Organizm()
{

}