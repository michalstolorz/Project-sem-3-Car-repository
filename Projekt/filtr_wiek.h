#pragma once
#include "filtr.h"
#include "Wlasciciele.h"
#include "Samochody.h"
#include "Relacje.h"
#include "wielkosci_tablic.h"
#include <ctime>
#include <string>
class filtr_wiek : public filtr
{
public:
	filtr_wiek();
	virtual void filtrowanie(Wlasciciele *wlasciciel, Samochody *samochod, Relacje *relacja, string nazwa_pliku_wyjsciowego);
	~filtr_wiek();
};

