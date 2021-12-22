
/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#include <string>

class InterfaceForCApi;

class MediaScanner
{
   public:
   MediaScanner(InterfaceForCApi& interface);
	bool scan(const std::string& media);

   InterfaceForCApi &interfaceCApi_;
};