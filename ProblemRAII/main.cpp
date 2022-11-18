#include <cstdlib>
#include <iostream>

using handle_t = FILE*;
handle_t kNullHandle = NULL;

void raw_write(handle_t handle, const std::string& content)
{
	fprintf(handle, "%s", content.c_str());
}

void raw_close(handle_t handle)
{
	fclose(handle);
}

class IOWrapper final
{
private:
	handle_t m_handle;

public:
	IOWrapper(handle_t handle) : m_handle(handle) {}

	~IOWrapper()
	{
		raw_close(m_handle);
		m_handle = kNullHandle;
	}

	IOWrapper(IOWrapper const&) = delete;
	IOWrapper& operator=(IOWrapper const&) = delete;

	IOWrapper(IOWrapper&& other) noexcept : m_handle(std::move(other.m_handle)) {}

	IOWrapper& operator=(IOWrapper&& other) noexcept
	{
		m_handle = std::move(other.m_handle);

		return *this;
	}

	void Write(const std::string& content)
	{
		raw_write(m_handle, content);
	}
};

int main()
{
	{
		IOWrapper wrapper(fopen("./data.txt", "w"));
		wrapper.Write("Hello");
	}
	{
		IOWrapper wrapper(fopen("./data.txt", "a"));
		wrapper.Write(" ");
	}
	{
		IOWrapper wrapper(fopen("./data.txt", "a"));
		wrapper.Write("World!");
	}
	return 0;
}