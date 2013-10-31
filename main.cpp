/* 
 * File:   main.cpp
 * Author: rodrigo
 *
 * Created on 28 de Maio de 2013, 22:24
 */

#include <cstdlib>
#include <string>
#include <unistd.h>
#include <vector>
#include "ProcessController.h"
#include "Solid.h"
#include "Mesh.h"
#include "NewSlicerGLUTOO.h"
#include "Timer.h"
#include "ASCIIFileImp.h"
#include "OpenGLImp.h"
#include "GraphicsImp.h"
#include "Graphics.h"
#include "PointFactory.h"
#include "Slicer.h"
#include "SimpleSlicer.h"
#include "SetSlicer.h"
#include "TriangleSlicer.h"
#include "CSVWriter.h"
#include "TataSlicer.h"
#include "MeshSlicer.h"

using namespace std;
using namespace glutFramework;

/*
 * 
 */
int main(int argc, char** argv) 
{
    string fileName, times, log, alg;
    int t, parseType;
	GraphicsImp* grImp;
	Graphics* gr;
    ProcessController pCtrl;
	Slicer* sl;
	bool aflg, oflg, sflg, tflg, nflg, lflg, errflg = false;
	int option;
	
	while ((option = getopt(argc, argv, "aostlnf:")) != -1) {
		switch (option) {
			case 'a':
				if (oflg) {
					errflg = true;
				} else {
					aflg = true;
					grImp = new ASCIIFileImp();
				}
				break;
			case 'o':
				if (aflg) {
					errflg = true;
				} else {
					oflg = true;
					grImp = new OpenGLImp();
				}
				break;
			case 's':
				if (tflg || nflg || lflg) {
					errflg = true;
				} else {
					sflg = true;
					parseType = 0;
					sl = static_cast<Slicer*>(new SimpleSlicer());
					//sl = static_cast<Slicer*>(new MeshSlicer());
					alg = "Trivial";
					//cout << "Using Simple Mesh and Slicing" << endl;
				}
				break;
			case 't':
				if (sflg || nflg || lflg) {
					errflg = true;
				} else {
					tflg = true;
					parseType = 1;
					alg = "Tata";
					sl = static_cast<Slicer*>(new TataSlicer());
					//sl = static_cast<Slicer*>(new MeshSlicer());
					//cout << "Using " << endl;
				}
				break;
			case 'n':
				if (sflg || tflg || lflg) {
					errflg = true;
				} else {
					nflg = true;
					parseType = 0;
					sl = static_cast<Slicer*>(new TriangleSlicer());
					alg = "Triangle Slicing";
					//cout << "Using Simple Mesh and Triangle Slicing" << endl;
				}
				break;
			case 'l':
				if (sflg || tflg || nflg) {
					errflg = true;
				} else {
					lflg = true;
					parseType = 0;
					sl = static_cast<Slicer*>(new SetSlicer());
					alg = "Set Slicing";
					//cout << "Using Simple Mesh and Set Slicing" << endl;
				}
				break;
			case 'f':
				fileName = optarg;
				cout << "Slicing file " << fileName << endl;
				break;
				
			case '?':
				cerr << "usage: " << argv[0] << " [ao] [stnl] [f<stl file>]" << endl;
				break;
		}
	}
	
	if (errflg) {
		cerr << "usage: " << argv[0] << " [ao] [stnl] [f<stl file>]" << endl;
	}
	else {
		cout << "Using algorithm " << alg << endl;
	}


//    times = argv[1]; 
	/* if (argc > 1) {
		option = argv[1];
	} else { 
		option = "-s";
	}
	 */			
//    log = argv[3];
	/* if (argc > 2) {
		fileName = argv[2];
	} else {
		fileName = "/Users/rodrigo/Projetos/MeshSlicing/STL Files/cube.stl";
	}

	//    t = atoi(times.c_str());
	if (option.compare("-s") == 0) {
		parseType = 0;
		cout << "Using Simple Mesh and Slicing" << endl;
	} else if (option.compare("-t") == 0) {
		parseType = 1;	
		cout << "Using Ordered Mesh and Slicing" << endl;
	}
	 */
	gr = new Graphics(grImp);
	PointFactory::setGraphics(gr);
	
	int timeIni, timeEnd;
	std::vector<std::string> resVector;
	CSVWriter csv("results.csv");
	
	if (csv.isEmptyFile())
	{
		vector<string> header;
		header.push_back("File Name");
		header.push_back("Parse Time");
		header.push_back("Slice Time");
		header.push_back("Contour Time");
		header.push_back("Exec. Time");
		header.push_back("Num. Facets");
		header.push_back("Avg. Facet Height");
		header.push_back("Num. Slicer Exec.");
		header.push_back("Times Sliced");
		header.push_back("Num. Slices");
		header.push_back("Algorithm");
		csv.writeLine(header);
	}
	
	// Get filename only
	std::string filename;
	
	size_t pos = fileName.find_last_of("/");
	if(pos != std::string::npos)
		filename.assign(fileName.begin() + pos + 1, fileName.end());
	else
		filename = fileName;
	
	resVector.push_back(filename);
	
	// Parse file
	timeIni = Timer::getTimeMs();
	
    pCtrl.parseSTLFromFile(fileName, parseType, gr);
	
	timeEnd = Timer::getTimeMs();
	
	int parseTime = timeEnd - timeIni;
	cout << "Parse execution time: " << parseTime << "ms" << endl;
	resVector.push_back(SSTR(parseTime));
	
	// Slice Mesh
    pCtrl.setSlicer(sl);
	
	timeIni = Timer::getTimeMs();
	pCtrl.sliceMesh();	
	timeEnd = Timer::getTimeMs();
	
	Mesh *m = pCtrl.getMesh();
	
	//int sliceTime = timeEnd - timeIni;
	int sliceTime = sl->getSliceTime();
	cout << "Slice execution time: " << sliceTime << "ms" << endl;
	resVector.push_back(SSTR(sliceTime));
	
	int contourTime = sl->getSegmentTime();
	cout << "Contour execution time: " << contourTime << "ms" << endl;
	resVector.push_back(SSTR(contourTime));
	
	int execTime = parseTime + sliceTime + contourTime;
	cout << "Total execution time: " << execTime << "ms" << endl;
	resVector.push_back(SSTR(execTime));
	
	
	cout << "Number of Triangles: " << m->getSize() << endl;
	resVector.push_back(SSTR(m->getSize()));
	
	float avgFacetHeight = m->getAvgFacetHeight();
	
	cout << "Avg. Triangle 'height': " << avgFacetHeight << endl;
	resVector.push_back(SSTR(avgFacetHeight));
	
	cout << "Times for Slicer Execution:" << m->getSliceCounter() << endl;
	resVector.push_back(SSTR(m->getSliceCounter()));
	
	cout << "Actual slicing times:" << m->getIfCounter() << endl;
	resVector.push_back(SSTR(m->getIfCounter()));

    Solid *s = pCtrl.getSolid();
	cout << "Number of slices: " << s->getSize() << endl;
	resVector.push_back(SSTR(s->getSize()));
	resVector.push_back(alg);
	
	csv.writeLine(resVector);
	
    //s->render();
	
	//NewSlicerGLUTOO n;
	//n.setGeometry(static_cast<Geometry*>(m));
	
	//n.startFramework(argc, argv);
	
    
    return 0;
}

