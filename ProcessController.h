/*
 * =====================================================================================
 *
 *       Filename:  ProcessController.h
 *
 *    Description:  Controller class for the process planning
 *
 *        Version:  1.0
 *        Created:  08/05/2012 10:26:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (), rodrigo.gregori@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once
#include "STLParser.h"
#include "ASCIISTLParser.h"
#include "BinarySTLParser.h"
#include "Mesh.h"
#include "TraditionalMesh.h"
#include "OrderedMesh.h"
#include "Solid.h"
#include <string>
//#include "RasterCalculator.h" //TODO: not sure whether using raster
//#include "OffsetCalculator.h" //TODO: not sure whether using offset calculator
#include "Slicer.h"
#include "SimpleSlicer.h"
#include "Graphics.h"

using namespace std;
namespace ProcessPlanning
{
    class ProcessController
    {
    private:
		Mesh* mesh;
		Solid* solid;
        STLParser *stlParser;
        Slicer *slicer;

    public:
        ProcessController(void);
        ~ProcessController(void);

        void setSTLParser(STLParser *stlParser);
        void setSlicer(Slicer *meshSlicer);
		void parseSTLFromFile(string fileName, int parserType, Graphics* gr);
        void sliceMesh(void);
		Mesh* getMesh(void) const;
        Solid* getSolid(void) const;
        int getMeshIfCounter();
    };
}
