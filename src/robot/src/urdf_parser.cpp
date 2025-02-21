#include "robot/urdf_parser.hpp"
#include <iostream>

bool URDFParser::parseURDF(const std::string &urdf_path)
{
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(urdf_path.c_str()) != tinyxml2::XML_SUCCESS) {
        std::cerr << "Failed to load URDF file: " << urdf_path << std::endl;
        return false;
    }
    
    tinyxml2::XMLElement *robotElement = doc.FirstChildElement("robot");
    if (!robotElement) {
        std::cerr << "No <robot> tag found in URDF file" << std::endl;
        return false;
    }

    std::cout << "Successfully loaded URDF for robot: " << robotElement->Attribute("name") << std::endl;
    return true;
}
