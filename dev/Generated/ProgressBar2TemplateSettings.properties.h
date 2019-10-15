// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#pragma once

class ProgressBar2TemplateSettingsProperties
{
public:
    ProgressBar2TemplateSettingsProperties();

    void ClipRect(winrt::RectangleGeometry const& value);
    winrt::RectangleGeometry ClipRect();

    void ContainerAnimationEndPosition(double value);
    double ContainerAnimationEndPosition();

    void ContainerAnimationStartPosition(double value);
    double ContainerAnimationStartPosition();

    void IndicatorLengthDelta(double value);
    double IndicatorLengthDelta();

    static winrt::DependencyProperty ClipRectProperty() { return s_ClipRectProperty; }
    static winrt::DependencyProperty ContainerAnimationEndPositionProperty() { return s_ContainerAnimationEndPositionProperty; }
    static winrt::DependencyProperty ContainerAnimationStartPositionProperty() { return s_ContainerAnimationStartPositionProperty; }
    static winrt::DependencyProperty IndicatorLengthDeltaProperty() { return s_IndicatorLengthDeltaProperty; }

    static GlobalDependencyProperty s_ClipRectProperty;
    static GlobalDependencyProperty s_ContainerAnimationEndPositionProperty;
    static GlobalDependencyProperty s_ContainerAnimationStartPositionProperty;
    static GlobalDependencyProperty s_IndicatorLengthDeltaProperty;

    static void EnsureProperties();
    static void ClearProperties();
};
