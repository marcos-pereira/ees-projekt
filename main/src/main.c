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
		go_straight();
		systick_wait_ms(500);
		stop(1000);
	}
}

void stop(int time){
	nxt_motor_set_speed(NXT_PORT_A,0,1);
	nxt_motor_set_speed(NXT_PORT_C,0,1);
	systick_wait_ms(time);
}

void go(int speed){
	nxt_motor_set_speed(NXT_PORT_A,speed,0);
	nxt_motor_set_speed(NXT_PORT_C,speed,0);
}

// Defines values for black, white and gray according to 1st sensor readings
void calibrate_light_sensor() {
  
}

// Go straight
void go_straight() {
	nxt_motor_set_speed(NXT_PORT_A, 100, 0);
	nxt_motor_set_speed(NXT_PORT_C, 100, 0);
} 

// Turn a certain amount of degrees
void turn(int degree) {
  
}

// Follow the black line to complete the path
void follow_path() {
  
}

void turn_right(float rot){
	nxt_motor_set_count(NXT_PORT_A,0);
	nxt_motor_set_count(NXT_PORT_C,0);
	while(nxt_motor_get_count(NXT_PORT_C)<=(int)(rot*RIGHTTURNFACTOR)){
		nxt_motor_set_speed(NXT_PORT_A,-TURNINGSPEED,0);
		nxt_motor_set_speed(NXT_PORT_C,TURNINGSPEED,0);
	}
	stop(1);
}

void turn_left(float rot){
	nxt_motor_set_count(NXT_PORT_A,0);
	nxt_motor_set_count(NXT_PORT_C,0);
	while(nxt_motor_get_count(NXT_PORT_A)<=(int)(rot*LEFTTURNFACTOR)){
		nxt_motor_set_speed(NXT_PORT_A,TURNINGSPEED,0);
		nxt_motor_set_speed(NXT_PORT_C,-TURNINGSPEED,0);
	}
	stop(1);
}


