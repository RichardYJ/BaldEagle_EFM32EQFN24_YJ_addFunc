

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8LB1_Register_Enums.h>
#include "EFM8LB1_Flash.h"

void FLASH_ByteWrite (FLADDR addr, uint8_t byte)
{
   bool EA_SAVE = IE_EA;                
   uint8_t SAVE_SFRPAGE;
   SI_VARIABLE_SEGMENT_POINTER(pwrite, uint8_t, SI_SEG_XDATA); 

   SAVE_SFRPAGE = SFRPAGE;
   SFRPAGE = 0;
   IE_EA = 0;                         

   VDM0CN = 0x80;                     

   RSTSRC = 0x02;                     

   pwrite = (SI_VARIABLE_SEGMENT_POINTER(, uint8_t, SI_SEG_XDATA)) addr;

   FLKEY  = 0xA5;                     
   FLKEY  = 0xF1;                     
   PSCTL |= 0x01;                     

   VDM0CN = 0x80;                     

   RSTSRC = 0x02;                     
   *pwrite = byte;                    

   PSCTL &= ~0x01;                    

   SFRPAGE = SAVE_SFRPAGE;
   IE_EA = EA_SAVE;                   
}

uint8_t FLASH_ByteRead (FLADDR addr)
{
	uint8_t SAVE_SFRPAGE;

   bool EA_SAVE = IE_EA;                
   SI_VARIABLE_SEGMENT_POINTER(pread, uint8_t, const SI_SEG_CODE); 
   uint8_t byte;
   SAVE_SFRPAGE = SFRPAGE;
   SFRPAGE = 0;

   IE_EA = 0;                          

   pread = (SI_VARIABLE_SEGMENT_POINTER(, uint8_t, const SI_SEG_CODE)) addr;

   byte = *pread;                      

   SFRPAGE = SAVE_SFRPAGE;
   IE_EA = EA_SAVE;                    

   return byte;
}

void FLASH_PageErase (FLADDR addr)
{
   bool EA_SAVE = IE_EA;                
   uint8_t SAVE_SFRPAGE;
   SI_VARIABLE_SEGMENT_POINTER(pwrite, uint8_t, SI_SEG_XDATA);

   SAVE_SFRPAGE = SFRPAGE;
   SFRPAGE = 0;
   IE_EA = 0;                          

   VDM0CN = 0x80;                      

   RSTSRC = 0x02;                      

   pwrite = (SI_VARIABLE_SEGMENT_POINTER(, uint8_t, SI_SEG_XDATA)) addr;

   FLKEY  = 0xA5;                      
   FLKEY  = 0xF1;                      
   PSCTL |= 0x03;                      

   VDM0CN = 0x80;                      

   RSTSRC = 0x02;                      
   *pwrite = 0;                        

   PSCTL &= ~0x03;                     

   SFRPAGE = SAVE_SFRPAGE;
   IE_EA = EA_SAVE;                    
}
