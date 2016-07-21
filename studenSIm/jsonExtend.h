#pragma once
#include "json.h"

std::string pretvoriUString(nlohmann::json vri) {
	if (vri.is_string()) {
		return vri;
	}
	if (vri.is_number()) {
		return std::to_string(vri.get<int>());
	}
	return "error";
}