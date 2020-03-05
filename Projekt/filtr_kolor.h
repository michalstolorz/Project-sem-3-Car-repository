#pragma once
#include "filtr.h"
#include "Wlasciciele.h"
#include "Samochody.h"
#include "Relacje.h"
#include "wielkosci_tablic.h"
class filtr_kolor : public filtr
{
public:
	filtr_kolor();
	virtual void filtrowanie(Wlasciciele *wlasciciel, Samochody *samochod, Relacje *relacja, string nazwa_pliku);
	~filtr_kolor();
};

