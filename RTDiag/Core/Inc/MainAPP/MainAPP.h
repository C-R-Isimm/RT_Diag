#ifndef INC_MAINAPP_MAINAPP_H_
#define INC_MAINAPP_MAINAPP_H_


//Different state of RT_Diag
// Define states
//exmple of state
typedef enum {
    STATE_INITIAL,
    STATE_STATE1,
    STATE_STATE2,
    STATE_FINAL
} State;

// Define events
//exmple of events

typedef enum {
    EVENT_START,
    EVENT_TRIGGER1,
    EVENT_TRIGGER2,
    EVENT_END
} Event;

// Function to handle state transitions
State handleEvent(State currentState, Event event);






#endif /* INC_MAINAPP_MAINAPP_H_ */
