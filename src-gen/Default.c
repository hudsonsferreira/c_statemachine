
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Default.h"
/*! \file Implementation of the state machine 'default'
*/

// prototypes of all internal functions

static void default_entryaction(Default* handle);
static void default_exitaction(Default* handle);
static void default_react_main_region_State1(Default* handle);
static void default_react_main_region_State2(Default* handle);
static void clearInEvents(Default* handle);
static void clearOutEvents(Default* handle);


void default_init(Default* handle)
{
	int i;

	for (i = 0; i < DEFAULT_MAX_ORTHOGONAL_STATES; ++i)
		handle->stateConfVector[i] = Default_last_state;
	
	
	handle->stateConfVectorPosition = 0;

clearInEvents(handle);
clearOutEvents(handle);

	// TODO: initialize all events ...

	{
		/* Default init sequence for statechart default */
		handle->iface.message = "";
	}

}

void default_enter(Default* handle)
{
	{
		/* Default enter sequence for statechart default */
		default_entryaction(handle);
		{
			/* 'default' enter sequence for region main region */
			{
				/* Default react sequence for initial entry  */
				{
					/* 'default' enter sequence for state State1 */
					{
						/* Entry action for state 'State1'. */
						handle->iface.message = "Initial Message";
					}
					handle->stateConfVector[0] = default_main_region_State1;
					handle->stateConfVectorPosition = 0;
				}
			}
		}
	}
}

void default_exit(Default* handle)
{
	{
		/* Default exit sequence for statechart default */
		{
			/* Default exit sequence for region main region */
			/* Handle exit of all possible states (of main region) at position 0... */
			switch(handle->stateConfVector[ 0 ]) {
				case default_main_region_State1 : {
					{
						/* Default exit sequence for state State1 */
						handle->stateConfVector[0] = Default_last_state;
						handle->stateConfVectorPosition = 0;
					}
					break;
				}
				case default_main_region_State2 : {
					{
						/* Default exit sequence for state State2 */
						handle->stateConfVector[0] = Default_last_state;
						handle->stateConfVectorPosition = 0;
					}
					break;
				}
				default: break;
			}
		}
		default_exitaction(handle);
	}
}

static void clearInEvents(Default* handle) {
	handle->iface.go_raised = bool_false;
	handle->iface.come_back_raised = bool_false;
}

static void clearOutEvents(Default* handle) {
}

void default_runCycle(Default* handle) {
	
	clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < DEFAULT_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++) {
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition]) {
		case default_main_region_State1 : {
			default_react_main_region_State1(handle);
			break;
		}
		case default_main_region_State2 : {
			default_react_main_region_State2(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}


sc_boolean default_isActive(Default* handle, DefaultStates state) {
	switch (state) {
		case default_main_region_State1 : 
			return (sc_boolean) (handle->stateConfVector[0] == default_main_region_State1
			);
		case default_main_region_State2 : 
			return (sc_boolean) (handle->stateConfVector[0] == default_main_region_State2
			);
		default: return bool_false;
	}
}

void defaultIface_raise_go(Default* handle) {
	handle->iface.go_raised = bool_true;
}
void defaultIface_raise_come_back(Default* handle) {
	handle->iface.come_back_raised = bool_true;
}


sc_string defaultIface_get_message(Default* handle) {
	return handle->iface.message;
}
void defaultIface_set_message(Default* handle, sc_string value) {
	handle->iface.message = value;
}
		
// implementations of all internal functions

/* Entry action for statechart 'default'. */
static void default_entryaction(Default* handle) {
	{
		/* Entry action for statechart 'default'. */
	}
}

/* Exit action for state 'default'. */
static void default_exitaction(Default* handle) {
	{
		/* Exit action for state 'default'. */
	}
}

/* The reactions of state State1. */
static void default_react_main_region_State1(Default* handle) {
	{
		/* The reactions of state State1. */
		if (handle->iface.go_raised) { 
			{
				/* Default exit sequence for state State1 */
				handle->stateConfVector[0] = Default_last_state;
				handle->stateConfVectorPosition = 0;
			}
			{
				/* 'default' enter sequence for state State2 */
				{
					/* Entry action for state 'State2'. */
					handle->iface.message = "Good Bye";
				}
				handle->stateConfVector[0] = default_main_region_State2;
				handle->stateConfVectorPosition = 0;
			}
		} 
	}
}

/* The reactions of state State2. */
static void default_react_main_region_State2(Default* handle) {
	{
		/* The reactions of state State2. */
		if (handle->iface.come_back_raised) { 
			{
				/* Default exit sequence for state State2 */
				handle->stateConfVector[0] = Default_last_state;
				handle->stateConfVectorPosition = 0;
			}
			{
				/* 'default' enter sequence for state State1 */
				{
					/* Entry action for state 'State1'. */
					handle->iface.message = "Initial Message";
				}
				handle->stateConfVector[0] = default_main_region_State1;
				handle->stateConfVectorPosition = 0;
			}
		} 
	}
}


