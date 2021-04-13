#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "helloworld/hello.hpp"

TEST_CASE("Greetings are correct", "[hello::greetings]")
{
	REQUIRE(hello::greetings() == "Hello world!");
}
