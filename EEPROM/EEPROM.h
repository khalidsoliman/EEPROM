/*
 * EEPROM.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Khalid
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(unsigned int Address, unsigned char Data);
void EEPROM_write_Block(unsigned int Address , char* Data , unsigned char size );
unsigned char EEPROM_read(unsigned int Address);
void EEPROM_read_Block(unsigned int Address,char* Data,unsigned char size );
#endif /* EEPROM_H_ */
