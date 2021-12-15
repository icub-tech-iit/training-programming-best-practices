#include "mediaScanner.h"
#include "InterfaceForCApi.h"

MediaScanner::MediaScanner(InterfaceForCApi& interface) : interfaceCApi_(interface)
{
}

bool MediaScanner::scan()
{
	// Open main device
	int fd = interfaceCApi_.open_c("/dev/media0", O_RDWR);
	if (fd == -1)
	{
		return false;
	}

	struct udev *udev;
	udev = interfaceCApi_.udev_new_c();
	if (udev == nullptr)
	{
		return false;
	}

	//...
	return true;
}