/*
 *  CSVWriter.cpp
 *  NewSlicer
 *
 *  Created by Rodrigo Habib Gregori on 27/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "CSVWriter.h"
#include <sstream>
#include <iostream>

CSVWriter::CSVWriter()
{

}

CSVWriter::~CSVWriter()
{
	if (csvFile.is_open()) 
	{
		csvFile.close();
	}
}

CSVWriter::CSVWriter(std::string fileName)
{
	this->fileName = fileName;
	csvFile.open(fileName.c_str(), std::ios::out | std::ios::app);
}

bool CSVWriter::fileExists(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (file.good())
	{
		file.close();
		return true;
	}
	
	file.close();
	return false;
}

bool CSVWriter::fileExists()
{
	return CSVWriter::fileExists(this->fileName);
}

void CSVWriter::writeLine(std::vector<std::string> lineContent)
{
	if (csvFile.is_open())
	{
		std::string line = this->joinVector(lineContent);
		csvFile << line << std::endl;
	}
	else {
		std::cerr << "File is not open!" << std::endl;
	}

}

std::string CSVWriter::joinVector(std::vector<std::string> strVector)
{
	std::stringstream ss;
	for(size_t i = 0; i < strVector.size(); ++i)
	{
		if(i != 0)
			ss << ",";
		ss << strVector[i];
	}
	return ss.str();
}

bool CSVWriter::isEmptyFile()
{
	std::ifstream pFile(fileName.c_str());
	bool isEmpty = pFile.peek() == std::ifstream::traits_type::eof();
	pFile.close();
	return isEmpty;
}
