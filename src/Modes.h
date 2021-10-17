//******************************************************************************
// Modes.h
//******************************************************************************

#ifndef MODES_H
#define MODES_H

typedef enum eMode : uint8_t
{
	MODE_TIME,				 // 0
#ifdef SHOW_MODE_ANSAGE
	MODE_ANSAGE,			 // 1
#endif
#ifdef SHOW_MODE_WEEKDAY
	MODE_WEEKDAY,			 // 2
#endif
#ifdef SHOW_MODE_DATE
  MODE_DATE,         // 3
#endif
#ifdef SHOW_MODE_MOONPHASE
	MODE_MOONPHASE,		 // 4
#endif
#if defined(RTC_BACKUP) || defined(SENSOR_BME280)
	MODE_TEMP,				 // 5
#endif
#ifdef SENSOR_BME280
	MODE_HUMIDITY,		 // 6
  MODE_LUFTDRUCK,    // 7
#endif
#ifdef APIKEY
  MODE_WETTER,       // 8 
	MODE_EXT_TEMP,		 // 9
	MODE_EXT_HUMIDITY, // 10
#endif
#ifdef SHOW_MODE_SECONDS
  MODE_SECONDS,      // 11 
#endif
#ifdef SHOW_MODE_TEST
  MODE_IP,           // 12
	MODE_TEST,				 // 13
	MODE_RED,				   // 14
	MODE_GREEN,				 // 15
	MODE_BLUE,				 // 16
	MODE_WHITE,				 // 17
#endif
#if defined(BUZZER) || defined(AUDIO_SOUND)
  MODE_TIMER,        // 18
#endif
	MODE_COUNT,				 // 19
	MODE_BLANK,				 // 20
	MODE_FEED,				 // 21
  MODE_SHOWANIMATION,  // 22
  MODE_MAKEANIMATION,  // 23
  MODE_ALARMANIMATION,  // 24
  MODE_GAME             //25
 
} Mode;

// Overload the ControlType++ operator.
inline Mode& operator++(Mode& eDOW, int)
{
	const uint8_t i = static_cast<uint8_t>(eDOW) + 1;
	eDOW = static_cast<Mode>((i) % MODE_COUNT);
	return eDOW;
}

enum eTransition
{
  TRANSITION_NORMAL,        //0
  TRANSITION_FARBENMEER,    //1
  TRANSITION_MOVEUP,        //2
  TRANSITION_MOVEDOWN,      //3
  TRANSITION_MOVELEFT,      //4
  TRANSITION_MOVERIGHT,     //5
  TRANSITION_MOVELEFTDOWN,  //6
  TRANSITION_MOVERIGHTDOWN, //7
  TRANSITION_MOVECENTER,    //8
  TRANSITION_FADE,          //9
  TRANSITION_MATRIX,        //10
  TRANSITION_SPIRALE_LINKS, //11
  TRANSITION_SPIRALE_RECHTS,//12
  TRANSITION_ZEILENWEISE,   //13
  TRANSITION_REGENBOGEN,    //14
  TRANSITION_MITTE_LINKSHERUM, //15
  TRANSITION_QUADRATE,      //16
  TRANSITION_MAX,           //17
  TRANSITION_PH2,           //18
  TRANSITION_PH3,           //19
  TRANSITION_ALLE_NACHEINANDER, //20
  TRANSITION_RANDOM         //21
};

enum SERTYPE
{
  SPIRALE_LINKS,      //0
  SPIRALE_RECHTS,     //1
  ZEILENWEISE,        //2
  MITTE_LINKSHERUM,   //3
  SPALTENWEISE,       //4
  QUER                //5
};

const uint16_t seriellpointer[][110] PROGMEM = 
{
     { //SPIRALE links
      0,1,2,3,4,5,6,7,8,9,10,21,32,43,54,65,76,87,98,109,
     108,107,106,105,104,103,102,101,100,99,88,77,66,55,44,33,22,11,
     12,13,14,15,15,17,18,19,20,31,42,53,64,75,86,97,
     96,95,94,93,92,91,90,89,78,67,56,45,34,23,
     24,25,26,27,28,29,30,41,52,63,74,85,
     84,83,82,81,80,79,68,57,46,35,
     36,37,38,39,40,51,62,73,72,71,70,69,
     58,47,48,49,50,61,60,59
     },
     { //SPIRALE rechts
       59, 60, 61, 50, 49, 48, 47, 58, 69, 70, 71, 72, 73, 62, 51, 40, 39, 38, 37, 36, 35, 46,
       57, 68, 79, 80, 81, 82, 83, 84, 85, 74, 63, 52, 41, 30, 29, 28, 27, 26, 25, 24, 23, 34,
       45, 56, 67, 78, 89, 90, 91, 92, 93, 94, 95, 96, 97, 85, 75, 64, 53, 42, 31, 20, 19, 18,
       17, 16, 15, 14, 13, 12, 11, 22, 33, 44, 55, 66, 77, 88, 99,100,101,102,103,104,105,106,
      107,108,109, 98, 87, 76, 65, 54, 43, 32, 21, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0
     },
     { //Zeilenweise
      0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,21,20,19,18,17,16,15,14,13,12,11,
      22,23,24,25,26,27,28,29,30,31,32,43,42,41,40,39,38,37,36,35,34,33,
      44,45,46,47,48,49,50,51,52,53,54,65,64,63,62,61,60,59,58,57,56,55,
      66,67,68,69,70,71,72,73,74,75,76,87,86,85,84,83,82,81,80,79,78,77,
      88,89,90,91,92,93,94,95,96,97,98,109,108,107,106,105,104,103,102,101,100,99
     },
     { //MITTE_LINKSHERUM
      0,1,13,25,37,48, 2,14,26, 3,4,15, 5,16,27,38,49, 7,6,17,
      8,18,28, 10,9,19,29,39,50, 21,20,30,40, 32,31,41,51 ,43,
      42,52, 54,53, 65,64, 76,75,63, 87,86,74,62, 98,97,85,
      73, 109,108,96,84,72,61, 107,95,83, 106,105,94, 104,
      93,82,71,60, 102,103,92, 101,91,81, 99,100,
      90,80,70,59, 88,89,79,69, 77,78,
      68,58, 66,67,57, 55,56, 44,45, 33,34,46,
      22,23,35,47, 11,12,24,36},
     { //Spaltenweise
       0,11,22,33,44,55,66,77,88,99,1,12,23,34,45,56,67,78,89,100,
       2,13,24,35,46,57,68,79,90,101,3,14,25,36,47,58,69,80,91,102,
       4,15,26,37,48,59,70,81,92,103,5,16,27,38,49,60,71,82,93,104,
       6,17,28,39,50,61,72,83,94,105,7,18,29,40,51,62,73,84,95,106,
       8,19,30,41,52,63,74,85,96,107,9,20,31,42,53,64,75,86,97,108,
       10,21,32,43,54,65,76,87,98,109
     },
     { //quer
       99,100, 88, 77, 89,101,102, 90, 78, 66, 55, 67, 79, 91,103,104, 92, 80, 68, 56, 44, 33,
       45, 57, 69, 81, 93,105,106, 94, 82, 70, 58, 46, 34, 22, 11, 23, 35, 47, 59, 71, 83, 95,
      107,108, 96, 84, 72, 60, 48, 36, 24, 12,  0,  1, 13, 25, 37, 49, 61, 73, 85, 97,109, 98,
       86, 74, 62, 50, 38, 26, 14,  2,  3, 15, 27, 39, 51, 63, 75, 87, 76, 64, 52, 40, 28, 16,
        4,  5, 17, 29, 41, 53, 65, 54, 42, 30, 18,  6,  7, 19, 31, 43, 32, 20,  8,  9, 21, 10
     }
};

const uint16_t MONDMATRIX[][10] PROGMEM =
{
  { // 0 Neumond
        0b0000101000000000,
        0b0010000010000000,
        0b0100000001000000,
        0b0000000000000000,
        0b1000000000100000,
        0b1000000000100000,
        0b0000000000000000,
        0b0100000001000000,
        0b0010000010000000,
        0b0000101000000000
  },
  { // 1
        0b0000011000000000,
        0b0000000110000000,
        0b0000000001000000,
        0b0000000001000000,
        0b0000000000100000,
        0b0000000000100000,
        0b0000000001000000,
        0b0000000001000000,
        0b0000000110000000,
        0b0000011000000000
  },
  { // 2
        0b0000011000000000,
        0b0000000110000000,
        0b0000000011000000,
        0b0000000011000000,
        0b0000000001100000,
        0b0000000001100000,
        0b0000000011000000,
        0b0000000011000000,
        0b0000000110000000,
        0b0000011000000000
  },
    { // 3
        0b0000011000000000,
        0b0000001110000000,
        0b0000000111000000,
        0b0000000011000000,
        0b0000000011100000,
        0b0000000011100000,
        0b0000000011000000,
        0b0000000111000000,
        0b0000001110000000,
        0b0000011000000000
  },
    { // 4
        0b0000011000000000,
        0b0000001110000000,
        0b0000000111000000,
        0b0000000111000000,
        0b0000000111100000,
        0b0000000111100000,
        0b0000000111000000,
        0b0000000111000000,
        0b0000001110000000,
        0b0000011000000000
  },
    { // 5
        0b0000011000000000,
        0b0000001110000000,
        0b0000001111000000,
        0b0000001111000000,
        0b0000001111100000,
        0b0000001111100000,
        0b0000001111000000,
        0b0000001111000000,
        0b0000001110000000,
        0b0000011000000000
  },
    { // 6
        0b0000011000000000,
        0b0000011110000000,
        0b0000011111000000,
        0b0000011111000000,
        0b0000011111100000,
        0b0000011111100000,
        0b0000011111000000,
        0b0000011111000000,
        0b0000011110000000,
        0b0000011000000000
  },
    { // 7
        0b0000011000000000,
        0b0000011110000000,
        0b0000111111000000,
        0b0000111111000000,
        0b0000111111100000,
        0b0000111111100000,
        0b0000111111000000,
        0b0000111111000000,
        0b0000011110000000,
        0b0000011000000000
  },
    { // 8
        0b0000111000000000,
        0b0000111110000000,
        0b0001111111000000,
        0b0001111111000000,
        0b0001111111100000,
        0b0001111111100000,
        0b0001111111000000,
        0b0001111111000000,
        0b0000111110000000,
        0b0000111000000000
  },
    { // 9
        0b0000111000000000,
        0b0001111110000000,
        0b0001111111000000,
        0b0011111111000000,
        0b0011111111100000,
        0b0011111111100000,
        0b0011111111000000,
        0b0001111111000000,
        0b0001111110000000,
        0b0000111000000000
  },
    { // 10
        0b0000111000000000,
        0b0001111110000000,
        0b0011111111000000,
        0b0111111111000000,
        0b0111111111100000,
        0b0111111111100000,
        0b0111111111000000,
        0b0011111111000000,
        0b0001111110000000,
        0b0000111000000000
  },
    { // 11 Vollmond
        0b0000111000000000,
        0b0011111110000000,
        0b0111111111000000,
        0b0111111111000000,
        0b1111111111100000,
        0b1111111111100000,
        0b0111111111000000,
        0b0111111111000000,
        0b0011111110000000,
        0b0000111000000000
  },
    { // 12
        0b0000111000000000,
        0b0011111100000000,
        0b0111111110000000,
        0b0111111111000000,
        0b1111111111000000,
        0b1111111111000000,
        0b0111111111000000,
        0b0111111110000000,
        0b0011111100000000,
        0b0000111000000000
  },
    { // 13
        0b0000111000000000,
        0b0011111100000000,
        0b0111111100000000,
        0b0111111110000000,
        0b1111111110000000,
        0b1111111110000000,
        0b0111111110000000,
        0b0111111100000000,
        0b0011111100000000,
        0b0000111000000000
  },
    { // 14
        0b0000111000000000,
        0b0011111000000000,
        0b0111111100000000,
        0b0111111100000000,
        0b1111111100000000,
        0b1111111100000000,
        0b0111111100000000,
        0b0111111100000000,
        0b0011111000000000,
        0b0000111000000000
  },
    { // 15
        0b0000110000000000,
        0b0011110000000000,
        0b0111111000000000,
        0b0111111000000000,
        0b1111111000000000,
        0b1111111000000000,
        0b0111111000000000,
        0b0111111000000000,
        0b0011110000000000,
        0b0000110000000000
  },
    { // 16
        0b0000110000000000,
        0b0011110000000000,
        0b0111110000000000,
        0b0111110000000000,
        0b1111110000000000,
        0b1111110000000000,
        0b0111110000000000,
        0b0111110000000000,
        0b0011110000000000,
        0b0000110000000000
  },
    { // 17
        0b0000110000000000,
        0b0011100000000000,
        0b0111100000000000,
        0b0111100000000000,
        0b1111100000000000,
        0b1111100000000000,
        0b0111100000000000,
        0b0111100000000000,
        0b0011100000000000,
        0b0000110000000000
  },
    { // 18
        0b0000110000000000,
        0b0011100000000000,
        0b0111000000000000,
        0b0111000000000000,
        0b1111000000000000,
        0b1111000000000000,
        0b0111000000000000,
        0b0111000000000000,
        0b0011100000000000,
        0b0000110000000000
  },
    { // 19
        0b0000110000000000,
        0b0011100000000000,
        0b0111000000000000,
        0b0110000000000000,
        0b1110000000000000,
        0b1110000000000000,
        0b0110000000000000,
        0b0111000000000000,
        0b0011100000000000,
        0b0000110000000000
  },
    { // 20
        0b0000110000000000,
        0b0011000000000000,
        0b0110000000000000,
        0b0110000000000000,
        0b1100000000000000,
        0b1100000000000000,
        0b0110000000000000,
        0b0110000000000000,
        0b0011000000000000,
        0b0000110000000000
  },
    { // 21
        0b0000110000000000,
        0b0011000000000000,
        0b0100000000000000,
        0b0100000000000000,
        0b1000000000000000,
        0b1000000000000000,
        0b0100000000000000,
        0b0100000000000000,
        0b0011000000000000,
        0b0000110000000000
  },
    { // 22 Neumond
        0b0000101000000000,
        0b0010000010000000,
        0b0100000001000000,
        0b0000000000000000,
        0b1000000000100000,
        0b1000000000100000,
        0b0000000000000000,
        0b0100000001000000,
        0b0010000010000000,
        0b0000101000000000
  }
};
#endif
