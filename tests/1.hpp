/**
 * @file 1.hpp
 * @author Mohammed Ghaith Al-Mahdawi (Mohido)
 * @brief Tests basic YAML variables processing.
 */

#include <iostream>
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

    bool test_1_variables(){
        int passed = 0;
        int total = 0;
        std::cout << "############# TESTGROUP: test_variables" << std::endl;
        try{
            Yaml yamlFile( dirpath() + std::string("/1.yaml"));

            total++; passed += assert(yamlFile["version"].getData<std::string>(), std::string("1.2.3"));
            total++; passed += assert(yamlFile["name"].getData<std::string>(), std::string("\"tiny yaml\""));
            total++; passed += assert(yamlFile["age"].getData<std::string>(), std::string("123"));
            total++; passed += assert(yamlFile["alive"].getData<std::string>(), std::string("true"));
            total++; passed += assert(yamlFile["complex_text"].getData<std::string>(), std::string("\"-1234he-\""));
            total++; passed += assert(yamlFile["comment_text"].getData<std::string>(), std::string("\"this is how to write a # comment\""));
            total++; passed += assert(yamlFile["var_comm"].getData<std::string>(), std::string("\"Some text\""));
            total++; passed += assert(yamlFile["special_text"].getData<std::string>(), std::string("\"Some#text\""));
            total++; passed += assert(yamlFile["quotation_marks_not_needed"].getData<std::string>(), std::string("should_be-ok"));
            total++; passed += assert(yamlFile["mixed_string_space_numbers"].getData<std::string>(), std::string("this-is 100_ok"));
            total++; passed += assert(yamlFile["duplicate_key"].getData<std::string>(), std::string("first_value"));
            total++; passed += assert(static_cast<int>(yamlFile["parent-label"].getSize()), 2);  // two children nodes
            total++; passed += assert(yamlFile["parent-label"]["window"].getData<std::string>(), std::string("60 60 800 400"));
            total++; passed += assert(yamlFile["parent-label"]["child_with_dash"].getData<std::string>(), std::string("this-is also 100_ok"));

            // test GetNodes() method
            total++;
            for (auto& it : yamlFile.getNodes()) {  // GetNodes() method returns a map of all nodes in the yaml file
                if (it.first == "quotation_marks_not_needed")
                {
                    passed += assert(it.second->getData<std::string>(), std::string("should_be-ok"));
                    break;
                }
            }
            // also check getID() method
            total++; passed += assert(yamlFile["var_comm"].getID(), std::string("var_comm"));

            // test missing key
            try {
                std::string value = yamlFile["dont_exist"].getData<std::string>();
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                total++; passed++;  // value does not exist, exception is expected
            }

        }catch(const std::exception& e){
            std::cerr << e.what() << std::endl;
            return false;
        }
        std::cout << "-- TESTGROUP test_variables RESULT: " << passed << " passed out of " << total << std::endl;
        std::cout << "############################" << std::endl;
        return total == passed;
    }

}}