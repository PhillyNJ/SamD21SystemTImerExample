#include <asf.h>
#include "sysTimer.h"
static SYS_Timer_t myTimer;
void appTimerTestHandler(SYS_Timer_t *timer);
void initMyTimer(void);
void startMyTimer(void);
void stopMyTimer(void);

int main (void)
{
	system_init();
	SYS_TimerInit();
	initMyTimer();
	startMyTimer();
	
	while (1) {
		
		SYS_TimerTaskHandler();		
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
