#include <msp430.h>
#include "state_machine.h"
#include "led.h"
//#include "switches.h"
//#include "buzzer.h"


enum State current_state = START;
int update_sec = 0;
int sec_flag = 0;


// 250 interrupts/sec
void update_250th()
{
  update_sec++;
  if(update_sec == 25) {
    update_sec = 0;
    sec();
  }
}


// Toggles the sec_flag when sec_count is equal to 250
void sec()
{
  sec_flag = sec_flag == 0 ? 1 : 0;
}


// Start state: toggles red light every sec when the sec_flag is on
void start_state()
{
  if(sec_flag){
    toggle_red();
    sec_flag = 0;
  }
}

// Siren state: creates a siren type sound
void state_1()
{
  if(sec_flag){
    toggle_red();
    toggle_green();
    sec_flag = 0;      // reset sec_flag
  }
}

void state_2()
{
  if(sec_flag){
    toggle_green();
    sec_flag = 0;       // reset sec_flag
  }
}

void state_3()
{
  if(sec_flag){
    toggle_green();
   sec_flag = 0;
  }
  toggle_red();
}

void state_4()
{
  if(sec_flag){
    toggle_red();
    toggle_green();
    sec_flag = 0;       // rest sec_flag
  }
}
