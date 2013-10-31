/*
 *  TataSlicer.cpp
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 29/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "TataSlicer.h"
#include "Solid.h"
#include "OrderedMesh.h"
#include "SimpleTriangle.h"
#include "Timer.h"
#include "OpenGLImp.h"
#include "Rect.h"
#include "Point.h"
#include <map>
#include <string>
#include <cmath>

namespace ProcessPlanning 
{
	TataSlicer::TataSlicer()
	{
		
	}
	
	TataSlicer::~TataSlicer()
	{
		
	}
	
	Solid* TataSlicer::sliceMesh(Mesh* m)
    {
        float zMin, zMax;
		int timeIni, timeEnd;
		
		timeIni = Timer::getTimeMs();
        Solid *s = new Solid();
		std::map<std::string, Rect*> segments;
		
		OrderedMesh *om = static_cast<OrderedMesh*> (m);
		OrderedMesh::zMinTriangleMap ordTriangleMap = om->ordTriangleMap;
		
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
		
		timeEnd = Timer::getTimeMs();
		this->incSliceTime(timeEnd- timeIni);
		
        while (zMin < zMax)
        {
			timeIni = Timer::getTimeMs();
			std::map<std::string, Rect*> segments;
			
			int adjZ = floor(zMin*10000);
			
			for (OrderedMesh::zMinTriangleMap::iterator i = ordTriangleMap.begin(), iend = ordTriangleMap.end(); (i != iend && (*i).first <= adjZ); i++)
			{
				OrderedMesh::zMaxTriangleMap &innerMap = (*i).second;
				for (OrderedMesh::zMaxTriangleMap::reverse_iterator j = innerMap.rbegin(), jend = innerMap.rend(); (j != jend && (*j).first >= adjZ); j++)
				{
					OrderedMesh::tVector &vTriang = (*j).second;
					SimpleTriangle *t;
					for (int k = 0; k < vTriang.size(); k++)
					{
						t = static_cast<SimpleTriangle*>(vTriang[k]);
						m->incSliceCounter();
						if (t->checkInterception(zMin)) {
							m->incIfCounter();
							Rect *l = t->intercept(zMin);
							Point *p1 = static_cast<Point*> (l->getGeometry(0));
							std::string label = p1->getLabel();
							segments[label] = l;
						}
					}
				}
			}
			
            zMin += sliceThickness;
			
			timeEnd = Timer::getTimeMs();
			this->incSliceTime(timeEnd - timeIni);
            if (!segments.empty())
				s->addGeometry(this->getSlice(segments));
			
        }
        
        s->setInterface(new Graphics(static_cast<GraphicsImp*>(new OpenGLImp())));
		
        return s;
    }
}

