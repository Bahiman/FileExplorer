#include "File.h"

std::filesystem::path file::currentDirectory()
{
    return std::filesystem::current_path();
}

std::vector<std::string> file::getDirectoriesFiles(const std::filesystem::path& path)
{
    if (!std::filesystem::exists(path))
        throw std::runtime_error("No such direcotry exists!(Tring to get the directories' file)");
    std::vector<std::string> files = {};
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        if (std::filesystem::is_directory(entry.path()))
        {
            files.emplace_back(std::move(entry.path().string()));
        }
    }
    return files;
}

std::vector<std::string> file::getDirectoriesDirectories(const std::filesystem::path& path)
{
    if (!std::filesystem::exists(path))
        throw std::runtime_error("The path doesn't exist(Trying to get the direcotries' directory)");
    std::vector<std::string> files = {};
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        if (std::filesystem::is_regular_file(entry.path()))
        {
            auto& filePath = entry.path();
            std::string fileData = filePath.filename().string();
            files.emplace_back(std::move(fileData));
        }
    }
    return files;
}
