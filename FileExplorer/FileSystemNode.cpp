#include "FileSystemNode.h"
#include<stdexcept>

FileSystemNode::FileSystemNode(const std::filesystem::path& p_path)
{
	if (!std::filesystem::exists(p_path))
		throw std::runtime_error("The passed path is not valid(Constructing the system node)");
	m_path = p_path;
	m_last_modification_date = std::filesystem::last_write_time(m_path);	
	m_size = std::filesystem::file_size(m_path);
}


const std::filesystem::path& FileSystemNode::getPath() const
{
	// TODO: insert return statement here
	return m_path;
}

const std::filesystem::file_time_type& FileSystemNode::getLastModificationDate() const
{
	// TODO: insert return statement here
	return m_last_modification_date;
}


unsigned long long FileSystemNode::getSize() const 
{
	return m_size;
}
