
#ifndef DEFAULT_H_
#define DEFAULT_H_

#include "sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'default'.
*/

//! enumeration of all states 
typedef enum {
	default_main_region_State1 ,
	default_main_region_State2 ,
	Default_last_state
} DefaultStates;

//! Type definition of the data structure for the DefaultIface interface scope.
typedef struct {
	sc_string message;
	sc_boolean go_raised;
	sc_boolean come_back_raised;
} DefaultIface;


//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
#define DEFAULT_MAX_ORTHOGONAL_STATES 1

/*! Type definition of the data structure for the Default state machine.
This data structure has to be allocated by the client code. */
typedef struct {
	DefaultStates stateConfVector[DEFAULT_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	DefaultIface iface;
} Default;

/*! Initializes the Default state machine data structures. Must be called before first usage.*/
extern void default_init(Default* handle);

/*! Activates the state machine */
extern void default_enter(Default* handle);

/*! Deactivates the state machine */
extern void default_exit(Default* handle);

/*! Performs a 'run to completion' step. */
extern void default_runCycle(Default* handle);


/*! Gets the value of the variable 'message' that is defined in the default interface scope. */ 
extern sc_string defaultIface_get_message(Default* handle);
/*! Sets the value of the variable 'message' that is defined in the default interface scope. */ 
extern void defaultIface_set_message(Default* handle, sc_string value);
/*! Raises the in event 'go' that is defined in the default interface scope. */ 
extern void defaultIface_raise_go(Default* handle);

/*! Raises the in event 'come_back' that is defined in the default interface scope. */ 
extern void defaultIface_raise_come_back(Default* handle);



/*! Checks if the specified state is active. */
extern sc_boolean default_isActive(Default* handle, DefaultStates state);

#ifdef __cplusplus
}
#endif 

#endif /* DEFAULT_H_ */
