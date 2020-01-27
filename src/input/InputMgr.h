#pragma once
#include "core/ApplicationEventHandler.h"
#include "iinput.h"
#include <functional>

namespace Archway
{
	struct InputAction
	{
		
	};

	class InputMgr : public IApplicationEventHandler
	{
		static InputMgr* singleton;

		public:
			static InputMgr* getSingleton() { return singleton; };
			Vector2f mousePosition;
			
			//----------------------------------------------------------------
			//Input arrays: need to be filled before next frame
			//----------------------------------------------------------------
			
			Vector2f	MousePos;			// Mouse position in screen
			bool        MouseDown[5];		// Mouse buttons pressed -- 0=left, 1=right, 2=middle + miscs
			float       MouseWheel;         // Mouse wheel Vertical: 1 unit scrolls about 5 lines text.
			bool        KeysDown[512];		// Keyboard keys pressed need to follow the platform key order
			bool		KeyCtrl;			// Ctrl key pressed
			bool        KeyAlt;				// Alt key pressed
			bool        KeySuper;			// Super/Cmd/Windows key pressed

			~InputMgr() {};
			InputMgr() 
			{ 
				if (singleton)
					delete this;
				else
					singleton = this;
			};
			//-----------------------------------------------------------------
			//Events: need to be called in the platform implementation
			//-----------------------------------------------------------------

			virtual void OnKeyDown(uint32 keyCode, bool isRepeat);			// Keyboard KeyDown event
			virtual void OnKeyUp(uint32 keyCode, bool isRepeat);				// Keyboard KeyUp event
			virtual void OnMouseDown(uint32 mouseButton, uint8 numClicks);	// Mouse ButtonDown event
			virtual void OnMouseUp(uint32 mouseButton, uint8 numClicks);		// Mouse ButtonUp event
			virtual void OnMouseMove(Vector2f mousePos, Vector2f delta);		// Mouse Move event

	};	

	#define	INPUT_MGR Archway::InputMgr::getSingleton()
} //namespace Archway