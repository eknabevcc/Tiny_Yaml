#include "1.hpp"    // Tests yaml variables
#include "2.hpp"    // Test yaml objects
#include "3.hpp"    // Test yaml lists
#include "4.hpp"    // Test yaml object lists
#include "5.hpp"    // Test yaml nested complex object
#include "6.hpp"    // Test missing child nodes


int main(int argc, char** argv) {
    bool passed = true;

    passed &= TINY_YAML::tests::test_1_variables();
    passed &= TINY_YAML::tests::test_2_basic_object();
    passed &= TINY_YAML::tests::test_3_basic_list();
    passed &= TINY_YAML::tests::test_4_basic_object_list();
    passed &= TINY_YAML::tests::test_5_complex_nested_object();
    passed &= TINY_YAML::tests::test_6_missing_child_nodes();

    printf("%s\n", passed ? "All tests PASSED" : "At least one test FAILED");

    return passed ? 0 : -1;
}