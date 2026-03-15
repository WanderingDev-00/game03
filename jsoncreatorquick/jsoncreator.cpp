#include<iostream>
#include<nlohmann/json.hpp>
#include<fstream>

using json = nlohmann::json;
int main()
{
	std::cout << "lesson 2" << std::endl;

	json player;
	player["name"] = "warrior";
	player["health"] = 150;
	player["level"] = 10;
	player["gold"] = 500;

	std::cout << "created json: \n" << player.dump(2) << std::endl;

	return 0;
}