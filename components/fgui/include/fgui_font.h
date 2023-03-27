#ifndef F30965E7_1FA3_4E9C_89B5_9BACC4535F1D
#define F30965E7_1FA3_4E9C_89B5_9BACC4535F1D

#include <stdint.h>

typedef int16_t UG_S16;
typedef uint16_t UG_U16;
typedef uint8_t UG_U8;

#define USE_FONT_8X8
#define USE_FONT_10X16
#define USE_FONT_12X20
#define USE_FONT_32X53


#define __UG_FONT_DATA const

typedef enum
{
	FONT_TYPE_1BPP,
	FONT_TYPE_8BPP
} FONT_TYPE;

typedef struct
{
   const unsigned char* p;
   FONT_TYPE font_type;
   UG_S16 char_width;
   UG_S16 char_height;
   UG_U16 start_char;
   UG_U16 end_char;
   const UG_U8  *widths;
} UG_FONT;

typedef const UG_FONT* fgui_font_t;

#ifdef USE_FONT_4X6
   extern const UG_FONT FONT_4X6;
#endif
#ifdef USE_FONT_5X8
   extern const UG_FONT FONT_5X8;
#endif
#ifdef USE_FONT_5X12
   extern const UG_FONT FONT_5X12;
#endif
#ifdef USE_FONT_6X8
   extern const UG_FONT FONT_6X8;
#endif
#ifdef USE_FONT_6X10
   extern const UG_FONT FONT_6X10;
#endif
#ifdef USE_FONT_7X12
   extern const UG_FONT FONT_7X12;
#endif
#ifdef USE_FONT_8X8
   extern const UG_FONT FONT_8X8;
#endif
#ifdef USE_FONT_8X12
   extern const UG_FONT FONT_8X12;
#endif
#ifdef USE_FONT_8X14
   extern const UG_FONT FONT_8X14;
#endif
#ifdef USE_FONT_10X16
   extern const UG_FONT FONT_10X16;
#endif
#ifdef USE_FONT_12X16
   extern const UG_FONT FONT_12X16;
#endif
#ifdef USE_FONT_12X20
   extern const UG_FONT FONT_12X20;
#endif
#ifdef USE_FONT_16X26
   extern const UG_FONT FONT_16X26;
#endif
#ifdef USE_FONT_22X36
   extern const UG_FONT FONT_22X36;
#endif
#ifdef USE_FONT_24X40
   extern const UG_FONT FONT_24X40;
#endif
#ifdef USE_FONT_32X53
   extern const UG_FONT FONT_32X53;
#endif

extern const UG_FONT font_VCR_OSD_MONO_1_28X39;

extern const UG_FONT font_VCR_OSD_MONO_1_57X81;

extern const UG_FONT font_UbuntuMono_R_16X28;
extern const UG_FONT font_UbuntuMono_R_31X64;
extern const UG_FONT font_UbuntuMono_R_62X112;

extern const UG_FONT font_UbuntuMono_R_39X70;
extern const UG_FONT font_UbuntuMono_R_24X42;

#endif /* F30965E7_1FA3_4E9C_89B5_9BACC4535F1D */
