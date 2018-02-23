/*
 * EEPROM.c
 *
 *  Created on: Feb 20, 2018
 *      Author: Khalid
 */
#include <avr/io.h>
#include "EEPROM.h"

#define set_bit(reg,pin) reg|=(1<<pin)
#define clear_bit(reg,pin) reg&=~(1<<pin)

void EEPROM_write(unsigned int Address, unsigned char Data)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = Address;
	EEDR = Data;
	/* Write logical one to EEMWE */
	set_bit(EECR,EEMWE);
	/* Start EEPROM write by setting EEWE */
	set_bit(EECR,EEWE);
}


unsigned char EEPROM_read(unsigned int Address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = Address;
	/* Start EEPROM read by writing EERE */
	set_bit(EECR,EERE);
	/* Return data from data register */
	return EEDR;
}

void EEPROM_write_Block(unsigned int Address , char* Data , unsigned char size )
{
	int i =0;

	for(i=0;i<size;i++)
	{
		EEPROM_write((Address+i),*(Data+i));
		if(*(Data+i)=='\0')
		{
			break;
		}
	}
}

void EEPROM_read_Block(unsigned int Address,char* Data,unsigned char size )
{
	int i =0;
	for(i=0;i<size;i++)
	{
		*(Data+i)= EEPROM_read((Address+i));
	}
}
