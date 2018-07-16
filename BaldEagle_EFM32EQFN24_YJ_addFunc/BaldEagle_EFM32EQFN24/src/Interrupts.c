

#include <SI_EFM8LB1_Register_Enums.h>
#include "EFM8LB1_SMBus_MasterMultibyte.h"
#include "EFM8LB1_I2C_Slave.h"
typedef enum {
	SLAVE_NORMAL_DATA, SLAVE_DATA_ADDRESS,
} SLAVE_WRITE_DATA_TYPE;

extern volatile uint8_t nWR;
extern uint32_t ADC_AVG;
extern bool CONV_COMPLETE;
uint8_t iArry = 0;
bool bTx_4th_byte_nack = false;


volatile uint8_t I2C1_slaveWriteData = 0x16;


uint8_t xdata EEPROM_Buffer[] =
#if 0	
		{
				17,		//B0
				5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0,

				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0,		//B127

				17, 0, 35,
				128,		//136
				0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 8, 70, 73, 84,
				32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 9, 58, 49, 48,
				48, 50, 57, 55, 49, 49, 48, 49, 32, 32, 32, 32, 32, 32, 49, 32,
				66, 104, 7, 208, 0, 99,
				2,		//CR4=11 SR4=2 AOC=1?����24
				0, 0, 0, 53, 50, 56, 54, 50, 48, 55, 53, 48, 32, 32, 32, 32, 32,
				32, 32, 49, 53, 49, 48, 49, 51, 32, 32, 0, 0, 0, 41,

				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

		};
#else
{
17,  
7,
0,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
16,
227,
0,
0,
132,
157,
0,
0,
0,
0,
0,
0,
0,
0, //RX1 power LSB
0,
0, //RX2 power LSB
0,
0, //RX3 power LSB
0,
0, //RX4 power LSB
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
255, //CDR Control
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
2,
8,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,  //page0
17,  
204,
33,
128,
0,
0,
0,
0,
0,
0,
0,
5,
255,
0,
0,
0,
0,
0,
3,
240, //wavelength ?850nm
79,
69,
77,
32,
67,
79,
82,
80,
32,
32,
32,
32,
32,
32,
32,
32,
31,
0,
144,
101,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
49,
54,
0,  //wavelength or Copper cable attenuation
0,
0,  //wavelength tolerance
0,
0,
54,
25,
7,
255,
220,
67,
114,
101,
100,
111,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
49,
56,
48,
49,
48,
52,
32,
32,
8,
0,
103,
36,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,   //page1
0,  
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0, //page2
0,  
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0, //page3
75,  
0,
251,
0,
70,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
141,
204,
116,
4,
135,
90,
121,
24,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
85,
118,
1,
142,
67,
226,
3,
26,
23,
112,
5,
220,
21,
124,
7,
208,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
151,
15,
0,
0,
0,
0,
0,
0,
0,
0,
102,
102,
119,
119,
51,
51,
15,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0
    };

#endif


SI_INTERRUPT (I2C0_ISR, I2C0_IRQn)
{
	static uint16_t eepromAddress = 0;
	static uint8_t slaveWriteType = SLAVE_NORMAL_DATA;
	static uint8_t WriteStat = 0;
	uint8_t t,j;

	uint8_t SAVE_SFRPAGE;
	bool EA_SAVE = IE_EA;
//	bool bBridge;
//	IE_EA = 0;
	SAVE_SFRPAGE = SFRPAGE;
	SFRPAGE = 0x20;

	switch (I2C0STAT & I2C_STATUS_VECTOR_MASK) {

		case I2C_ADDR_RD:
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_RD__BMASK);
		t = EEPROM_Buffer[eepromAddress++];
		if(0x0==t)
		{
			j=t;
		}
		I2C0DOUT = t;//EEPROM_Buffer[eepromAddress++];
		if(sizeof(EEPROM_Buffer) <= eepromAddress)
		{
			eepromAddress = 0;
		}
		WriteStat = 0;
		break;

		case I2C_ADDR_WR:
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_WR__BMASK);
		slaveWriteType = SLAVE_DATA_ADDRESS;
		WriteStat = 1;
		break;

		case I2C_RD_DATA:
		if ((I2C0STAT & I2C0STAT_NACK__BMASK) == I2C0STAT_NACK__SET) {
			I2C0STAT &= ~I2C0STAT_NACK__BMASK;
		} else {
			t = EEPROM_Buffer[eepromAddress++];
			if(0x11==t)
			{
				j=t;
			}
			I2C0DOUT = t;

			if(sizeof(EEPROM_Buffer) <= eepromAddress)
			{
				eepromAddress = 0;
			}
		}
		I2C0STAT &= ~I2C0STAT_RD__BMASK;
		break;

		case I2C_WR_DATA:
		I2C0STAT &= ~I2C0STAT_WR__BMASK;

		break;

		case I2C_STOSTA:
		case I2C_STOSTARD:
		I2C0STAT &= ~I2C0STAT_STOP__BMASK;
#if 0
		I2C0CN0 &= ~I2C0CN0_BUSY__BMASK;		// Clear BUSY bit
		I2C0CN0 |= I2C0FCN0_RFLSH__FLUSH | I2C0FCN0_TFLSH__FLUSH;
#endif

//		WriteStat = 0;//added 20180122
		return;
		break;

		case I2C_STO:
		I2C0STAT &= ~I2C0STAT_STOP__BMASK;
#if 0
		I2C0CN0 &= ~I2C0CN0_BUSY__BMASK;		// Clear BUSY bit
		I2C0CN0 |= I2C0FCN0_RFLSH__FLUSH | I2C0FCN0_TFLSH__FLUSH;
#endif

//		WriteStat = 0;//added 20180122
		break;
		default:
		break;
	}

	while((I2C0FCN1 & I2C0FCN1_RXE__BMASK) == I2C0FCN1_RXE__NOT_EMPTY) {
		I2C1_slaveWriteData = I2C0DIN;
		if(1==WriteStat&&80!=I2C1_slaveWriteData)
		{
			switch(slaveWriteType)
			{
				case SLAVE_DATA_ADDRESS:
				if(I2C1_slaveWriteData>=128)
				{
					eepromAddress = I2C1_slaveWriteData+128*EEPROM_Buffer[127];
				}
				else
				{
					eepromAddress = I2C1_slaveWriteData;
				}
				break;

				case SLAVE_NORMAL_DATA:
				default:
				EEPROM_Buffer[eepromAddress++] = I2C1_slaveWriteData;

				if(sizeof(EEPROM_Buffer) <= eepromAddress)
				{
					eepromAddress = 0;
				}
				//yj20180226 for bridge start
				if(78==(eepromAddress-1)&&(I2C1_slaveWriteData<3))
				{
					if(2==I2C1_slaveWriteData){
						SMB0_I2C_MasterWrite( (EEPROM_Buffer[74]<<8)|EEPROM_Buffer[75], (EEPROM_Buffer[76]<<8)| EEPROM_Buffer[77] );
						EEPROM_Buffer[78] = 0;	  //complete
					}
					else{
						
						uint16_t rValue;
						rValue = SMB0_I2C_MasterRead( (EEPROM_Buffer[74]<<8)|EEPROM_Buffer[75] );
						EEPROM_Buffer[76] = rValue >> 8;
						EEPROM_Buffer[77] = rValue & 0x00ff;
						EEPROM_Buffer[78] = 0;	  //complete
					}
				}
				//yj20180226 for bridge end
				break;
			}

			slaveWriteType = SLAVE_NORMAL_DATA;
//			WriteStat = 0;//added 20180122
		}
	}

	I2C0STAT &= ~I2C0STAT_I2C0INT__BMASK;
	SFRPAGE = SAVE_SFRPAGE;
//	IE_EA = EA_SAVE;

}


SI_INTERRUPT (SMBUS0_ISR, SMBUS0_IRQn)
{
	bool FAIL = 0;
	static uint8_t sent_byte_counter;
	static uint8_t rec_byte_counter;

	if (SMB0CN0_ARBLOST == 0)
	{

		switch (SMB0CN0 & 0xF0)
		{

			case SMB_MTSTA:
			SMB0DAT = TARGET<<1;
			SMB0DAT &= 0xFE;
			SMB0DAT |= (uint8_t) SMB_RW;
			SMB0CN0_STA = 0;
			rec_byte_counter = 1;
			sent_byte_counter = 1;
			break;


			case SMB_MTDB:
			if (SMB0CN0_ACK)
			{
				if (SMB_RW == WRITE)
				{
					if (sent_byte_counter <= nWR /*NUM_BYTES_WR*/)
					{

						SMB0DAT = SMB_DATA_OUT[sent_byte_counter-1];
						sent_byte_counter++;
					}
					else
					{
						SMB0CN0_STO = 1;
						SMB_BUSY = 0;
					}
				}
				else {}
			}
			else
			{
				if(bTx_4th_byte_nack)
				{
					SMB0CN0_STO = 1;
					SMB_BUSY = 0;
					break;
				}
				SMB0CN0_STO = 1;
				SMB0CN0_STA = 1;
				NUM_ERRORS++;
			}
			break;


			case SMB_MRDB:
			if (rec_byte_counter < NUM_BYTES_RD)
			{
				SMB_DATA_IN[rec_byte_counter-1] = SMB0DAT;

				SMB0CN0_ACK = 1;
				rec_byte_counter++;
			}
			else
			{
				SMB_DATA_IN[rec_byte_counter-1] = SMB0DAT;

				SMB_BUSY = 0;
				SMB0CN0_ACK = 0;

				SMB0CN0_STO = 1;
			}
			break;

			default:
			FAIL = 1;
			break;

		}
	}
	else
	{

		FAIL = 1;
	}

	if (FAIL)
	{
		SMB0CF &= ~0x80;
		SMB0CF |= 0x80;
		SMB0CN0_STA = 0;
		SMB0CN0_STO = 0;
		SMB0CN0_ACK = 0;

		SMB_BUSY = 0;

		FAIL = 0;


		NUM_ERRORS++;
	}

	SMB0CN0_SI = 0;
}

SI_INTERRUPT (TIMER3_ISR, TIMER3_IRQn)
{
	SMB0CF &= ~0x80;
	SMB0CF |= 0x80;
	TMR3CN0 &= ~0x80;

	SMB0CN0_STA = 0;
	SMB_BUSY = 0;
}

SI_INTERRUPT (TIMER4_ISR, TIMER4_IRQn)
{
	SFRPAGE = PG3_PAGE;

	I2C0CN0 &= ~I2C0CN0_I2C0EN__BMASK;
	I2C0CN0 |= I2C0CN0_I2C0EN__ENABLED;

	SFRPAGE = PG2_PAGE;
	TMR4CN0 &= ~TMR4CN0_TF4H__BMASK;

}

SI_INTERRUPT (ADC0EOC_ISR, ADC0EOC_IRQn)
{
	   ADC0CN0_ADINT = 0;
	   ADC_AVG = ADC0/4;
	   CONV_COMPLETE = 1;

}

