#include "Line.h"

namespace ProcessPlanning 
{

	Line::Line(void)
	{
	}


	Line::~Line(void)
	{
	}

	void Line::render(void)
	{
		ifImp->prepareRender(this);
		geomList.renderAllGeometries();
		ifImp->finishRender();
	}

}
