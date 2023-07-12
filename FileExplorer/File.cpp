#include "File.h"

File::File(const std::filesystem::path& path) : FileSystemNode(path)
{
	m_file_name = path.filename();
}
