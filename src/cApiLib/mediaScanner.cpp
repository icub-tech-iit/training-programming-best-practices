#include "mediaScanner.h"
#include "InterfaceForCApi.h"

MediaScanner::MediaScanner(InterfaceForCApi& interface) : interfaceCApi_(interface)
{
}

bool MediaScanner::scan(const std::string& media)
{
	//..
	
	// Open main device
	int fd = interfaceCApi_.open_c(media.c_str(), O_RDWR);
	//int fd = open(media.c_str(), O_RDWR); <--- original code
	if (fd == -1)
	{
		return false;
	}

	struct udev *udev;
	udev = interfaceCApi_.udev_new_c();
	//udev = udev_new(); <--- original code
	if (udev == nullptr)
	{
		return false;
	}

	//...
	return true;
}