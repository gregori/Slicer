/*
 * =====================================================================================
 *
 *       Filename:  SimpleSlicer.cpp
 *
 *    Description:  Simple Slicer Class implementation
 *
 *        Version:  1.0
 *        Created:  08/05/2012 08:39:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (), rodrigo.gregori@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "SimpleSlicer.h"
#include "GraphicsImp.h"
#include "OpenGLImp.h"
#include "Timer.h"
#include "Rect.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Timer.h"
#include "SimpleTriangle.h"

using namespace std;

namespace ProcessPlanning
{
    SimpleSlicer::SimpleSlicer(void)
    {
        
    }

    SimpleSlicer::~SimpleSlicer(void)
    {

    }

    Solid* SimpleSlicer::sliceMesh(Mesh* m)
    {
        float zMin, zMax;
		int iniTime, endTime;
		
		iniTime = Timer::getTimeMs();
		
        Solid *s = new Solid();
		std::map<std::string, Rect*> segments;

        zMin = m->getZMin();
        zMax = m->getZMax();
		
		s->setXMax(m->getXMax());
		s->setXMin(m->getXMin());
		s->setYMax(m->getYMax());
		s->setYMin(m->getYMin());
		s->setZMax(zMax);
		s->setZMin(zMin);
		s->setSphereCenter();
		s->setSphereRadius();

		endTime = Timer::getTimeMs();
		
		this->incSliceTime(endTime - iniTime);
		
        while (zMin < zMax)
        {
			iniTime = Timer::getTimeMs();
			std::map<std::string, Rect*> segments;
			
            for (int i = 0; i < m->getSize(); i++)
			{
				SimpleTriangle *t = static_cast<SimpleTriangle*> (m->getGeometry(i));
				m->incSliceCounter();
				if (t->checkInterception(zMin)) {
					m->incIfCounter();
					Rect *l = t->intercept(zMin);
					Point *p1 = static_cast<Point*> (l->getGeometry(0));
					std::string label = p1->getLabel();
					segments[label] = l;
				}
			}
			
			zMin += sliceThickness;
			
			endTime = Timer::getTimeMs();
			this->incSliceTime(endTime - iniTime);
			if (!segments.empty())
				s->addGeometry(getSlice(segments));
		}
        
        s->setInterface(new Graphics(static_cast<GraphicsImp*>(new OpenGLImp())));

        // :TODO: We should actually create the contours here
        return s;
    }
}
