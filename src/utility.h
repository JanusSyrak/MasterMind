#ifndef UTILITY_H_
#define UTILITY_H_

#include <algorithm>
#include <vector>

namespace utility {

	inline int char_to_int(char c) {
		return c - '0';
	}

	inline std::vector<int> to_vector(std::string s) {
		std::vector<int> result;
		for (int i = 0; i < s.size(); i++) {
			result.push_back(utility::char_to_int(s[i]));
		}
		return result;
	}

	inline void shuffle_vector(std::vector<int>& v) {
		std::random_shuffle(std::begin(v), std::end(v));
	}


	inline int sum(std::vector<int>& v) {
		int res = 0;
		for (auto& n : v) {
			res += n;
		}
		return res;
	}

}

#endif // UTILITY_H
