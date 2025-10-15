#pragma once

#include <random>

namespace RandomUtils {

	class Random {
	public:
		template<typename T>
		static T get(T from, T to) {
			static thread_local std::mt19937 generator(std::random_device{}());

			if constexpr (std::is_integral<T>::value) {
				std::uniform_int_distribution<T> dist(from, to);
				return dist(generator);
			}
			else if constexpr (std::is_floating_point<T>::value) {
				std::uniform_real_distribution<T> dist(from, to);
				return dist(generator);
			}
		}
	};
}
