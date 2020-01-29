
#include "stdafx.h"
#include "interface.h"
#include "procesor1.h"
#include "Procesor2.h"
#include "fifo.h"

SC_MODULE(SYSTEM) {

	sc_clock clock_signal;
	sc_signal<bool> reset_signal;
	procesor1* Proc1;
	procesor2* Proc2;
	fifo* kolejka;
	SC_CTOR(SYSTEM) : clock_signal("clock_signal", 10, SC_NS)
	{
		kolejka = new fifo("fifo");

		Proc1 = new procesor1("procesor1");
		Proc1->clock(clock_signal);
		Proc1->reset(reset_signal);
		Proc1->out(*kolejka);
		Proc1->reset_out(reset_signal);



		Proc2 = new procesor2("procesor2");
		Proc2->clock(clock_signal);
		Proc2->reset(reset_signal);
		Proc2->in(*kolejka);

	}
	~SYSTEM()
	{
		delete Proc1;
		delete Proc2;
		delete kolejka;
	}
};

SYSTEM* top = NULL;

int sc_main(int argc, char** argv)
{
	top = new SYSTEM("top");
	sc_start();
	getchar();
	return 0;
}
