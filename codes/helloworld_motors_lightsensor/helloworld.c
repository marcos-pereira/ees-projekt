/* helloworld.c for TOPPERS/ATK(OSEK) */ 
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

/* nxtOSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void){ /* do nothing */ }
void disp(int row, char *str, int val);

void disp(int row, char *str, int val)
{
#define DISPLAY_ON
#ifdef DISPLAY_ON 
	display_clear(0);
	display_goto_xy(0, row);
	display_string(str);
	display_int(val, 0);
	display_update();
#endif
}

TASK(OSEK_Task_Background)
{
	while(1)
	{
    int light;
    
    ecrobot_status_monitor("OSEK HelloWorld!");
    
    light = (int)ecrobot_get_light_sensor(NXT_PORT_S2);	/* Read Light Sensor                 */
    disp(0, " ADClight: ", light);							/* Display Light Sensor              */
		
    nxt_motor_set_speed(NXT_PORT_A, 20, 1); 				/* Set motor A speed to A            */
		
    systick_wait_ms(500); /* 500msec wait */
    
	}
}
