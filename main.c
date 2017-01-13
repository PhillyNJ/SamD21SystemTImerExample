/* works - Stop watch timer
1. Requires the following modules:
	TC - Timer Counter
	Delay Routines

2. Add libsam0_lib_hw_timer.a to ARM/GNU Linker Libraries and Library Search Path
3. Copy conf_hw_timer.h
4. Copy common_hw_timer.h
5. Copy hw_timer.h && hw_timer.c
6. Copy sysTimer.h && sysTimer.c

works on SAMD21 && SAMR21

Note: not tested on SAM4S

*/
#include <asf.h>
#include "sysTimer.h"
static SYS_Timer_t myTimer;
void appTimerTestHandler(SYS_Timer_t *timer);
void initMyTimer(void);
void startMyTimer(void);
void stopMyTimer(void);
volatile int seconds = 0;
int main (void)
{
	system_init();
	SYS_TimerInit();
	initMyTimer();	
	startMyTimer();
	/* Insert application code here, after the board has been initialized. */

	/* This skeleton code simply sets the LED to the state of the button. */
	while (1) {
		
		SYS_TimerTaskHandler();
		
		/* Is button pressed? */
		//if (seconds % 2 == 0) {
			///* Yes, so turn LED on. */
			//port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
		//} else {
			///* No, so turn LED off. */
			//port_pin_set_output_level(LED_0_PIN, !LED_0_ACTIVE);
		//}
	}
}


void appTimerTestHandler(SYS_Timer_t *timer)
{
	
	port_pin_toggle_output_level(LED_0_PIN);	

	(void)timer;
}
void initMyTimer(void)
{

	myTimer.interval = 1000; // milli seconds
	myTimer.mode = SYS_TIMER_PERIODIC_MODE;
	myTimer.handler = appTimerTestHandler;
	
}
void startMyTimer(void){
	
	SYS_TimerStart(&myTimer);
}

void stopMyTimer(void){
	
	SYS_TimerStop(&myTimer);

}