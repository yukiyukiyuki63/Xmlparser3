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

	gamecode_t g;
	vector<gamecode_t> g_da;

	read_xml(Filename + ".xml", pt);
	boost::optional<const ptree&> gamecodes = find_attr(pt.begin()->second);

	BOOST_FOREACH(const ptree::value_type& child_, pt.get_child("session")) {
		if (child_.first == "game") {
			const ptree& child = child_.second;

			g.gamecode = child.get<std::string>("<xmlattr>.gamecode");

			std::cout << child_.first <<" [["  <<g.gamecode << "]]" << std::endl;

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
										g.p.seat = child.get < int >("<xmlattr>.seat");
										std::cout << g.p.seat << ",";

										std::cout << "name = ";
										g.p.name = child.get < std::string >("<xmlattr>.name");
										std::cout << g.p.name << ",";

										std::cout << "chips = ";
										g.p.chips = child.get < std::string >("<xmlattr>.chips");
										std::cout << g.p.chips << ",";

										std::cout << "dealer = ";
										g.p.dealer = child.get < std::string >("<xmlattr>.dealer");
										std::cout << g.p.dealer << ",";

										std::cout << "win = ";
										g.p.win = child.get < std::string >("<xmlattr>.win");
										std::cout << g.p.win << ",";

										std::cout << "addon = ";
										g.p.addon = child.get < std::string >("<xmlattr>.addon");
										std::cout << g.p.addon << ",";

										std::cout << "reg_code = ";
										g.p.reg_code = child.get < std::string >("<xmlattr>.reg_code");
										std::cout << g.p.reg_code << std::endl;

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
					g.r.no = child_round.get<int>("<xmlattr>.no");
					std::cout << "round no  [[" << g.r.no << "]]" << std::endl;


					BOOST_FOREACH(boost::property_tree::ptree::value_type const& w, subtree2.get_child(""))
					{
						std::string label = w.first;
						if (label != "<xmlattr>")
						{
								const std::string value = boost::lexical_cast<std::string>(w.second.data());
								std::cout << label << ":  " << value << std::endl;

							if (w.first == "action") {

								g.r.a.no = w.second.get<int>("<xmlattr>.no");
								std::cout << "no = ";
								std::cout << g.r.a.no << ",";

								g.r.a.player = w.second.get<std::string>("<xmlattr>.player");
								std::cout << "player = ";
								std::cout << g.r.a.player << ",";

								g.r.a.type = w.second.get<std::string>("<xmlattr>.type");
								std::cout << "type = ";
								std::cout << g.r.a.type << ",";

								g.r.a.sum = w.second.get<std::string>("<xmlattr>.sum");
								std::cout << "sum = ";
								std::cout << g.r.a.sum << ",";

								g.r.a.cards = w.second.get<std::string>("<xmlattr>.cards");
								std::cout << "cards = ";
								std::cout << g.r.a.cards << std::endl;
							}

							if (w.first == "cards") {

								g.r.c.type = w.second.get<std::string>("<xmlattr>.type");
								std::cout << "type = ";
								std::cout << g.r.c.type << ",";

								g.r.c.player = w.second.get<std::string>("<xmlattr>.player");
								std::cout << "player = ";
								std::cout << g.r.c.player << std::endl;
							}

						}
					}
					std::cout << std::endl;
				}
			}
		}
	}

	//ÅŒã‚Évector g_da‚É\‘¢‘Ì‚Ì”z—ñg‚ðpush
	g_da.push_back(g);
}