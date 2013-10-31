/*
 * =====================================================================================
 *
 *       Filename:  SimpleSlicer.h
 *
 *    Description:  Simple Slicer class
 *
 *        Version:  1.0
 *        Created:  08/05/2012 08:36:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (), rodrigo.gregori@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#pragma once
#include "Solid.h"
#include "Slicer.h"
#include "Mesh.h"

namespace ProcessPlanning
{
    class SimpleSlicer :
        public  Slicer
    {

    public:
        SimpleSlicer(void);
        ~SimpleSlicer(void);

        Solid* sliceMesh(Mesh* m);

    };
}
