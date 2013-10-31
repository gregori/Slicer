#pragma once

#include <string>
#include "Vector.h"
#include "Point.h"
#include "Mesh.h"
#include "TraditionalMesh.h"
#include "STLParser.h"

using namespace std;

namespace ProcessPlanning
{

	class ASCIISTLParser :
		public STLParser
	{
	private:
        Mesh* parsedMesh;
        int triangleType;

		bool checkSTLFile(void) const;
		Vector* getNormal(string line);
		Point* getVertex(string line);
	public:
		ASCIISTLParser(void);
		ASCIISTLParser(Mesh* m, int tType);
		~ASCIISTLParser(void);
        void setMesh(Mesh* m);
		Mesh* parseFile(void);
        static bool checkASCIIFile(string fileName);
	};

}
