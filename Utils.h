#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Enum.h"

#define interface class
#define abstract

using String = std::string;
using File = std::ifstream;
template <typename T> using Array = std::vector<T>;
template <typename K, typename V> using Map = std::map<K, V>;
template <typename K, typename V> using Pair = std::pair<K, V>;

#endif