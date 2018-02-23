# EEPROM

Atmega 32 EEPROM Write and Read (One Byte by One Or Block Of Bytes)

## EEPROM.c contains APIs 

### EEPROM_write 
### EEPROM_read
### EEPROM_write_Block
### EEPROM_read_Block

## EEPROM.h contains Prototypes

### void EEPROM_write(unsigned int Address, unsigned char Data);
### void EEPROM_write_Block(unsigned int Address , char* Data , unsigned char size );
### unsigned char EEPROM_read(unsigned int Address);
### void EEPROM_read_Block(unsigned int Address,char* Data,unsigned char size );
