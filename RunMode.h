#if !defined(INCLUDED_RUNMODE_H_)
#define INCLUDED_RUNMODE_H_

#include "kernel.h"

typedef enum RunModeName{
	MAIMAI, LINE_TRACE,
} RunModeName;

// ‘®«‚ğ•Û‚·‚é‚½‚ß‚Ì\‘¢‘Ì‚Ì’è‹`
typedef struct RunMode
{
	BOOL run_mode;
} RunMode;

// ŒöŠJ‘€ì
void RunMode_init(RunMode* this);
void RunMode_change(RunMode* this, int runModeName);

#endif /*!defined(INCLUDED_RUNMODE_H_)*/
