#include "session_info.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace boost::property_tree;
using namespace std;

inline boost::optional<const ptree&> find_attr(const ptree& pt)
{
	ptree::const_assoc_iterator p = pt.find("<xmlattr>");
	return p != pt.not_found() ?
		p->second : boost::optional<const ptree&>();
}

inline std::string get_attr(const ptree& pt, const std::string& name)
{
	return pt.find(name)->second.data();
}


void Session_info::Sessioncode(string Filename) {

	read_xml(Filename + ".xml", pt);
	boost::optional<const ptree&> sessioncodes = find_attr(pt.begin()->second);

	if (boost::optional<std::string> sessioncode = sessioncodes.get().get_optional<std::string>("sessioncode")) {
		session_info_value_t s = { sessioncode.get() };
		std::cout << "sessioncode  [" << s.sessoincode << "]" << std::endl;
	}
	else
		std::cout << "sessioncode attribute not found" << std::endl;
}