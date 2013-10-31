#include "ProcessController.h"
#include "Graphics.h"
#include <string>

using namespace std;

namespace ProcessPlanning
{
	ProcessController::ProcessController(void)
	{
		mesh = NULL;
		solid = NULL;
		stlParser = NULL;
        slicer = NULL;
	}

	ProcessController::~ProcessController(void)
	{
		mesh = NULL;
		solid = NULL;
		stlParser = NULL;
        slicer = NULL;
	}

	void ProcessController::setSTLParser(STLParser *sp)
	{
		stlParser = sp;
	}

	void ProcessController::setSlicer(Slicer *meshSlicer)
	{
		slicer = meshSlicer;
	}

	void ProcessController::parseSTLFromFile(string fileName, int parserType, Graphics* gr)
	{
        int triangleType;

        //TODO: make this better
        switch (parserType)
        {
            case 0:
                mesh = new TraditionalMesh();
                triangleType = 0; 
                break;
            case 1:
                mesh = new OrderedMesh();
                triangleType = 0;
                break;
        }

        if (ASCIISTLParser::checkASCIIFile(fileName))
    		setSTLParser(static_cast<STLParser*>(new ASCIISTLParser(static_cast<Mesh*>(mesh), triangleType)));
        else
            setSTLParser(static_cast<STLParser*>(new BinarySTLParser(static_cast<Mesh*>(mesh), triangleType)));

		stlParser->setFileName(fileName);
		stlParser->setGraphics(gr);
		mesh = stlParser->parseFile();
	}

	Mesh* ProcessController::getMesh(void) const
	{
		return mesh;
	}

    Solid* ProcessController::getSolid(void) const
    {
        return solid;
    }

    void ProcessController::sliceMesh(void)
    {
        // :TODO: Slicer deve receber por parâmetro
        //setSlicer(static_cast<Slicer*>(new SimpleSlicer));
        solid = slicer->sliceMesh(mesh);
    }

    int ProcessController::getMeshIfCounter()
    {
        return mesh->getIfCounter();
    }
}
