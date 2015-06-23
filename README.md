FRDM K25Z SPI driver:
----------------------------------

Initializes the SPI0 for:

|	- Configure PTA15,PTA16,PTA17 as the SPI module pins (Second alternative)
|	- Enables the SPI module by enabling clock gating to SPI and enables the SPI system 
|	- MSB first 
|	- Configure SPI as a MASTER
|	- Disables the SPI transmit interrupt (SPTIE) 
|	- Disables the SPI interrupt (SPIE)
|	- Configures the SS pin as a general I/O pin (Not controlled by SPI) 
|	- DMA request disabled
|	- SPI uses separate pins for data input and data output (Is not bidirectional) 
|	- SPI clocks stop when the MCU enters wait mode
|	- Configures the Baudrate for 1MHZ operation 
Use the Following equation to find the proper Baudrate. If you are using the MCG
driver, the Busclock is 16MHZ. 
To use this driver qlong with NRF24L01 module, make sure that the SPCK is not more
than 10MHZ. Refer to the NRF24L01 datasheet for more information.

-Calculating the BaudRate:
	BaudRateDivisor = (SPPR + 1) * 2^(SPR + 1)
	BaudRate = BusClock / BaudRateDivisor
	Desired baudrate = 1MHZ, BusClock= 16MHZ  ----> BaudRateDivisor= 16 
	SPPR=1
	SPR=2
	
	This driver will use PTA14 as the CSN(Chip Select Not). The automatic triggering
	is disabled, so the code developer should take care of handling this pin.
