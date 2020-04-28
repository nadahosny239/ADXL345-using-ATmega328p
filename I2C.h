void I2C_Init()
{
	TWBR = 8;
	TWSR = 0;
	
}

void Transmit_I2C(int Slave_Add, int Reg_Add, int DATA)
{
	TWCR = (1<<TWINT)| (1<<TWSTA) | (1<<TWEN);
	while (getbit(TWCR, TWINT, 0)); //stuck till start happens
	if ((TWSR != 0x10) && (TWSR != 0x08))  //Start was not sent
		RGB(RED);
	
	TWDR = Slave_Add;
	TWCR= 1<<TWINT  | (1<<TWEN); 
	while(getbit(TWCR, TWINT, 0));
	if (TWSR != 0x18) //Slave address was not transmitted
		RGB(YELLOW); 
	
	TWDR= Reg_Add;
	TWCR= 1<<TWINT | (1<<TWEN);
	while(getbit(TWCR, TWINT, 0));
	if(TWSR != 0x28) //Register Address was not transmitted
		RGB(PURPLE);
		
	TWDR= DATA;
	TWCR= 1<<TWINT | (1<<TWEN);
	while(getbit(TWCR, TWINT, 0));
	if(TWSR != 0x28) //DATA was not transmitted 
	RGB(WHITE);
	
	TWCR = (1<<TWSTO) | (1<<TWINT);
	
}

char Receive_I2c(int Slave_Add_Write, int Slave_Add_Read, int Reg_Add)
{
	
	TWCR = (1<<TWINT)| (1<<TWSTA) | (1<<TWEN);
	while (getbit(TWCR, TWINT, 0)); //stuck till start happens
		if ((TWSR != 0x10) && (TWSR != 0x08))   //Start was not sent
	RGB(RED);
	
	TWDR = Slave_Add_Write;
	TWCR= 1<<TWINT | (1<<TWEN);
	while(getbit(TWCR, TWINT, 0));
	if (TWSR != 0x18) //Slave address was not transmitted
	RGB(YELLOW);
	
	TWDR= Reg_Add;
	TWCR= 1<<TWINT | (1<<TWEN);
	while(getbit(TWCR, TWINT, 0));
	if(TWSR != 0x28) //Register Address was not transmitted
	RGB(PURPLE);
	
	TWCR = (1<<TWINT)| (1<<TWSTA) | (1<<TWEN);
	while (getbit(TWCR, TWINT, 0)); //stuck till start happens
	if ((TWSR != 0x10) && (TWSR != 0x08))  //Repeated Start was not sent
	RGB(RED);
	
	
	TWDR = Slave_Add_Read;
	TWCR= 1<<TWINT | (1<<TWEN);
	while(getbit(TWCR, TWINT, 0));
	if (TWSR !=0x40)//Slave address was not received
	RGB(YELLOW);
	
	
	
	
	TWCR= 1<<TWINT | (1<<TWEN);
	while(getbit(TWCR, TWINT, 0));
	if(TWSR != 0x58)
	RGB(WHITE);
	char Data = TWDR;
	
	TWCR = (1<<TWSTO) | (1<<TWINT);
	return Data;
}
