/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Layer.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Layer;

class Screen
{
  private:
    vector<Layer*> layers;
    int width;
    int height;
  public:
    Screen(int aWidth, int aHeight);
    ~Screen();
    void setWidth(int aWidth);
    int getWidth();
    void setHeight(int aHeight);
    int getHeight();
    Layer* createLayer(string aName, int aWidth, int aHeight);
    Layer* getLayerByIndex(int aIndex);
    Layer* getLayerByName(string aName);
    int getLayerCount();
    void moveLayerDown(Layer* aLayer);
    void moveLayerUp(Layer* aLayer);
    void setLayerIndex(Layer* aLayer,int aIndex);
    int getLayerIndex(Layer* aLayer);
    void paint();
};

#endif
