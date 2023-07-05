#pragma once
#include<filesystem>

namespace file
{
	std::filesystem::path currentDirectory();	
	std::vector<std::string> getDirectoriesFiles(const std::filesystem::path& path);
	std::vector<std::string> getDirectoriesDirectories(const std::filesystem::path& path);
}