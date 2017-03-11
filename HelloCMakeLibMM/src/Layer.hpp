/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#ifndef LAYER_HPP
#define LAYER_HPP

#include "Canvas.hpp"
#include "Screen.hpp"
#include <iostream>

using namespace std;

class Screen;

class Layer
{
  private:
    Screen* screen;
    string name;
    Canvas* canvas;
    int width;
    int height;
    int top;
    int left;
    int transparent;
    bool enabled;
  public:
    Layer(Screen* aScreen, string aName);
    Layer(Screen* aScreen, string aName, int aWidth, int aHeight);
    ~Layer();
    void setWidth(int aWidth);
    int getWidth();
    void setHeight(int aHeight);
    int getHeight();
    void setName(string aName);
    string getName();
    void setTransparent(int aValue);
    int getTransparent();
    void setTop(int aTop);
    int getTop();
    void setLeft(int aLeft);
    int getLeft();
    void setEnabled(bool aEnabled);
    bool getEnabled();
    void moveDown();
    void moveUp();
    void setIndex(int aIndex);
    int getIndex();
    Canvas* getCanvas();
};

#endif
