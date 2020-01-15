#pragma once
#include "core/ApplicationEventHandler.h"
#include "iinput.h"
#include <functional>

namespace Archway
{
	class InputMgr : public IApplicationEventHandler
	{
		static InputMgr* singleton;

		public:
			static InputMgr* getSingleton() { return singleton; };
			Vector2f mousePosition;

			~InputMgr() {};
			InputMgr() 
			{ 
				if (singleton)
					delete this;
				else
					singleton = this;
			};


	};	

	#define	INPUT_MGR Archway::InputMgr::getSingleton()
} //namespace Archway