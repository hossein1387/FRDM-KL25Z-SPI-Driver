//--------------------------------------------------------------------------------
// Name: Spi.h
//--------------------------------------------------------------------------------
// Company: Concordia University
// Author : MohammadHossein Askari-Hemmat
// 
// Create Date:    1/20/2014 
// Design Name: 	 SPI low level driver
// Target Devices: KL25Z128VLK4
// Platform: FRDM-KL25Z (Freescale Freedom Development Platform for Kinetis)
// Compiler Versions: Keil 5.1
// Version: 1.0
//----------------------------------------------------------------------------
#include "common.h"
#include "MemMapPtr_KL25Z4.h"
#include <MKL25Z4.H>


#ifndef __SPI_H__
#define __SPI_H__ 

#define EN_CSN (FPTC->PSOR= 1UL << 9)
#define DS_CSN (FPTC->PCOR= 1UL << 9)

#define EN_CE (FPTC->PSOR= 1UL << 8)
#define DS_CE (FPTC->PCOR= 1UL << 8)

void en_SPI(void);
	
void spi_init(SPI_MemMapPtr SPI_MemPtr);

uint8 spi_send(SPI_MemMapPtr SPI_MemPtr,uint8 data);

#endif // SPI
