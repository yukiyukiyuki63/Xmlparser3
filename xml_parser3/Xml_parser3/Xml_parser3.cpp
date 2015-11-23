#include "session_info.h"
#include "general_info.h"
#include "gamecode_info.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>


using namespace boost::property_tree;
using namespace std;



int main()
{

	std::string Filename;
	std::cout << "ƒtƒ@ƒCƒ‹–¼“ü—Í\n";
	std::cin >> Filename;

	Session_info S_i;
	General_info G_i;
	Game_info Ga_i;

	S_i.Sessioncode(Filename);
	G_i.general_info(Filename);
	Ga_i.Gamecode_info(Filename);

}