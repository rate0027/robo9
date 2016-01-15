#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "Barcode.h"

void Barcode_init(Baecode* this)
{
	this->target = 0;
}

void Barcode_run(Barcode* this, unsigned int Target)
{	
	this->target = Target;
}



