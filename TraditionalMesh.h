/*
 * =====================================================================================
 *
 *       Filename:  TraditionalMesh.h
 *
 *    Description:  Header File for the traditional mesh
 *
 *        Version:  1.0
 *        Created:  11/04/2012 09:56:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (rhg), rodrigo.gregori@gmail.com
 *        Company:  Universidade Tenológica Federal do Paraná
 *
 * =====================================================================================
 */
#pragma once
#include "Mesh.h"
#include "Facet.h"
#include <map>
#include "Slice.h"

namespace ProcessPlanning
{
    class TraditionalMesh : public Mesh
    {
        public:
            TraditionalMesh();
            ~TraditionalMesh();
            virtual void orderedInsertTriangle(Facet *t);
            virtual Slice* interceptTriangles(float z);
    };
}
