#include <iostream>
#include <fmt/core.h>
#include "helloworld/hello.hpp"

int main()
{
	fmt::print("Greetings stranger. Or should I say: {}", hello::greetings());
}
