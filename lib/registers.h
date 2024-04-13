// Register names from Peter Barrett's Microtouch code

#define TFTLCD_DELAY 0xFF


#define HX8357_NOP 0x00
#define HX8357_SWRESET 0x01
#define HX8357_RDDID 0x04
#define HX8357_RDDST 0x09



#define HX8357_SLPIN 0x10
#define HX8357_SLPOUT 0x11


#define HX8357_INVOFF 0x20
#define HX8357_INVON 0x21
#define HX8357_DISPOFF 0x28
#define HX8357_DISPON 0x29

#define HX8357_CASET 0x2A
#define HX8357_PASET 0x2B
#define HX8357_RAMWR 0x2C
#define HX8357_RAMRD 0x2E

#define HX8357B_PTLAR 0x30
#define HX8357_TEON 0x35
#define HX8357_TEARLINE 0x44
#define HX8357_MADCTL 0x36
#define HX8357_COLMOD 0x3A

#define HX8357_SETOSC 0xB0
#define HX8357_SETPWR1 0xB1

#define HX8357_SETRGB 0xB3
#define HX8357D_SETCOM 0xB6


#define HX8357D_SETCYC 0xB4

#define HX8357D_SETC 0xB9


#define HX8357D_SETSTBA 0xC0

#define HX8357_SETPANEL 0xCC

#define HX8357_SETSPI 0xFE



#define HX8357D_SETGAMMA 0xE0

// HX8375D Commands
#define HX8375D_CMD_NOP          0x00
#define HX8375D_CMD_SWRESET      0x01
#define HX8375D_CMD_RD_DISP_ID   0x04
#define HX8375D_CMD_RD_STAT      0x09
#define HX8375D_CMD_RD_MADCTL    0x0B
#define HX8375D_CMD_RD_PIXEL_FMT 0x0C
#define HX8375D_CMD_RD_IMG_FMT   0x0D
#define HX8375D_CMD_RD_SIG_MODE  0x0E
#define HX8375D_CMD_RD_PWR_MODE  0x0F
#define HX8375D_CMD_RD_ID1       0xDA
#define HX8375D_CMD_RD_ID2       0xDB
#define HX8375D_CMD_RD_ID3       0xDC
#define HX8375D_CMD_RD_ID4       0xDD

#define HX8375D_CMD_SLPOUT       0x11
#define HX8375D_CMD_DISPON       0x29
#define HX8375D_CMD_CASET         0x2A
#define HX8375D_CMD_PASET         0x2B
#define HX8375D_CMD_RAMWR         0x2C




// Color definitions for graphics 
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF