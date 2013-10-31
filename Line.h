#pragma once
#include "ComplexGeometry.h"
#include "Graphics.h"

namespace ProcessPlanning
{

	class Line :
		public ComplexGeometry
	{
	public:
		Line(void);
		~Line(void);
		virtual void render(void);
	};

}
