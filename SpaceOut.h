//-----------------------------------------------------------------
// Space Out Application
// C++ Header - SpaceOut.h
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <windows.h>
#include "Resource.h"
#include "GameEngine.h"
#include "Bitmap.h"
#include "Sprite.h"
#include "Background.h"
#include "AlienSprite.h"

//-----------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------
HINSTANCE         _hInstance;
GameEngine*       _pGame;
HDC               _hOffscreenDC;
HBITMAP           _hOffscreenBitmap;
Bitmap*           _pDesertBitmap;
Bitmap*           _pCarBitmap;
Bitmap*           _pSmCarBitmap;
Bitmap*           _pMissileBitmap;
Bitmap*           _pBlobboBitmap;
Bitmap*           _pBMissileBitmap;
Bitmap*           _pJellyBitmap;
Bitmap*           _pJMissileBitmap;
Bitmap*           _pTimmyBitmap;
Bitmap*           _pTMissileBitmap;
Bitmap*           _pSmExplosionBitmap;
Bitmap*           _pLgExplosionBitmap;
Bitmap*           _pGameOverBitmap;
Bitmap*			  _pSaucer;
Bitmap*           _pZombie;
Bitmap*			  _pBackground;
Sprite*           _pCarSprite;
int               _iFireInputDelay;
int               _iNumLives, _iScore, _iDifficulty;
int				  _iSaucerX, _iSaucerY;
BOOL              _bGameOver;
int				  _iSpeedX, _iSpeedY;
int				  direction;
int relativityX;
int relativityY;
bool leftClicked;
int mouseX;
int mouseY;
int bulletFrameDuration;
int bulletRelativityX;
int bulletRelativityY;

//-----------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------
void NewGame();
void AddAlien();
