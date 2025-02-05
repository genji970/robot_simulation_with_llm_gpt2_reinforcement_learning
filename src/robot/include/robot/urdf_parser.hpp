#ifndef ROBOT_URDF_PARSER_HPP
#define ROBOT_URDF_PARSER_HPP

#include <tinyxml2.h>
#include <string>

class URDFParser
{
public:
    static bool parseURDF(const std::string &urdf_path);
};

#endif
