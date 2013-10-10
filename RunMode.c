#include "RunMode.h"

void RunMode_init(RunMode* this){
	this->run_mode = TRUE;
}

void RunMode_change(RunMode* this, int runModeName)
{
	if(runModeName == MAIMAI) this->run_mode = TRUE;
	else                      this->run_mode = FALSE;
}
