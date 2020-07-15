/*
 * control.c
 *
 *  Created on: 2020/07/15
 *      Author: tamod
 */


#include "control.h"

static float PosCmd,PosRes,PosErr,PosErrInt;
static float VelCmd,VelRes,VelErr;
static float PosICmd,PosIRes;
