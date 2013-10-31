#pragma once
#include "ComplexGeometry.h"
#include "Graphics.h"

namespace ProcessPlanning
{

	class Rect :
		public ComplexGeometry
	{
	public:
		Rect(void);
		~Rect(void);
		virtual void render(void);
	};

}
