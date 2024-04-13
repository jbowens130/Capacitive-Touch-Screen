#include <avr/io.h>
#include <util/delay.h>
#include "lib\registers.h"
#include "lib\spi_init.h"
#include <util/delay.h>
#include <stdint.h>

void HX8375D_init() {
    // Initialize SPI communication
    SPI_init();
    static const uint8_t HX8357D_regValues[] = {
    HX8357_SWRESET,
        0x80 + 100 / 5, // Soft reset, then delay 10 ms
        HX8357D_SETC,
        3,
        0xFF,
        0x83,
        0x57,
        0xFF,
        0x80 + 500 / 5, // No command, just delay 300 ms
        HX8357_SETRGB,
        4,
        0x80,
        0x00,
        0x06,
        0x06, // 0x80 enables SDO pin (0x00 disables)
        HX8357D_SETCOM,
        1,
        0x25, // -1.52V
        HX8357_SETOSC,
        1,
        0x68, // Normal mode 70Hz, Idle mode 55 Hz
        HX8357_SETPANEL,
        1,
        0x05, // BGR, Gate direction swapped
        HX8357_SETPWR1,
        6,
        0x00, // Not deep standby
        0x15, // BT
        0x1C, // VSPR
        0x1C, // VSNR
        0x83, // AP
        0xAA, // FS
        HX8357D_SETSTBA,
        6,
        0x50, // OPON normal
        0x50, // OPON idle
        0x01, // STBA
        0x3C, // STBA
        0x1E, // STBA
        0x08, // GEN
        HX8357D_SETCYC,
        7,
        0x02, // NW 0x02
        0x40, // RTN
        0x00, // DIV
        0x2A, // DUM
        0x2A, // DUM
        0x0D, // GDON
        0x78, // GDOFF
        HX8357D_SETGAMMA,
        34,
        0x02,
        0x0A,
        0x11,
        0x1d,
        0x23,
        0x35,
        0x41,
        0x4b,
        0x4b,
        0x42,
        0x3A,
        0x27,
        0x1B,
        0x08,
        0x09,
        0x03,
        0x02,
        0x0A,
        0x11,
        0x1d,
        0x23,
        0x35,
        0x41,
        0x4b,
        0x4b,
        0x42,
        0x3A,
        0x27,
        0x1B,
        0x08,
        0x09,
        0x03,
        0x00,
        0x01,
        HX8357_COLMOD,
        1,
        0x55, // 16 bit
        HX8357_MADCTL,
        1,
        0xC0,
        HX8357_TEON,
        1,
        0x00, // TW off
        HX8357_TEARLINE,
        2,
        0x00,
        0x02,
        HX8357_SLPOUT,
        0x80 + 150 / 5, // Exit Sleep, then delay 150 ms
        HX8357_DISPON,
        0x80 + 50 / 5, // Main screen turn on, delay 50 ms
        0, 
    };

    // Perform initialization sequence
    for(int i = 0; i < sizeof(HX8357D_regValues);i++){
        HX8375D_send_command(HX8357D_regValues[i]);
        
    }
    
}

void setAddressWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h){
    uint16_t x2 = (x1 + w - 1), y2 = (y1 + h - 1);
    HX8375D_send_command(HX8357_CASET);
    HX8375D_send_data(x1);
    HX8375D_send_data(x2);
    HX8375D_send_command(HX8357_PASET);
    HX8375D_send_data(y1);
    HX8375D_send_data(y2);
    HX8375D_send_command(HX8357_RAMWR);

}





int main() {
    HX8375D_init();
    
}


