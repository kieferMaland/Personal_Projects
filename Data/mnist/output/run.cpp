#include<stdlib.h>
#include "objects.h"
#include<ctime>
#include "randomkit.h"

#include "code_objects/neurongroup_2_group_variable_set_conditional_codeobject.h"
#include "code_objects/neurongroup_2_stateupdater_codeobject.h"
#include "code_objects/neurongroup_2_stateupdater_codeobject_1.h"
#include "code_objects/statemonitor_codeobject.h"
#include "code_objects/statemonitor_codeobject_1.h"


void brian_start()
{
	_init_arrays();
	_load_arrays();
	// Initialize clocks (link timestep and dt to the respective arrays)
    brian::defaultclock.timestep = brian::_array_defaultclock_timestep;
    brian::defaultclock.dt = brian::_array_defaultclock_dt;
    brian::defaultclock.t = brian::_array_defaultclock_t;
    for (int i=0; i<1; i++)
	    rk_randomseed(brian::_mersenne_twister_states[i]);  // Note that this seed can be potentially replaced in main.cpp
}

void brian_end()
{
	_write_arrays();
	_dealloc_arrays();
}


