
/******************************************************************************
 *                                                                            *
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia (IIT)        *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @luca.triceri@iit.it
 */

#pragma once

#include <string>

class MultiplierFromDb
{
public:
    explicit MultiplierFromDb(const std::string &name) : name_(name){};
    double invoke(unsigned int leftIndex, unsigned int rightIndex) const;

protected:
    virtual double getDataFromDb(unsigned int index) const;
    const std::string name_;
};