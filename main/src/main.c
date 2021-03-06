#include "../h/main.h"

//DEFINES TO CONTROL THE MOTORS 
#define LEFTTURNFACTOR 1.79
#define RIGHTTURNFACTOR 1.85
#define POWERLEFT 80
#define POWERRIGHT 81
#define TURNINGSPEED 60

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
// TODO(Marcos): test function, look up the start position of the robot, define the ports for each sensor, 
// take the average for both sensors, display average on LCD
void calibrate_light_sensor() {
  //int average, white_average,white1,white2,white3, black_line, gray_line;
  
	//black_line=ecrobot_get_light_sensor(NXT_PORT_S1);
	
  //// TODO(Marcos): decide how to debug/test and display values of calibration
  ////putNumberOnLCD(line);
  
	//systick_wait_ms(100);

	//turn_left(30);
			//white=ecrobot_get_light_sensor(NXT_PORT_S1);
	//turn_left(10);
			//white1=ecrobot_get_light_sensor(NXT_PORT_S1);
	//turn_left(10);
			//white2=ecrobot_get_light_sensor(NXT_PORT_S1);
	//turn_left(10);
			//white3=ecrobot_get_light_sensor(NXT_PORT_S1);

	//white_average=white+white1+white2+white3;
	//white=white/4;
	//putNumberOnLCD(white);
	//systick_wait_ms(100);
	//=white+line;
	//light=all/2;
	//turn_right_till_line(360);  
}

// Go straight
void go_straight() {
	nxt_motor_set_speed(NXT_PORT_A, 100, 0);
	nxt_motor_set_speed(NXT_PORT_C, 100, 0);
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


