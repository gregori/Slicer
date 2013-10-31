/*
 *  YangEdge.h
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 10/09/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */
#pragma once

#include "Rect.h"
#include "YangFacet.h"
#include <vector>

namespace ProcessPlanning 
{
	class YangEdge : public Rect
	{
	private:
		std::vector<YangFacet*> facets;
	};
}
