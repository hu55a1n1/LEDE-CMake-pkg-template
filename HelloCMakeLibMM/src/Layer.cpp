/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#include "Layer.hpp"

Layer::Layer(Screen* aScreen, string aName)
{
  screen=aScreen;
  name=aName;
  width=0;
  height=0;
  top=0;
  left=0;
  canvas=new Canvas(width, height);
  transparent=Canvas::COLOR_BLACK;
  enabled=true;
}

Layer::Layer(Screen* aScreen, string aName, int aWidth, int aHeight)
{
  screen=aScreen;
  name=aName;
  width=aWidth;
  height=aHeight;
  top=0;
  left=0;
  canvas=new Canvas(width, height);
  transparent=Canvas::COLOR_BLACK;
  enabled=true;
}

Layer::~Layer()
{
  delete canvas;
}

void Layer::setWidth(int aWidth)
{
  if ( aWidth!=width )
  {
    Canvas* c=new Canvas(aWidth,height);
    canvas->copy(c);
    delete canvas;
    canvas=c;
    width=aWidth;
  }
}

int Layer::getWidth()
{
  return width;
}

void Layer::setHeight(int aHeight)
{
  if ( aHeight!=height )
  {
    Canvas* c=new Canvas(width,aHeight);
    canvas->copy(c);
    delete canvas;
    canvas=c;
    height=aHeight;
  }
}

int Layer::getHeight()
{
  return height;
}

void Layer::setName(string aName)
{
  name=aName;
}

string Layer::getName()
{
  return name;
}

void Layer::setTransparent(int aValue)
{
  transparent=aValue;
}

int Layer::getTransparent()
{
  return transparent;
}

void Layer::setTop(int aTop)
{
  top=aTop;
}

int Layer::getTop()
{
  return top;
}

void Layer::setLeft(int aLeft)
{
  left=aLeft;
}

int Layer::getLeft()
{
  return left;
}

void Layer::setEnabled(bool aEnabled)
{
  enabled=aEnabled;
}

bool Layer::getEnabled()
{
  return enabled;
}

void Layer::moveDown()
{
  screen->moveLayerDown(this);
}

void Layer::moveUp()
{
  screen->moveLayerUp(this);
}

void Layer::setIndex(int aIndex)
{
  screen->setLayerIndex(this,aIndex);
}

int Layer::getIndex()
{
  return screen->getLayerIndex(this);
}

Canvas* Layer::getCanvas()
{
  return canvas;
}
