﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "common.h"
#include "ResourceAccessor.h"
#include "NumberBox.h"
#include "NumberBoxAutomationPeer.h"
#include "Utils.h"

NumberBoxAutomationPeer::NumberBoxAutomationPeer(winrt::NumberBox const& owner)
    : ReferenceTracker(owner)
{
}

// IAutomationPeerOverrides
winrt::IInspectable NumberBoxAutomationPeer::GetPatternCore(winrt::PatternInterface const& patternInterface)
{
    if (patternInterface == winrt::PatternInterface::RangeValue)
    {
        return *this;
    }

    return __super::GetPatternCore(patternInterface);
}

hstring NumberBoxAutomationPeer::GetClassNameCore()
{
    return winrt::hstring_name_of<winrt::NumberBox>();
}

winrt::AutomationControlType NumberBoxAutomationPeer::GetAutomationControlTypeCore()
{
    return winrt::AutomationControlType::Spinner;
}

com_ptr<NumberBox> NumberBoxAutomationPeer::GetImpl()
{
    com_ptr<NumberBox> impl = nullptr;

    if (auto numberBox = Owner().try_as<winrt::NumberBox>())
    {
        impl = winrt::get_self<NumberBox>(numberBox)->get_strong();
    }

    return impl;
}

// IRangeValueProvider
double NumberBoxAutomationPeer::Minimum()
{
    return GetImpl()->Minimum();
}

double NumberBoxAutomationPeer::Maximum()
{
    return GetImpl()->Maximum();
}

double NumberBoxAutomationPeer::Value()
{
    return GetImpl()->Value();
}

double NumberBoxAutomationPeer::SmallChange()
{
    return GetImpl()->StepFrequency();
}

double NumberBoxAutomationPeer::LargeChange()
{
    return GetImpl()->StepFrequency();
}

void NumberBoxAutomationPeer::SetValue(double value)
{
    GetImpl()->Value(value);
}

void NumberBoxAutomationPeer::RaiseValueChangedEvent(double oldValue, double newValue)
{
    __super::RaisePropertyChangedEvent(winrt::RangeValuePatternIdentifiers::ValueProperty(),
        winrt::PropertyValue::CreateDouble(oldValue),
        winrt::PropertyValue::CreateDouble(newValue));
}
