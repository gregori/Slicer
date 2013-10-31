#include "PointFactory.h"
#include <sstream>
#include <cmath>
#include "OpenGLImp.h"

namespace ProcessPlanning
{
	PointFactory::PMap PointFactory::points;
	Graphics* PointFactory::gr;

	PointFactory::PointFactory(void)
	{
	}


	PointFactory::~PointFactory(void)
	{
        //TODO: Clean Point Vector
	}

	Point* PointFactory::getPoint(const float x, const float y, const float z)
	{
		Point* p;
        PMapIterator it;

        std::stringstream label;
        label << floor(1000*x) << "|" << floor(1000*y) << "|" << floor(1000*z);
        
        it = points.find(label.str());  
        if (it == points.end())
        {
            p = new Point(x, y, z);
			p->setInterface(PointFactory::gr);
            points[label.str()] = p;
        }
        else
            p = (it->second);

        return p;
	}
	
	void PointFactory::setGraphics(Graphics* g)
	{
		PointFactory::gr = g;
	}

}
