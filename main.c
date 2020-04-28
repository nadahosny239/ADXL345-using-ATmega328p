#include <avr/io.h>
#include "definitions.h"
#include <util/delay.h>
#include "variables.h"
#include "ADXL_Free_Fall.h"
#include "I2C.h"

int main(void)
{
	
	I2C_Init();
	
	ADXL_INIT();

    while (1) 
    {
    
	
	
	
	if(Receive_I2c((ADXL_SLA_ADD_W,ADXL_SLA_ADD_R,ADXL_INT_Source)&4) == 0b00000100)
	{
		
	Buzzer();
	
	
	}
	
	
}

}