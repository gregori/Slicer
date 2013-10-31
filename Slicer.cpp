#include "Slicer.h"
#include "OpenGLImp.h"
#include "GraphicsImp.h"
#include "Graphics.h"
#include "Contour.h"
#include "Point.h"
#include "Rect.h"
#include "Slice.h"
#include "Timer.h"
#include <map>

namespace ProcessPlanning
{

	Slicer::Slicer(void)
	{
		sliceThickness = 0.152f;
		segmentTime = 0;
		sliceTime = 0;
	}


	Slicer::~Slicer(void)
	{
	}
	
	float Slicer::getSliceThickness(void) const
    {
        return sliceThickness;
    }
	
    void Slicer::setSliceThickness(const float st)
    {
        sliceThickness = st;
    }
	
	Slice* Slicer::getSlice(std::map<std::string, Rect*> segments)
	{
		int timeIni, timeEnd;
		
		//timeIni = timeEnd = 0;
		
		timeIni = Timer::getTimeMs();
		
		std::map<std::string, Rect*>::iterator segIt;
		Slice *s = new Slice();
		Contour *c = new Contour();
		
		while (!segments.empty())
        {
            segIt = segments.begin();
            std::string lbl = static_cast<Point*>(segIt->second->getGeometry(0))->getLabel();
			
            while (segments.count(lbl))
            {				
				Rect *l = segments[lbl];
				c->addGeometry(l);
				segments.erase(segments.find(lbl));
				Point *p2 = static_cast<Point*>(l->getGeometry(1));
				lbl = p2->getLabel();
            }
            c->setInterface(new Graphics(static_cast<GraphicsImp*>(new OpenGLImp())));
			s->addGeometry(c);
			c = new Contour();
        } 
		
		timeEnd = Timer::getTimeMs();
		
		this->incSegmentTime(timeEnd - timeIni);
		
		return s;
	}
	
	void Slicer::setSegmentTime(const int sTime)
	{
		segmentTime = sTime;
	}
	
	void Slicer::incSegmentTime(const int sTime)
	{
		segmentTime += sTime;
	}
	
	int Slicer::getSegmentTime(void) const
	{
		return segmentTime;
	}
	
	void Slicer::setSliceTime(const int sTime)
	{
		sliceTime = sTime;
	}
	
	void Slicer::incSliceTime(const int sTime)
	{
		sliceTime += sTime;
	}
	
	int Slicer::getSliceTime(void) const
	{
		return sliceTime;
	}
	
}
