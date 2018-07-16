
#ifndef SMBUS_MASTER_MULTIBYTE_H_
#define SMBUS_MASTER_MULTIBYTE_H_

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (SDA, SFR_P0, 6);              
SI_SBIT (SCL, SFR_P0, 7);              
//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------

#define  SYSCLK               72000000 

#define  SMB_FREQUENCY           10000 

#define  WRITE                    0x00 
#define  READ                     0x01 


#define  TARGET_ADDR               0x10 


#define  SMB_MTSTA                0xE0
#define  SMB_MTDB                 0xC0
#define  SMB_MRDB                 0x80


#define  NUM_BYTES_WR                4  
#define  NUM_BYTES_RD                2 
//-----------------------------------------------------------------------------
// Global VARIABLES
//-----------------------------------------------------------------------------



extern uint8_t SMB_DATA_IN[NUM_BYTES_RD];

extern uint8_t SMB_DATA_OUT[NUM_BYTES_WR];

extern const uint8_t TARGET;                

extern volatile bool SMB_BUSY;        
extern volatile bool SMB_RW;          
extern uint16_t NUM_ERRORS;           

extern bool SMB0_I2C_MasterWrite(uint16_t RegAddr, uint16_t RegValue);
extern uint16_t SMB0_I2C_MasterRead(uint16_t RegAddr);

#endif // SMBUS_MASTER_MULTIBYTE_H_
//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
