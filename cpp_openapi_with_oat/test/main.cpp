#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "big_example/version.h"

TEST_CASE( "hello_world", "[hello]" ) {
    std::cout << "big_example "<< big_example::VERSION << " " << big_example::VERSION_SHORT << " unittests\n";
    REQUIRE( true );
}
