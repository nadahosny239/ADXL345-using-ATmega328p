#define setbit(x,y)		x |=(1<<y)
#define clearbit(x,y)	x &=~(1<<y)
#define togglebit(x,y)  x ^= (1<<y)
#define getbit(x,y,z) ((x>>y)&1) == z
#define F_CPU 8000000UL

#define ADXL_SLA_ADD_W  0xA6
#define ADXL_SLA_ADD_R	0xA7

#define ADXL_Power_CTL 0x2D
#define ADXL_Power_CTL_Val 0b00001000
#define ADXL_BW_Rate 0x2C 
#define ADXL_BW_Rate_Val 0b00001110
#define ADXL_Time_FF 0x29
#define ADXL_Time_FF_Val 20
#define ADXL_Thresh_FF 0x28
#define ADXL_Thresh_FF_Val 9
#define ADXL_INT_Enable 0x2E
#define ADXL_INT_Enable_Val 0b00000100
#define ADXL_INT_Source 0x30
#define ADXL_DATA_FORMAT 0x31
#define ADXL_DATA_FORMAT_Val 0x00
#define ADXL_DATAX0 0x32
#define ADXL_DATAX1 0x33
#define ADXL_DATAY0 0x34
#define ADXL_DATAY1 0x35
#define ADXL_DATAZ0 0x36
#define ADXL_DATAZ1 0x37

#define BUZZER_PORTB	PORTB


