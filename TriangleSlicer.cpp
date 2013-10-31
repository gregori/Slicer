/*
 *  TriangleSlicer.cpp
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 22/09/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "TriangleSlicer.h"
#include "SimpleTriangle.h"
#include "Timer.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <exception>

namespace ProcessPlanning {
	TriangleSlicer::TriangleSlicer()
	{
		
	}
	
	TriangleSlicer::~TriangleSlicer()
	{
		
	}

	Solid* TriangleSlicer::sliceMesh(Mesh *m)
	{
		float zMin, zMax;
		//std::map<float, std::map<std::string, Rect*> > segments;
		std::vector<std::map<std::string, Rect*> > segments;
		
		int timeIni, timeEnd;
		
		timeIni = Timer::getTimeMs();
		
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
		
		segments.resize(ceil((zMax-zMin)/sliceThickness));
		
		//std::cout << m->getSize() << " triangles." << std::endl;
		for (int i = 0; i < m->getSize(); i++) 
		{
			SimpleTriangle *t = static_cast<SimpleTriangle*>(m->getGeometry(i));
			int sliceTimes = floorf((t->getZMin()-zMin)/sliceThickness);
			
			for (float z = sliceTimes*sliceThickness; z < t->getZMax(); z += sliceThickness)
			{
				m->incSliceCounter();
				if (t->checkInterception(z)) 
				{
					m->incIfCounter();
					Rect *l = t->intercept(z);
					Point *p1 = static_cast<Point*>(l->getGeometry(0));
					
					//segments[z][p1->getLabel()] = l;
					
					int vectorIndex = ceil(z/sliceThickness)-sliceTimes;
					
					try 
					{
						segments.at(vectorIndex)[p1->getLabel()] = l;
					}
					catch (exception& e)
					{
						std::map<std::string, Rect*> tMap;
						tMap[p1->getLabel()] = l;
						segments.at(vectorIndex) = tMap;
					}				

				}
				
			}			
		}
		
		timeEnd = Timer::getTimeMs();
		
		this->incSliceTime(timeEnd - timeIni);
		//std::cout << "Assembling the contour" << std::endl;
		
		/*for (std::map<float, std::map<std::string, Rect*> >::iterator it = segments.begin(); 
			 it != segments.end(); ++it) 
		{
			if (!(it->second).empty())
				s->addGeometry(this->getSlice(it->second));
		}*/
		
		for (int j = 0; j < segments.size(); ++j) {
			std::cout << "segments[" << j << "] : " << std::endl;
			
			for (std::map<std::string, Rect*>::iterator it = (segments[j]).begin(); it != (segments[j]).end(); ++it) {
				std::cout << "map[" << (*it).first << "] = " << static_cast<Point*>(((*it).second)->getGeometry(0))->getLabel() << " - " 
						<< static_cast<Point*>(((*it).second)->getGeometry(1))->getLabel() << std::endl;
			}
			cout << "----------------------------" << endl;
		}
		
		for (std::vector<std::map<std::string, Rect*> >::iterator it = segments.begin(); 
			 it != segments.end(); ++it) 
		{
			if (!(*it).empty())	
				s->addGeometry(this->getSlice(*it));
		}
		
		
		return s;
		
	}
}
