#pragma once
#include<filesystem>
#include<sys/stat.h>

class FileSystemNode
{
protected:
	std::filesystem::path m_path;
	std::filesystem::file_time_type m_last_modification_date;
	unsigned long long m_size;
public:
	FileSystemNode(const std::filesystem::path& p_path);
	FileSystemNode() = delete;
	virtual ~FileSystemNode() = default;
	const std::filesystem::path& getPath() const;
	const std::filesystem::file_time_type& getLastModificationDate() const;
	virtual unsigned long long getSize() const;
};
