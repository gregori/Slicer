/*
 *  SetSlicer.cpp
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 19/09/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "SetSlicer.h"
#include "Rect.h"
#include "Graphics.h"
#include "OpenGLImp.h"
#include "GraphicsImp.h"
#include "SimpleTriangle.h"
#include "Timer.h"
#include <set>
#include <map>
#include <vector>
#include <iostream>

namespace ProcessPlanning 
{
	SetSlicer::SetSlicer()
	{
		
	}
	
	SetSlicer::~SetSlicer()
	{
		
	}
	
	Solid* SetSlicer::sliceMesh(Mesh *m)
	{
		float zMin, zMax;
		int iniTime, endTime;
		std::set<float> zSet;
		std::map<float, std::map<std::string, Rect*> > segments;
		
		iniTime = Timer::getTimeMs();
		
		Solid *s = new Solid();
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
		
		for (float i = zMin + sliceThickness; i < zMax; i += sliceThickness) 
		{
			zSet.insert(i);
		}
		
		
		std::cout << m->getSize() << " triangles." << std::endl;
		for (int i = 0; i < m->getSize(); i++) 
		{
			SimpleTriangle *t = static_cast<SimpleTriangle*>(m->getGeometry(i));
			m->incIfCounter();
			std::set<float>::iterator itlow,itup;
			
			itlow = zSet.lower_bound(t->getZMin());
			itup = zSet.upper_bound(t->getZMax());
			
			for (std::set<float>::iterator it=itlow; it!=itup; ++it)
			{
				if (t->checkInterception(*it)) 
				{
					Rect *l = t->intercept(*it);
					Point *p1 = static_cast<Point*>(l->getGeometry(0));
					
					segments[*it][p1->getLabel()] = l;
				}
				
			}			
		}
		endTime = Timer::getTimeMs();
		
		this->incSliceTime(endTime - iniTime);
		
		for (std::map<float, std::map<std::string, Rect*> >::iterator it = segments.begin(); 
							it != segments.end(); ++it) 
		{
			s->addGeometry(this->getSlice(it->second));
		}
		
		return s;
		
	}
	
}


