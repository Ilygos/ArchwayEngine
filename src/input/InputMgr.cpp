#include "InputMgr.h"
using namespace Archway;

InputMgr* InputMgr::Singleton = nullptr;

void InputMgr::OnKeyDown(uint32 keyCode, bool isRepeat)
{
	KeysDown[keyCode] = true;
}

void InputMgr::OnKeyUp(uint32 keyCode, bool isRepeat)
{
	KeysDown[keyCode] = false;
}

void InputMgr::OnMouseDown(uint32 mouseButton, uint8 numClicks)
{
	MouseDown[mouseButton] = true;
}

void InputMgr::OnMouseUp(uint32 mouseButton, uint8 numClicks)
{
	MouseDown[mouseButton] = false;
}

void InputMgr::OnMouseMove(Vector2f mousePos, Vector2f delta)
{
	MousePos = mousePos;
}