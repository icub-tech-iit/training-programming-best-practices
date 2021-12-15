
/******************************************************************************
 *                                                                            *
 * Copyright (C) 2021 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

class InterfaceForCApi;

class MediaScanner
{
   public:
   MediaScanner(InterfaceForCApi& interface);
	bool scan();

   InterfaceForCApi &interfaceCApi_;
};