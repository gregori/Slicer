/*
 *  MeshSlicer.h
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 30/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "Solid.h"
#include "Slicer.h"
#include "Mesh.h"

namespace ProcessPlanning
{
    class MeshSlicer :
	public  Slicer
    {
    private:
        float sliceThickness;
		
    public:
        MeshSlicer(void);
        ~MeshSlicer(void);
		
        float getSliceThickness(void) const;
        void setSliceThickness(const float st);
		
        Solid* sliceMesh(Mesh* m);
		
    };
}