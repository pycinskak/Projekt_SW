#include "stdafx.h"
#include "systemc.h"
#include "procesor1.h"

void procesor1::input()
{
	system("cls");
	cout << "TRYB:";
	int opcja = 0;
	while (true)
	{
		wait();
		cin >> opcja;
		system("cls");
		out->write(opcja); //dodawanie do outa (kolejki)
		program.write(opcja); //dodawanie do bufera
	}
}

void procesor1::output()
{
	int poprzedniaOpcja = 0;
	int aktualnaOpcja = 0;
	bool isTrue = true;
	bool tablicaWlaczonych[6] = { false };
	int licznik = 0;
	while (true)
	{
		wait();
		if (reset.read() == 1)
		{
			poprzedniaOpcja = 0;
			cout << "Wszystkie programy wylaczone" << endl;
			reset_out.write(false);
			for (int i = 0; i < 6; i++)
			{
				tablicaWlaczonych[i] = false;
			}
		}
		else
		{
			aktualnaOpcja = program.read();
			licznik = 0;
			if (aktualnaOpcja == 0)
			{
				cout << "Wszystkie programy wylaczone" << endl;
			}
			if (aktualnaOpcja != 113)
			{

				cout << "40          50          60          65          70           90          Error" << endl;
				if (aktualnaOpcja == 0)
				{
					for (int i = 0; i < 6; i++)
					{
						tablicaWlaczonych[i] = false;
					}
				}
				if (aktualnaOpcja > 0 && aktualnaOpcja < 7)
				{
					if(tablicaWlaczonych[aktualnaOpcja - 1] == false) tablicaWlaczonych[aktualnaOpcja - 1] = true;

					else
					{
						tablicaWlaczonych[aktualnaOpcja - 1] = false;
					}
				}
				for (int i = 0; i < 6; i++)
				{
					if (tablicaWlaczonych[i])
					{
						cout << "On          ";
						licznik++;
					}
					else
						cout << "Off         ";
				}
				if (licznik > 1 || aktualnaOpcja > 6)
					cout << "ERROR" << endl;
				else
					cout << "     " << endl;
			}
			poprzedniaOpcja = aktualnaOpcja;
			if (aktualnaOpcja == 113) {
				sc_stop();
				exit(1);
			}
		}
	}
}

void procesor1::zadanie1()
{
	int aktualnaOpcja;
	int poprzedniaOpcja = 0;
	while (true)
	{
		wait();
		if (reset.read() == 1)
			poprzedniaOpcja = 0;
		else
		{
			aktualnaOpcja = program.read();
			if (poprzedniaOpcja == 0)
			{
				if (aktualnaOpcja == 1)
					cout << "40 obrotow pralki" << endl;
			}
			poprzedniaOpcja = aktualnaOpcja;
		}
	}
}

void procesor1::zadanie3()
{
	int aktualnaOpcja;
	int poprzedniaOpcja = 0;
	while (true)
	{
		wait();
		if (reset.read() == 1)
			poprzedniaOpcja = 0;
		else
		{
			aktualnaOpcja = program.read();
			if (poprzedniaOpcja == 0)
			{
				if (aktualnaOpcja == 3)
					cout << "60 obrotow pralki" << endl;
			}
			poprzedniaOpcja = aktualnaOpcja;
		}
	}
}

void procesor1::zadanie4()
{
	int aktualnaOpcja;
	int poprzedniaOpcja = 0;
	while (true)
	{
		wait();
		if (reset.read() == 1)
			poprzedniaOpcja = 0;
		else
		{
			aktualnaOpcja = program.read();
			if (poprzedniaOpcja == 0)
			{
				if (aktualnaOpcja == 4)
					cout << "65 obrotow pralki" << endl;
			}
			poprzedniaOpcja = aktualnaOpcja;
		}
	}
}
void procesor1::zadanie5()
{
	int aktualnaOpcja;
	int poprzedniaOpcja = 0;
	while (true)
	{
		wait();
		if (reset.read() == 1)
			poprzedniaOpcja = 0;
		else
		{
			aktualnaOpcja = program.read();
			if (poprzedniaOpcja == 0)
			{
				if (aktualnaOpcja == 5)
					cout << "70 obrotow pralki" << endl;
			}
			poprzedniaOpcja = aktualnaOpcja;
		}
	}
}

void procesor1::zadanie6()
{
	int aktualnaOpcja;
	int poprzedniaOpcja = 0;
	while (true) {
		wait();
		if (reset.read() == 1)
			poprzedniaOpcja = 0;
		else
		{
			aktualnaOpcja = program.read();
			if (poprzedniaOpcja == 0)
			{
				if (aktualnaOpcja == 6)
					cout << "90 obrotow pralki" << endl;


			}
			poprzedniaOpcja = aktualnaOpcja;
		}
	}
}
