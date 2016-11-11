#include "stdafx.h"
#include <ams/fileutils.h>


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::map<std::string, int> adjmap;
		std::string filename = argv[1];
		ams::LineReader(filename, [&](std::string s) {
			if (s.length() > 3 && s[0] != '/')
			{
				std::string crs = s.substr(0, 3);
				adjmap[crs]++;
			}
		}).Read();

		for (auto p : adjmap)
		{
			if (p.second > 2)
			{
				std::cout << p.first << std::endl;
			}
		}
	}
	else
	{
		std::cerr << "You must supply a filename\n";
	}
}
