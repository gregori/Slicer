/*
 * =====================================================================================
 *
 *       Filename:  OrderedMesh.h
 *
 *    Description:  A Mesh with a hash for ordering triangles
 *
 *        Version:  1.0
 *        Created:  10/22/2012 11:39:42 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (rhg), rodrigo.gregori@gmail.com
 *        Company:  Universidade Tenológica Federal do Paraná
 *
 * =====================================================================================
 */

#pragma once
#include <map>
#include <vector>
#include "Facet.h"
#include "Mesh.h"
#include "Slice.h"

using namespace std;

namespace ProcessPlanning
{
    class OrderedMesh : public Mesh
    {
    private:
                

    public:
		typedef vector<Facet*> tVector;
        typedef map<int, tVector> zMaxTriangleMap;
        typedef map<int, zMaxTriangleMap> zMinTriangleMap;
		
        OrderedMesh();
        ~OrderedMesh();
        virtual void orderedInsertTriangle(Facet *t);
        virtual Slice* interceptTriangles(float z);
		zMinTriangleMap ordTriangleMap;

	};
}
