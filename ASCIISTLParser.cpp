#include <boost/algorithm/string.hpp>
#include <fstream>
#include <boost/regex.hpp>
#include "PointFactory.h"
#include "ASCIISTLParser.h"
#include "SimpleTriangle.h"
#include "OpenGLImp.h"

using namespace std;
using namespace boost;

namespace ProcessPlanning
{
	ASCIISTLParser::ASCIISTLParser(void)
	{
        parsedMesh = static_cast<Mesh*>(new TraditionalMesh());
	}

	ASCIISTLParser::ASCIISTLParser(Mesh* m, int type)
	{
        parsedMesh = m;
        triangleType = type;
	}

	ASCIISTLParser::~ASCIISTLParser(void)
	{
        delete parsedMesh;
        parsedMesh = NULL;
	}

    void ASCIISTLParser::setMesh(Mesh* m)
    {
        parsedMesh = m;
    }

	Vector* ASCIISTLParser::getNormal(std::string line)
	{
		regex rNormal("facet normal +([-+]?[0-9]*.?[0-9]+([eE][-+]?[0-9]+)?) +([-+]?[0-9]*.?[0-9]+([eE][-+]?[0-9]+)?) +([-+]?[0-9]*.?[0-9]+([eE][-+]?[0-9]+)?)");
        //boost::match_results<std::string::const_iterator> content;
		cmatch content;
        Vector* v;

        if (regex_match(line.c_str(), content, rNormal))
        {
			v = new Vector(atof(content[1].str().c_str()), atof(content[3].str().c_str()), atof(content[5].str().c_str()));
			return v;
		}
        
		return NULL;
	}

	Point* ASCIISTLParser::getVertex(std::string line)
	{
		regex rVertex("vertex +([-+]?[0-9]*.?[0-9]+([eE][-+]?[0-9]+)?) +([-+]?[0-9]*.?[0-9]+([eE][-+]?[0-9]+)?) +([-+]?[0-9]*.?[0-9]+([eE][-+]?[0-9]+)?)");
        //boost::match_results<std::string::const_iterator> content;
		cmatch content;
        Point* p;

		if (regex_match(line.c_str(), content, rVertex))
        {   // TODO: need to use the PointFactory
			p = PointFactory::getPoint(atof(content[1].str().c_str()), atof(content[3].str().c_str()), atof(content[5].str().c_str()));
			return p;
		}
		return NULL;
	}

	Mesh* ASCIISTLParser::parseFile(void)
	{
		std::string fn = getFileName(); // STL filename
		std::string line;
        Facet* t;
        Point* p;
        int triangleCount = 0;
		Mesh* m = parsedMesh;
		m->setInterface(getGraphics());

		ifstream input(fn.c_str());
        while (getline(input, line))
        {
            trim(line);
			if (find_first(line, "endfacet"))
			{
                triangleCount++;
			}
            else if (find_first(line, "facet")) // we have the normal vector data
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

				t->setInterface(getGraphics());
                t->setVector(getNormal(line));
            }
            else if (find_first(line, "vertex")) // we have vertex data
            {
                p = getVertex(line);
                t->addVertex(p);
                if (p->getZ() < t->getZMin()) t->setZMin(p->getZ());
                if (p->getZ() > t->getZMax()) t->setZMax(p->getZ());

                p = NULL;
            }
            else if (find_first(line, "endloop"))
            {
                m->addTriangle(t);
	            if (t->getZMin() < m->getZMin()) m->setZMin(t->getZMin());
                if (t->getZMax() > m->getZMax()) m->setZMax(t->getZMax());
 			
                t = NULL;
            }
        }
//        cout << triangleCount << " Triangles." << endl;

		m->setSphereCenter();
		m->setSphereRadius();
		
		return m;
	}

	bool ASCIISTLParser::checkSTLFile(void) const
	{
		string fn = getFileName(); // STL filename

		ifstream input;

		input.open(fn.c_str());  // trying to read the file

		if (!input)
		{
			throw "Could not open STL file!";
		}

		// TODO: Better checking

		input.close();

		return true;
	}

    bool ASCIISTLParser::checkASCIIFile(string fileName)
    {
        string line1, line2;
        ifstream input;

        input.open(fileName.c_str());

        getline(input, line1);
        getline(input, line2);

        return (find_first(line1, "solid") && find_first(line2, "facet"));
    }


}

