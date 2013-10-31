/*
 *  NewSlicerGLUTOO.h
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 29/08/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */
#pragma once

#include "GlutFramework.h"
#include "Geometry.h"

namespace glutFramework {
	class NewSlicerGLUTOO : public glutFramework::GlutFramework {
	private:
		ProcessPlanning::Geometry* geom;
	public:
		NewSlicerGLUTOO();
		virtual ~NewSlicerGLUTOO();
		
		void setGeometry(ProcessPlanning::Geometry* g);
		
		virtual void load();
		virtual void display(float dTime);
	};
}