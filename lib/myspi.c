//Sets up SPI communication from the Arduino to the display board

#include <util/delay.h>
#include <inttypes.h>
#include "spi_init.h"
#include "registers.h"
#include "IO_Macros.h"

#define CD      B,1 // Arduino 9
#define CS      B,2 // Arduino 10
#define MOSI    B,3 // Arduino 11
#define MISO    B,4 // Arduino 12
#define SCK     B,5 // Arduino 13

// Function to initialize SPI communication
void SPI_init() {
    // Set MOSI, SCK, and SS as outputs
    DDRB |= (1<<DDB3)|(1<<DDB5)|(1<<DDB2);
    
    // Enable SPI, Set as Master
    SPCR |= (1<<SPE)|(1<<MSTR);
    
    // Set clock rate fck/16
    SPCR |= (1<<SPR0);

    DigitalWrite(CS,High);
}

// Function to send data over SPI
void SPI_write(uint8_t data) {

    DigitalWrite(CS,Low);

    // Start transmission
    SPDR = data;
    
    // Wait for transmission complete
    while(!(SPSR & (1<<SPIF)));

    //Ensure CS is set high again
    DigitalWrite(CS,High);
}

// Function to send a command to the HX8375D TFT LCD
void HX8375D_send_command(uint8_t cmd) {
    // Set the Data/Command (D/C) pin low to indicate a command
    DigitalWrite(CD,Low); 
    
    // Send the command over SPI
    SPI_write(cmd);
}

// Function to send data to the HX8375D TFT LCD
void HX8375D_send_data(uint8_t data) {
    // Set the Data/Command (D/C) pin high to indicate data
    DigitalWrite(CD,High);
    
    // Send the data over SPI
    SPI_write(data);
}
