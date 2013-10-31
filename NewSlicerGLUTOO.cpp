/*
 *  NewSlicerGLUTOO.cpp
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 29/08/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "NewSlicerGLUTOO.h"

namespace glutFramework {
	NewSlicerGLUTOO::NewSlicerGLUTOO()
	{
		geom = NULL;
		title = "New Slicer";
	}
	
	NewSlicerGLUTOO::~NewSlicerGLUTOO()
	{
	}
	
	void NewSlicerGLUTOO::setGeometry(ProcessPlanning::Geometry* g)
	{
		geom = g;
	}
	
	void NewSlicerGLUTOO::load()
	{
	}
	
	void NewSlicerGLUTOO::display(float dTime)
	{
		//std::cout << "Displaying something ..." << std::endl;
		if (geom != NULL)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			geom->render();
		}
	}
}