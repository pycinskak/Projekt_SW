#pragma once
#include "stdafx.h"
#include "systemc.h"
#include "interface.h"
#include "modul.h"
#include "fifo.h"
#include "Procesor2.h"

void procesor2::zadanie2()
{
	int aktualnaOpcja;
	int poprzedniaOpcja = 0;
	while (true)
	{
		if (reset.read() == 1)
			poprzedniaOpcja = 0;
		else
		{
			in->read(aktualnaOpcja);
			system("cls");
			if (poprzedniaOpcja == 0)
			{
				if (aktualnaOpcja == 2)
					cout << "50 C w pralce(Uruchomiony z 2 procesora)" << endl;
			}
			poprzedniaOpcja = aktualnaOpcja;
		}
	}
}

void procesor2::main() {
	int wartosc;

	while (true)
	{
		wait();
		in->read(wartosc);
		//kolejka->write(wartosc);
	}
}
