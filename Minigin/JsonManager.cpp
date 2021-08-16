#include "MiniginPCH.h"
#include "JsonManager.h"

#include <fstream>

void JsonManager::Init(const std::string& Data)
{
	m_DataPath = Data;
}

nlohmann::json JsonManager::LoadJsonDoc(const std::string& file)
{
	const auto FullPath = m_DataPath + file;
	
	std::ifstream input(m_DataPath + file);
	if ((input.rdstate() & std::ifstream::failbit) != 0)
	{
		throw std::runtime_error(std::string("JSON File Not Found"));

	}
	
	nlohmann::json j;
	input >> j;
	std::cout << j.dump() << std::endl;
	return j;
}


// 2 waves from top, bees left, butterlfy right
// bottom left
//bottom right
//top to left
//top to right