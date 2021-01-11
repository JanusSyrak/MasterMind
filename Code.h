#ifndef CODE_H_
#define CODE_H_

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

#endif // CODE_H_