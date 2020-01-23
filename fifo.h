#pragma once
#include "systemc.h"
#include "stdafx.h"
#include "interface.h"

class fifo : public sc_channel, public write_if, public read_if
{
	sc_mutex muteks;
	sc_fifo<int> kolejka;

public:
	fifo(sc_module_name nazwa) :sc_channel(nazwa), kolejka(24), muteks()
	{

	}

	void write(int wartosc)
	{
		muteks.lock();
		kolejka.write(wartosc);
		muteks.unlock();
	}

	void read(int &wartosc)
	{
		kolejka.read(wartosc);
	}

	void reset()
	{

	}

};
