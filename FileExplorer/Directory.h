#pragma once 
#include"FileSystemNode.h"
#include<vector>
#include"File.h"

class Directory : public FileSystemNode
{
public:
	Directory(const std::filesystem::path dir);
	std::filesystem::path getPreviousDirectory();
	std::vector<Directory> getAllDirectoriesInside();
	std::vector<File> getAllFilesInside();
	static std::vector<File> getAllFilesInside(const std::filesystem::path& pPath);
	static std::vector<Directory> getAllDirectoriesInside(const std::filesystem::path& pPath);
	unsigned long long getSize() const override; 
};	