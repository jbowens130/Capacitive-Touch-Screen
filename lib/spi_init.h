#include <avr/io.h>
#include <inttypes.h>
#include "IO_Macros.h"


#ifndef _SPI_INIT_H_INCLUDE
#define _SPI_INIT_H_INCLUDE
#endif

#define CD      B,1 // Arduino 9
#define CS      B,2 // Arduino 10
#define MOSI    B,3 // Arduino 11
#define MISO    B,4 // Arduino 12
#define SCK     B,5 // Arduino 13

//Prototypes
void SPI_init();
void SPI_write(uint8_t data);
void HX8375D_send_command(uint8_t cmd);
void HX8375D_send_data(uint8_t data);
void HX8375D_init();
void setAddressWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h);

