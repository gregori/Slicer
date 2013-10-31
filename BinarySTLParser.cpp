/*
 * =====================================================================================
 *
 *       Filename:  BinarySTLParser.cpp
 *
 *    Description:  Implementation for Binary Parser
 *
 *        Version:  1.0
 *        Created:  11/06/2012 09:01:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (rhg), rodrigo.gregori@gmail.com
 *        Company:  Universidade Tenológica Federal do Paraná
 *
 * =====================================================================================
 */

#include "BinarySTLParser.h"
#include "PointFactory.h"
#include "SimpleTriangle.h"

namespace ProcessPlanning
{
    BinarySTLParser::BinarySTLParser(void)
    {
        parsedMesh = static_cast<Mesh*>(new TraditionalMesh());
    }

    BinarySTLParser::~BinarySTLParser(void)
    {
        delete parsedMesh;
    }

    BinarySTLParser::BinarySTLParser(Mesh* m, int type)
    {
        parsedMesh = m;
        triangleType = type;
    }

    Mesh* BinarySTLParser::parseFile(void)
    {
        char header[80];
        char* bCount;

        long triangleCount = 0;

        Point* p;
        Facet* t;
        Mesh* m = parsedMesh;

        string fn = getFileName();
        ifstream input(fn.c_str(), ios::in|ios::binary);

        if(input.is_open())
        {
            input.read(header, 80);
            input.read((char*) &triangleCount, 4);

            cout << triangleCount << " Triangles." << endl;

            while (triangleCount > 0)
            {
                switch (triangleType)
                {
                    case 0: // Simple triangle
                        t = static_cast<Facet*>(new SimpleTriangle());
                        break;
//                    case 1:
 //                       t = static_cast<Facet*>(new NOPTriangle());
  //                      break;
                }

                t->setVector(getNormal(input));
                
                for (int i = 0; i < 3; i++)
                {
                    p = getVertex(input);
                    t->addVertex(p);
                    
                    if (p->getZ() < t->getZMin()) t->setZMin(p->getZ());
                    if (p->getZ() > t->getZMax()) t->setZMax(p->getZ());

                    p = NULL;
                }

                m->addTriangle(t);

	            if (t->getZMin() < m->getZMin()) m->setZMin(t->getZMin());
                if (t->getZMax() > m->getZMax()) m->setZMax(t->getZMax());
 			
                t = NULL;
                
                bCount = new char[2];

                input.read(bCount, 2);

                triangleCount--;
               // cout << triangleCount << " Triangles to go." << endl;
            }

            input.close();
            cout << "Read finished." << endl;
        }
    }

    Point* BinarySTLParser::getVertex(ifstream &input)
    {
        float x, y, z;
        Point* p;

        input.read((char*) &x, 4);
        input.read((char*) &y, 4);
        input.read((char*) &z, 4);

		p = PointFactory::getPoint(x, y, z);
        
        return p;
    }

    Vector* BinarySTLParser::getNormal(ifstream &input)
    {
        float x, y, z;
        Vector* v;

        input.read((char*) &x, 4);
        input.read((char*) &y, 4);
        input.read((char*) &z, 4);

        v = new Vector(x, y, z);

        return v;
    }
}
