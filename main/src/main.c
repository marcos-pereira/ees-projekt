#include "../h/main.h"

/* nxtOSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void) {
}

void ecrobot_device_initialize(void) {
}

void ecrobot_device_terminate(void) {
}

void hello_world() {
	ecrobot_status_monitor("Hello, World!");

}

TASK(OSEK_Main_Task) {
	while (1) {
		hello_world();
		/* 500msec wait */
		systick_wait_ms(500);
	}
}

// Defines values for black, white and gray according to 1st sensor readings
void calibrate_light_sensor() {
  
}

// Go straight
void go_straight() {
  
} 

// Turn a certain amount of degrees
void turn(int degree) {
  
}

// Follow the black line to complete the path
void follow_path() {
  
}
