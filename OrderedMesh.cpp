/*
 * =====================================================================================
 *
 *       Filename:  OrderedMesh.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/23/2012 06:40:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (rhg), rodrigo.gregori@gmail.com
 *        Company:  Universidade Tenológica Federal do Paraná
 *
 * =====================================================================================
 */
#include "OrderedMesh.h"
#include "SimpleTriangle.h"
#include <math.h>
#include <iostream>

using namespace std;

namespace ProcessPlanning
{
    OrderedMesh::OrderedMesh()
    {
    }

    OrderedMesh::~OrderedMesh()
    {
    }

    void OrderedMesh::orderedInsertTriangle(Facet* t)
    {
        int zMin, zMax;

        zMin = floor(t->getZMin()*10000);
        zMax = floor(t->getZMax()*10000);

        if (!ordTriangleMap[zMin][zMax].empty())
        {
            (ordTriangleMap[zMin][zMax]).push_back(t);        
        }
        else
        {
            tVector tmp;
            tmp.push_back(t);
            ordTriangleMap[zMin][zMax] = tmp;
        }
    }

    Slice* OrderedMesh::interceptTriangles(float z)
    {
        int adjZ = floor(z*10000);

        for (zMinTriangleMap::iterator i = ordTriangleMap.begin(), iend = ordTriangleMap.end(); (i != iend && (*i).first <= adjZ); i++)
        {
            zMaxTriangleMap &innerMap = (*i).second;
            for (zMaxTriangleMap::reverse_iterator j = innerMap.rbegin(), jend = innerMap.rend(); (j != jend && (*j).first >= adjZ); j++)
            {
                tVector &vTriang = (*j).second;
                SimpleTriangle *t;
                for (int k = 0; k < vTriang.size(); k++)
                {
                    t = static_cast<SimpleTriangle*>(vTriang[k]);
					ifCounter++;
                    if (t->checkInterception(z)) {
						
                        Rect *l = t->intercept(z);
						Point *p1 = static_cast<Point*> (l->getGeometry(0));
						std::string label = p1->getLabel();
						segments[label] = l;
                    }
                }
            }
        }
		
        
		return this->getSlice();
		//return NULL;
		
    }
}

