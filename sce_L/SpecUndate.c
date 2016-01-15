#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#include "SpecUndate.h"

void SpecUndate_init(SpecUndate* this)
{
	this->target = 0;
}

void SpecUndate_run(SpecUndate* this, unsigned int Target){
  this->target = Target;

} 
