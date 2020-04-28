void ADXL_INIT()
{
	
	Transmit_I2C(ADXL_SLA_ADD_W,ADXL_Thresh_FF,ADXL_Thresh_FF_Val);
	_delay_ms(10);
	Transmit_I2C(ADXL_SLA_ADD_W,ADXL_Time_FF ,ADXL_Time_FF_Val);
	_delay_ms(10);
	Transmit_I2C(ADXL_SLA_ADD_W,ADXL_BW_Rate ,ADXL_BW_Rate_Val);
	_delay_ms(10);
	Transmit_I2C(ADXL_SLA_ADD_W,ADXL_INT_Enable ,ADXL_INT_Enable_Val);
	_delay_ms(10);
	Transmit_I2C(ADXL_SLA_ADD_W,ADXL_Power_CTL ,ADXL_Power_CTL_Val );
   _delay_ms(10);
    Transmit_I2C(ADXL_SLA_ADD_W,ADXL_DATA_FORMAT ,ADXL_DATA_FORMAT_Val);
   _delay_ms(10);
}
