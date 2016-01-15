#if !defined(BARCODE_INCLUDED_)
#define BARCODE_INCLUDED_ 

#include "../StopConditions.h"
#include "../run/LineTracer.h"
#include "../run/NolineTracer.h"

typedef struct Barcode
{
	unsigned int target;
	StopConditions* stopConditions;
	LineTracer*     lineTracer;
	NolineTracer*   nolineTracer;
}Barcode;

void Barcode_init(Baecode* this);
void Barcode_run(Barcode* this, unsigned int Target);
#endif
