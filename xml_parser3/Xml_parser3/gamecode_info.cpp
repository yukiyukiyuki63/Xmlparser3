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
	//ファイル書き込み用宣言
	std::ofstream ofs("test.txt", std::ios::out | std::ios::ate | std::ios::app | std::ios::binary);

	BOOST_FOREACH(const ptree::value_type& child_, pt.get_child("session")) {
		if (child_.first == "game") {
			const ptree& child = child_.second;

			g.gamecode = child.get<std::string>("<xmlattr>.gamecode");

			std::cout << std::endl << std::endl << child_.first <<" [["  <<g.gamecode << "]]" << std::endl;
			ofs << std::endl << std::endl << child_.first << " [[" << g.gamecode << "]]" << std::endl;

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
								std::cout << std::endl << label << ":  " << value << std::endl;
								ofs << std::endl << label << ":  " << value << std::endl;
							}
							if (label == "players") {
								std::cout << "players :" << std::endl;
								BOOST_FOREACH(const ptree::value_type& child_, v.second.get_child("")) {
									if (child_.first == "player") {
										const ptree& child = child_.second;

										g.p.seat = child.get < int >("<xmlattr>.seat");
										g.p.name = child.get < std::string >("<xmlattr>.name");
										g.p.chips = child.get < std::string >("<xmlattr>.chips");
										g.p.dealer = child.get < std::string >("<xmlattr>.dealer");
										g.p.win = child.get < std::string >("<xmlattr>.win");
										g.p.addon = child.get < std::string >("<xmlattr>.addon");
										g.p.reg_code = child.get < std::string >("<xmlattr>.reg_code");

										//標準出力
										std::cout << "seat = " << g.p.seat << ",";
										std::cout << "name = " << g.p.name << ",";
										std::cout << "chips = " << g.p.chips << ",";
										std::cout << "dealer = " << g.p.dealer << ",";
										std::cout << "win = " << g.p.win << ",";
										std::cout << "addon = " << g.p.addon << ",";
										std::cout << "reg_code = " << g.p.reg_code << std::endl;
										
										//ファイル出力
										ofs << "seat = " << g.p.seat << ",";
										ofs << "name = " << g.p.name << ",";
										ofs << "chips = " << g.p.chips << ",";
										ofs << "dealer = " << g.p.dealer << ",";
										ofs << "win = " << g.p.win << ",";
										ofs << "addon = " << g.p.addon << ",";
										ofs << "reg_code = " << g.p.reg_code << std::endl;

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
					std::cout << std::endl << "round no  [[" << g.r.no << "]]" << std::endl;
					ofs << std::endl << "round no  [[" << g.r.no << "]]" << std::endl;


					BOOST_FOREACH(boost::property_tree::ptree::value_type const& w, subtree2.get_child(""))
					{
						std::string label = w.first;
						if (label != "<xmlattr>")
						{
								const std::string value = boost::lexical_cast<std::string>(w.second.data());
								std::cout << label << ":  " << value << std::endl;
								ofs << label << ":  " << value << std::endl;


							if (w.first == "action") {

								g.r.a.no = w.second.get<int>("<xmlattr>.no");
								g.r.a.player = w.second.get<std::string>("<xmlattr>.player");
								g.r.a.type = w.second.get<std::string>("<xmlattr>.type");
								g.r.a.sum = w.second.get<std::string>("<xmlattr>.sum");
								g.r.a.cards = w.second.get<std::string>("<xmlattr>.cards");

								std::cout << "no = " << g.r.a.no << ",";
								std::cout << "player = " << g.r.a.player << ",";
								std::cout << "type = " << g.r.a.type << ",";
								std::cout << "sum = " << g.r.a.sum << ",";
								std::cout << "cards = " << g.r.a.cards << std::endl;

								ofs << "no = " << g.r.a.no << ",";
								ofs << "player = " << g.r.a.player << ",";
								ofs << "type = " << g.r.a.type << ",";
								ofs << "sum = " << g.r.a.sum << ",";
								ofs << "cards = " << g.r.a.cards << std::endl;
							}

							if (w.first == "cards") {

								g.r.c.type = w.second.get<std::string>("<xmlattr>.type");
								g.r.c.player = w.second.get<std::string>("<xmlattr>.player");

								std::cout << "type = " << g.r.c.type << ",";
								std::cout << "player = "<< g.r.c.player << std::endl;

								ofs << "type = " << g.r.c.type << ",";
								ofs << "player = " << g.r.c.player << std::endl;
							}

						}
					}
					std::cout << std::endl;
				}
			}
		}
	}
	//最後にvector g_daに構造体の配列gをpush
	g_da.push_back(g);
}