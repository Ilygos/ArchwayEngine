#pragma once
#include "core/common.hpp"
#include "math/vector.hpp"

namespace Archway
{
	class IApplicationEventHandler
	{
		NULL_COPY_AND_ASSIGN(IApplicationEventHandler);

	public:
		IApplicationEventHandler();
		virtual ~IApplicationEventHandler();

		virtual void onKeyDown(uint32 keyCode, bool isRepeat) {};
		virtual void onKeyUp(uint32 keyCode, bool isRepeat) {};
		virtual void onMouseDown(uint32 mouseButton, uint8 numClicks) {};
		virtual void onMouseUp(uint32 mouseButton, uint8 numClicks) {};
		virtual void onMouseMove(Vector2f mousePos, Vector2f delta) {};
	};
}