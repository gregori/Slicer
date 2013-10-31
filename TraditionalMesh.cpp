/*
 * =====================================================================================
 *
 *       Filename:  TraditionalMesh.cpp
 *
 *    Description:  Source for the TraditionalMesh
 *
 *        Version:  1.0
 *        Created:  11/04/2012 09:56:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (rhg), rodrigo.gregori@gmail.com
 *        Company:  Universidade Tenológica Federal do Paraná
 *
 * =====================================================================================
 */

#include "TraditionalMesh.h"
#include "SimpleTriangle.h"
#include "Contour.h"
#include <iostream>

using namespace std;

namespace ProcessPlanning
{
    TraditionalMesh::TraditionalMesh()
    {
        ifCounter = 0;
    }

    TraditionalMesh::~TraditionalMesh()
    {
    } 

    void TraditionalMesh::orderedInsertTriangle(Facet *t)
    {
        // Do nothing in a traditional mesh
    }

    Slice* TraditionalMesh::interceptTriangles(float z)
    {
        SimpleTriangle *t;
                
        for(int i = 0; i < this->getSize(); i++)
        {
            t = static_cast<SimpleTriangle*>(this->getGeometry(i));
			if (t->checkInterception(z)) 
            {
				ifCounter++;
                Rect *l = t->intercept(z);
                Point *p1 = static_cast<Point*>(l->getGeometry(0));
                std::string label = p1->getLabel();
                segments[label] = l;
            }
        }
        
        //return NULL;
		return this->getSlice();
    }


}
