#pragma once
#include "ComplexGeometry.h"
#include "Graphics.h"

using namespace ProcessPlanning;

namespace ProcessPlanning
{
	class Contour :
		public ComplexGeometry
	{
	public:
		Contour(void);
		~Contour(void);
		virtual void render(void);
	};

}
