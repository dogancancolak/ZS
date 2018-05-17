//-----------------------------------------------------------------
// ZS Application
// C++ Source - ZS.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "ZS.h"
#include <cmath>

//-----------------------------------------------------------------
// Game Engine Functions
//-----------------------------------------------------------------
BOOL GameInitialize(HINSTANCE hInstance)
{
	// Create the game engine
	_pGame = new GameEngine(hInstance, TEXT("ZS"),
		TEXT("ZS"), playerRight, playerRight, 500, 400);
	if (_pGame == NULL)
		return FALSE;

	// Set the frame rate
	_pGame->SetFrameRate(60);

	// Store the instance handle
	_hInstance = hInstance;

	return TRUE;
}

void GameStart(HWND hWindow)
{
	// Create and load the background and saucer bitmaps
	HDC hDC = GetDC(hWindow);
	_pBackground = new Bitmap(hDC, grass, _hInstance);
	_pSaucer = new Bitmap(hDC, playerRight, _hInstance);
	_pZombie = new Bitmap(hDC, zombieRight, _hInstance);

	// Set the initial saucer position and speed
	_iSaucerX = 640 - (_pSaucer->GetWidth() / 2);
	_iSaucerY = 360 - (_pSaucer->GetHeight() / 2);
	_iSpeedX = 0;
	_iSpeedY = 0;
	relativityX = 0;
	relativityY = 0;
	leftClicked = false;
	mouseX = 0;
	mouseY = 0;
	bulletFrameDuration = 0;
	bulletRelativityX = 0;
	bulletRelativityY = 0;
}

void GameEnd()
{
	// Cleanup the background and saucer bitmaps
	delete _pBackground;
	delete _pSaucer;

	// Cleanup the game engine
	delete _pGame;
}

void GameActivate(HWND hWindow)
{
}

void GameDeactivate(HWND hWindow)
{
}

int mod(int num, int m) {
	int result = num % m;
	if (result < 0)
	{
		result += m;
	}
	return result;
}

void GamePaint(HDC hDC)
{

	// Draw the background and saucer bitmaps
	for (int i = -5; i < 16; i++)
	{
		for (int j = -4; j < 12; j++)
		{
			_pBackground->Draw(hDC, _iSaucerX + relativityX % 125 + i * 125, _iSaucerY + relativityY % 100 + j * 100, FALSE);
		}
	}


	//_pBackground->Draw(hDC, mod(-_iSaucerX, 500) - 500, 0, FALSE);

	_pZombie->Draw(hDC, relativityX, relativityY, TRUE);
	_pSaucer = new Bitmap(hDC, direction, _hInstance);
	_pSaucer->Draw(hDC, _iSaucerX, _iSaucerY, TRUE);
	if (leftClicked || bulletFrameDuration > 0)
	{
		HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		MoveToEx(hDC, 640 + relativityX - bulletRelativityX, 360 + relativityY - bulletRelativityY, NULL);
		LineTo(hDC, mouseX + relativityX - bulletRelativityX, mouseY + relativityY - bulletRelativityY);
		leftClicked = false;
		bulletFrameDuration--;
	}
}

void GameCycle()
{



	// Update the saucer position

	_iSaucerX = 640 - _pSaucer->GetWidth() / 2;
	_iSaucerY = 360 - _pSaucer->GetHeight() / 2;

	// Force a repaint to redraw the saucer
	InvalidateRect(_pGame->GetWindow(), NULL, FALSE);
}

void HandleKeys()
{
	// Change the speed of the saucer in response to arrow key presses
	if (GetAsyncKeyState(0x41) < 0)
		relativityX += 5;
	else if (GetAsyncKeyState(0x44) < 0)
		relativityX -= 5;
	if (GetAsyncKeyState(0x57) < 0)
		relativityY += 5;
	else if (GetAsyncKeyState(0x53) < 0)
		relativityY -= 5;
}

void MouseButtonDown(int x, int y, BOOL bLeft)
{
	if (bLeft)
	{
		mouseX = x;
		mouseY = y;
		leftClicked = true;
		bulletFrameDuration = 10;
		bulletRelativityX = relativityX;
		bulletRelativityY = relativityY;
	}

}

void MouseButtonUp(int x, int y, BOOL bLeft)
{
}

void MouseMove(int x, int y)
{
	int relativeX = x - 1280 / 2;
	int relativeY = y - 720 / 2;
	if (relativeX > 0 && abs(relativeX) > abs(relativeY))
	{
		//Right
		direction = playerRight;
	}
	else if (relativeY > 0 && abs(relativeY) > abs(relativeX))
	{
		//Down
		direction = playerDown;
	}
	else if (relativeX < 0 && abs(relativeX) >  abs(relativeY))
	{
		//Left
		direction = playerLeft;
	}
	else if (relativeY < 0 && abs(relativeY) > abs(relativeX))
	{
		//Up
		direction = playerUp;
	}
}
