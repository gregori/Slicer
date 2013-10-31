/*
 *  SetSlicer.h
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 19/09/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "Slicer.h"
#include <map>

namespace ProcessPlanning 
{
	class SetSlicer : public Slicer
	{
    public:
		SetSlicer();
		virtual ~SetSlicer();
		
		Solid* sliceMesh(Mesh *m);
	};
	
}
