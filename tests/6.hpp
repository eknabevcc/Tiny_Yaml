/**
 * @file 6.hpp
 * @author Emil Knabe (eknabevcc)
 * @brief Tests missing children nodes
 */

 #include <iostream>
 #include <vector>
 #include "../yaml/yaml.hpp"

 namespace TINY_YAML{
 namespace tests {

     #ifndef TINY_YAML_TESTS_HELPER_FUNCS
     #define TINY_YAML_TESTS_HELPER_FUNCS
         template<typename T>
         bool assert(T v1, T v2){
             bool result = v1 == v2;
             std::cout << "TEST: Value (" << v1 << ") Expected to be (" << v2 << ")? " << ((result)? "passed" : "failed") << std::endl;
             return result;
         }

         /// @brief - Mainly used in compile time to get the absolute path of .hpp/.cpp file parent directory
         /// @return - Directory absolutepath of the current file.
         std::string dirpath(){
             std::string hppfilepath(__FILE__);
             #if _WIN32
                 return hppfilepath.substr(0, hppfilepath.find_last_of("\\"));
             #else
                 return hppfilepath.substr(0, hppfilepath.find_last_of("/"));
             #endif
         }
     #endif

     bool test_6_missing_child_nodes() {
         int passed = 0;
         int total = 0;
         std::cout << "############# TESTGROUP: test_missing_child_nodes" << std::endl;
         try {
             Yaml yamlFile( dirpath() + std::string("/6.yaml"));
         } catch(const std::exception& e){
             std::string expect_str = "Parent node (final check) \"dummy_parent2\" missing children";
             total++; passed += (expect_str.compare(0, expect_str.length(), e.what(), 0, expect_str.length()) == 0);
         }
         std::cout << "-- TESTGROUP test_missing_child_nodes RESULT: " << passed << " passed out of " << total << std::endl;
         std::cout << "############################" << std::endl;
         return total == passed;
     }
 }}