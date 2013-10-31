/*
 *  CSVWriter.h
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 27/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include <fstream>
#include <string>
#include <vector>

#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
	( std::ostringstream() << std::dec << x ) ).str()

class CSVWriter 
{
public:
    CSVWriter();
	CSVWriter(std::string fileName);
    virtual ~CSVWriter();
	
	void writeLine(std::vector<std::string> lineContent);
	static bool fileExists(std::string fileName);
	bool isEmptyFile();
	std::string joinVector(std::vector<std::string> strVector);
private:
	std::string fileName;
	std::ofstream csvFile;
	bool fileExists();
};
