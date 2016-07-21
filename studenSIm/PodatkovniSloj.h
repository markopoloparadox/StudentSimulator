#pragma once
#include "json.h"

class PodatkovniSloj {
public:
	PodatkovniSloj();
	~PodatkovniSloj();
	static nlohmann::json dohvatiVrijednostDat(std::string);
	static void upisiULog(std::string) noexcept;
};

