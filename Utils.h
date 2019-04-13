#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cstdarg>
#include <initializer_list>
#include <exception>
#include <any>
#include <memory>
#include "Enum.h"

#define interface class
#define abstract

using Object = std::any;
using String = std::string;
using File = std::ifstream;
using Exception = std::exception;
template <typename T> using Array = std::vector<T>;
template <typename K, typename V> using Map = std::map<K, V>;
template <typename K, typename V> using Pair = std::pair<K, V>;

String objectToString(const Object& any);

#endif