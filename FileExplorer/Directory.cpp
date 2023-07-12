#include "Directory.h"
#include<vector>

Directory::Directory(const std::filesystem::path dir) : FileSystemNode(dir)
{
}

std::filesystem::path Directory::getPreviousDirectory()
{
	return m_path.parent_path();
}

std::vector<Directory> Directory::getAllDirectoriesInside()
{
	return Directory::getAllDirectoriesInside(m_path);
}

std::vector<File> Directory::getAllFilesInside()
{
	return Directory::getAllFilesInside(m_path);
}

std::vector<File> Directory::getAllFilesInside(const std::filesystem::path& pPath)
{
	std::vector<File> files = {};

	for (const auto& file : std::filesystem::directory_iterator(pPath))
	{
		if (std::filesystem::is_regular_file(file))
			files.emplace_back(file);
	}

	return files;
}

std::vector<Directory> Directory::getAllDirectoriesInside(const std::filesystem::path& pPath)
{
	std::vector<Directory> directories = {};

	for (const auto& dir : std::filesystem::directory_iterator(pPath))
	{
		if (std::filesystem::is_directory(dir))
			directories.emplace_back(dir);
	}

	return directories;
}

unsigned long long Directory::getSize() const 
{

	unsigned long long res = 0;

	for (const auto& file : std::filesystem::directory_iterator(m_path))
	{
		if (std::filesystem::is_regular_file(file)) {
			res += std::filesystem::file_size(file.path());
		}
	}

	return res;
}
