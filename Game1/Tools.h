#pragma once

// STL and useful mathematical tools

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>  // system �Լ�
#include "conio.h"
#include <windows.h>
#include <random>
#include <unordered_map>

using namespace std;

#define MAX_Y 3
#define MAX_X 4

struct Position {
	int y, x;

	Position() : y(0), x(0) {}
	Position(int y, int x) : y(y), x(x) {}
};
