/*
 * BmuInterface.c
 *
 *  Created on: 2017��1��2��
 *      Author: chj704
 */

#include "BmuInterface.h"


void BmuRead(void)
{
	int i=0;
	for(i=0;i<96;i++)
	{
		BMS_U.VCell[i] = 3.5;
	}

	BMS_U.TCell = 20.0;
}


