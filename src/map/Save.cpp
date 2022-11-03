/*
** EPITECH PROJECT, 2022
** indie_studio
** File description:
** save.cpp
*/

#include "MapManager.hpp"

bool ids::MapManager::save(const std::string &path) noexcept
{
	std::fstream save_file;
	std::vector<std::string> lines;
	int y = 0;
	int x = 0;

	save_file.open(!path.empty() ? path : PATH_SAVE_FILE, std::ios_base::out);
	if (!save_file.is_open()) {
		exit(84);
	}
	for (auto &line: _staticMapVector2) {
		std::string tmp;
		for (auto &cases: line) {
			tmp.push_back(static_cast<char>(cases));
		}
		lines.emplace_back(tmp);
	}
	for (auto &line: _boxMapVector2) {
		for (auto &cases: line) {
			if (cases == BoxMap::Unknown) {
				x += 1;
				continue;
			}
			lines[y][x] = static_cast<char>(cases);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	for (auto &line: lines) {
		line += '\n';
		save_file << line;
	}

	return true;
}