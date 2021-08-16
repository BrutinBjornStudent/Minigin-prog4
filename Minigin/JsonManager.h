#pragma once
#include "Singleton.h"
#include <nlohmann/json.hpp>

class JsonManager final : public dae::Singleton<JsonManager>
{
public:
	void Init(const std::string& Data);
	nlohmann::json LoadJsonDoc(const std::string& file);
private:
	friend class Singleton< JsonManager>;
	JsonManager() = default;
	std::string m_DataPath;
};

