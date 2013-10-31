/*
 *  TataSlicer.h
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 29/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "Mesh.h"
#include "Slicer.h"

namespace ProcessPlanning 
{
	class TataSlicer : public Slicer
	{
    public:
		TataSlicer();
		virtual ~TataSlicer();
		
		Solid* sliceMesh(Mesh* m);
	};	
}
