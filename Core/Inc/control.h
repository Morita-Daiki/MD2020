/*
 * control.h
 *
 *  Created on: 2020/07/15
 *      Author: tamod
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_

/**************** System parameters ***************/
#define dt_minor    0.000050f       ///< Sampling time of minor loop [sec]
#define dt_major    0.000200f       ///< Sampling time of major loop [sec]
#define DIVERGENCE_THRESHOLD_MS 300 ///< Threshold time to detect divergence [msec]
/**************************************************/

/********** Hardware-specific parameters **********/
#define Ktn         0.001159f       ///< Nominal torque constant of motor (Mabuchi FA-130RA-2270) [Nm/A]
#define Mn          0.0000005f      ///< Nominal Inertia [Nm/s^2*rad]
#define Rn          0.6818f         ///< Nominal resistance (Mabuchi FA-130RA-2270) [Ohm]
#define Ln          0.000340f       ///< Nominal inductance (Mabuchi FA-130RA-2270) [H]
/**************************************************/

/************ Default constol parameters *************/
// Position control gains
#define Kp_p_DEFAULT    2.0f     ///< Proportional gain of position control [s^2]
#define Ki_p_DEFAULT    1.0f     ///< Integral     gain of position control [s^3]
#define Kd_p_DEFAULT    0.0f      ///< Differential gain of position control [s]

void get_time();
void get_pos();
void get_vel();

void control();
float get_vel_cmd();
#endif /* INC_CONTROL_H_ */
