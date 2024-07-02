#ifndef stateMachine_included
#define stateMachine_included

// supported states
enum State{
  START = 0,
  STATE1 = 1,
  STATE2 = 2,
  STATE3 = 3,
  STATE4 = 4
};


// external variables
extern enum State current_state;
extern int sec_count;
extern int sec_flag;

void start_state();
void state_1();
void state_2();
void state_3();
void state_4();
void update_250th();
void sec();

#endif // included
