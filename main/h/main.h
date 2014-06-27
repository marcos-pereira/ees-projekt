#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include "kernel.h"
/* Will be generated: */
#include "kernel_id.h"
#include "ecrobot_interface.h"

/* add user headers here: */

void hello_world();
void calibrate_light_sensor(); 
void follow_path();  
void turn(int degree);
void go_straight();

#endif /* MAIN_H_ */
