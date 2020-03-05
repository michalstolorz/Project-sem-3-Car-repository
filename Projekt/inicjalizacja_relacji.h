#pragma once
#ifndef _INCJALIZACJA_RELACJI_H_
#define _INCJALIZACJA_RELACJI_H_
#include "Relacje.h"
#include "wielkosci_tablic.h"
#include <fstream>
Relacje *inicjalizacja_relacji(string argv);
void wpisywanie_relacji_do_tablicy(Relacje &wsk, string bufor);
#endif#