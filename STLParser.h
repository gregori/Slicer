#pragma once
#include <string>
#include "Mesh.h"
#include "Graphics.h"

using namespace std;


namespace ProcessPlanning
{

	class STLParser //:
		//public Thread
	{
	private:
		string fileName;
		Mesh* stlMesh;
		Graphics* gr;
		
		//methods
		virtual bool checkSTLFile(void) { return false; };
		//void run();
	public:
		STLParser(const string fn="");
		virtual ~STLParser(void);
		virtual Mesh* parseFile(void) { return NULL; }
		void setFileName(string f);
		void setGraphics(Graphics* gr);
		Graphics* getGraphics(void) const;
		string getFileName(void) const;
		void setSTLMesh(Mesh* m);
		Mesh* getSTLMesh(void) const;
	};


}
