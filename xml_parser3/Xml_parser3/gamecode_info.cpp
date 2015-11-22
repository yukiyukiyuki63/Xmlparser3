#include "session_info.h"
#include "gamecode_info.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <vector>   
#include <boost/lexical_cast.hpp>

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

void Game_info::Gamecode_info(string Filename) {
	player_t p;
	round_t r;
	action_t a;
	cards_t c;
	vector<player_t> p_da;
	vector<round_t> r_da;

	read_xml(Filename + ".xml", pt);
	boost::optional<const ptree&> gamecodes = find_attr(pt.begin()->second);

	BOOST_FOREACH(const ptree::value_type& child_, pt.get_child("session")) {
		if (child_.first == "game") {
			const ptree& child = child_.second;
			std::cout << child_.first <<" [["  <<child.get<std::string>("<xmlattr>.gamecode") << "]]" << std::endl;

			BOOST_FOREACH(boost::property_tree::ptree::value_type const& node2, child.get_child(""))
			{
				boost::property_tree::ptree subtree2 = node2.second;

				if (node2.first == "general")
				{
					BOOST_FOREACH(boost::property_tree::ptree::value_type const& v, subtree2.get_child(""))
					{
						std::string label = v.first;
						if (label != "<xmlattr>")
						{
							if (label == "startdate") {
								std::string value = subtree2.get<std::string>(label);
								std::cout << label << ":  " << value << std::endl;
							}
							if (label == "players") {
								std::cout << "players :" << std::endl;
								BOOST_FOREACH(const ptree::value_type& child_, v.second.get_child("")) {
									if (child_.first == "player") {
										const ptree& child = child_.second;
										std::cout << "seat = ";
										p.seat = child.get < int >("<xmlattr>.seat");
										std::cout << p.seat << ",";

										std::cout << "name = ";
										p.name = child.get < std::string >("<xmlattr>.name");
										std::cout << p.name << ",";

										std::cout << "chips = ";
										p.chips = child.get < std::string >("<xmlattr>.chips");
										std::cout << p.chips << ",";

										std::cout << "dealer = ";
										p.dealer = child.get < std::string >("<xmlattr>.dealer");
										std::cout << p.dealer << ",";

										std::cout << "win = ";
										p.win = child.get < std::string >("<xmlattr>.win");
										std::cout << p.win << ",";

										std::cout << "addon = ";
										p.addon = child.get < std::string >("<xmlattr>.addon");
										std::cout << p.addon << ",";

										std::cout << "reg_code = ";
										p.reg_code = child.get < std::string >("<xmlattr>.reg_code");
										std::cout << p.reg_code << std::endl;
										p_da.push_back(p);
									}

									else {
										std::cout << "seat is nothing" << std::endl;
									}
								}
							}
						}
					}
					std::cout << std::endl;
				}

				if (node2.first == "round")
				{
					const ptree& child_round = node2.second;
					r.no = child_round.get<int>("<xmlattr>.no");
					std::cout << "round no  [[" << r.no << "]]" << std::endl;
					r_da.push_back(r);

					BOOST_FOREACH(boost::property_tree::ptree::value_type const& w, subtree2.get_child(""))
					{
						std::string label = w.first;
						if (label != "<xmlattr>")
						{
								const std::string value = boost::lexical_cast<std::string>(w.second.data());
								std::cout << label << ":  " << value << std::endl;

							if (w.first == "action") {
								std::cout << "no = ";
								std::cout << w.second.get<std::string>("<xmlattr>.no") << ",";
								std::cout << "player = ";
								std::cout << w.second.get<std::string>("<xmlattr>.player") << ",";
								std::cout << "type = ";
								std::cout << w.second.get<std::string>("<xmlattr>.type") << ",";
								std::cout << "sum = ";
								std::cout << w.second.get<std::string>("<xmlattr>.sum") << ",";
								std::cout << "cards = ";
								std::cout << w.second.get<std::string>("<xmlattr>.cards") << std::endl;
							}

							if (w.first == "cards") {
								std::cout << "type = ";
								std::cout << w.second.get<std::string>("<xmlattr>.type") << ",";
								std::cout << "player = ";
								std::cout << w.second.get<std::string>("<xmlattr>.player") << std::endl;
							}

						}
					}
					std::cout << std::endl;
				}
			}
		}
	}
}