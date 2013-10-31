/*
 * =====================================================================================
 *
 *       Filename:  BinarySTLParser.h
 *
 *    Description:  Header file for the binary parser
 *
 *        Version:  1.0
 *        Created:  11/05/2012 06:23:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (rhg), rodrigo.gregori@gmail.com
 *        Company:  Universidade Tenológica Federal do Paraná
 *
 * =====================================================================================
 */

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "STLParser.h"
#include "Mesh.h"
#include "TraditionalMesh.h"
#include "Facet.h"

using namespace std;

namespace ProcessPlanning
{
    class BinarySTLParser : public STLParser
    {
        private:
            Mesh* parsedMesh;
            int triangleType;
            bool checkSTLFile(void) const;
            Vector* getNormal(ifstream &input);
            Point* getVertex(ifstream &input);
        
        public:
            BinarySTLParser(void);
            BinarySTLParser(Mesh* m, int type);
            ~BinarySTLParser();
            Mesh* parseFile(void);
            void setMesh(Mesh* m);
    };
}
