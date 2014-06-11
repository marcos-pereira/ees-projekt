/* helloworld.c for TOPPERS/ATK(OSEK) */ 
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

DeclareTask(Task1);

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

/* Task1 executed only once at initialization */
TASK(Task1)
{
	nxt_avr_set_input_power(NXT_PORT_S2,2);
	i2c_enable(NXT_PORT_S2);

	TerminateTask();
}

TASK(OSEK_Task_Background)
{
	while(1)
	{
    
    static U8 data;
    int light_port2;
    int light_port4;
    
    // Print Hello World! 
    //ecrobot_status_monitor("HelloWorld!!11!1");
    
    // Read Light Sensors
    light_port2 = (int)ecrobot_get_light_sensor(NXT_PORT_S2);	/* Read Light Sensor on port 2*/
    light_port4 = (int)ecrobot_get_light_sensor(NXT_PORT_S4);	/* Read Light Sensor on port 4*/
    
    // Read RFID Tag from sensor on port 3
    // TODO: implement functionable test for the RFID test
    //i2c_start_transaction(NXT_PORT_S3,1,0x42,1,&data,1,0);
    
    // Example of motor test on port A
    /* nxt_motor_set_speed(NXT_PORT_A, 20, 1); 				          /* Set motor A speed to 20 */
    
    // Print reading from light sensors
    display_goto_xy(0, 0);
    display_string(" ADC2: ");
    display_int(light_port2, 0);
    
    display_goto_xy(0, 1);
    display_string(" ADC4: ");
    display_int(light_port4, 0);
    
    // Print reading from RFID Tag
    // TODO: implement functionable test for the RFID test
    //display_goto_xy(0, 2);
    //display_string(" RFID: ");
    //display_int(data, 0);

    systick_wait_ms(500); /* 500msec wait */
    
	}
}
