#include "jsonExtend.h"
#include <sstream>
std::string pretvoriUString(nlohmann::json vri) {
	if (vri.is_string()) {
		return vri;
	}
	if (vri.is_number()) {
		return std::to_string(vri.get<int>());
	}

	if (vri.is_number_unsigned()) {
		return std::to_string(vri.get<unsigned int>());
	}

	if (vri.is_boolean()) {
		std::stringstream converter;
		converter << vri;
		return converter.str();
	}

	return "error";
}

bool pretvoriUBool(std::string vri) {
	if (vri == "true")
		return true;

	return false;
}

unsigned int pretvoriUUInt(std::string vri) {
	return std::stoul(vri);
}
