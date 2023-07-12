#pragma once
#include"FileSystemNode.h"

class File : public FileSystemNode
{
private:
	std::filesystem::path m_file_name;
public:
	File(const std::filesystem::path& path);
};