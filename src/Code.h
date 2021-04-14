#pragma once

#include <string>
#include <vector>

#include "utility.h"

class Code {
public:
	Code();
	Code(std::string);
	Code(std::vector<int>);
	~Code();

	std::vector<int> compare(Code other);

	std::vector<int> code_;
};