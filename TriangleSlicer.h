/*
 *  TriangleSlicer.h
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 22/09/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "Slicer.h"
#include <map>

namespace ProcessPlanning {
	class TriangleSlicer : public Slicer
	{
    public:
		TriangleSlicer();
		virtual ~TriangleSlicer();
		
		Solid* sliceMesh(Mesh* m);
	};
}

