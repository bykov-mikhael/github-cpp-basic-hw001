#include "cstr.hpp"

cstr::cstr() : _str{""} {}

cstr::cstr(std::string str) : _str{str} {}

cstr::~cstr() { ; }

void cstr::setValue(std::string str) { this->_str = str; }

std::string cstr::getValue() { return this->_str; }