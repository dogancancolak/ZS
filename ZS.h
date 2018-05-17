//-----------------------------------------------------------------
// UFO Application
// C++ Header - UFO.h
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <windows.h>
#include "Resource.h"
#include "GameEngine.h"
#include "Bitmap.h"

//-----------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------
HINSTANCE   _hInstance;
GameEngine* _pGame;
const int   _iMAXSPEED = 8;
Bitmap*     _pBackground;
Bitmap*     _pSaucer;
Bitmap*     _pZombie;
int         _iSaucerX, _iSaucerY;
int         _iSpeedX, _iSpeedY;
int         direction;
int relativityX;
int relativityY;
bool leftClicked;
int mouseX;
int mouseY;
int bulletFrameDuration;
int bulletRelativityX;
int bulletRelativityY;
