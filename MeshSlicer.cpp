/*
 *  MeshSlicer.cpp
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 30/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "MeshSlicer.h"
#include "Timer.h"
#include "GraphicsImp.h"
#include "OpenGLImp.h"
#include <iostream>

using namespace std;

namespace ProcessPlanning
{
    MeshSlicer::MeshSlicer(void)
    {
        sliceThickness = 0.152f;
    }
	
    MeshSlicer::~MeshSlicer(void)
    {
		
    }
	
    float MeshSlicer::getSliceThickness(void) const
    {
        return sliceThickness;
    }
	
    void MeshSlicer::setSliceThickness(const float st)
    {
        sliceThickness = st;
    }
	
    Solid* MeshSlicer::sliceMesh(Mesh* m)
    {
        float zMin, zMax;
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
		
        while (zMin < zMax - sliceThickness)
        {
            s->addGeometry(m->interceptTriangles(zMin));
			
            zMin += sliceThickness;
        }
        
        s->setInterface(new Graphics(static_cast<GraphicsImp*>(new OpenGLImp())));
		timeEnd = Timer::getTimeMs();
		this->incSliceTime(timeEnd - timeIni);
		
        // :TODO: We should actually create the contours here
        return s;
    }
}
