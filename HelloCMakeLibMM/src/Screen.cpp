/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#include "Screen.hpp"

Screen::Screen(int aWidth, int aHeight)
{
  width=aWidth;
  height=aHeight;
}

Screen::~Screen()
{
  while ( layers.size()>0 )
    layers.pop_back();
}

void Screen::setWidth(int aWidth)
{
  width=aWidth;
}

int Screen::getWidth()
{
  return width;
}

void Screen::setHeight(int aHeight)
{
  height=aHeight;
}

int Screen::getHeight()
{
  return height;
}

Layer* Screen::createLayer(string aName, int aWidth, int aHeight)
{
  Layer* result=new Layer(this,aName,aWidth,aHeight);
  layers.push_back(result);
  return result;
}

Layer* Screen::getLayerByIndex(int aIndex)
{
  Layer* result=NULL;
  if ( (aIndex>=0)&&((unsigned)aIndex<layers.size()) )
    result=layers[aIndex];
  return result;
}

Layer* Screen::getLayerByName(string aName)
{
  Layer* result=NULL;
  for ( unsigned i=0; i<layers.size(); i++ )
  if ( layers[i]->getName()==aName )
    result=layers[i];
  return result;
}

int Screen::getLayerCount()
{
  return layers.size();
}

void Screen::moveLayerDown(Layer* aLayer)
{
  int index=getLayerIndex(aLayer);
  if ( index>0 )
  {
    Layer* l=layers[index-1];
    layers[index-1]=layers[index];
    layers[index]=l;
  }
}

void Screen::moveLayerUp(Layer* aLayer)
{
  unsigned index=getLayerIndex(aLayer);
  if ( index<layers.size()-1 )
  {
    Layer* l=layers[index+1];
    layers[index+1]=layers[index];
    layers[index]=l;
  }
}

void Screen::setLayerIndex(Layer* aLayer,int aIndex)
{
  if (aIndex<0)
    aIndex=0;
  if ((unsigned)aIndex>layers.size()-1)
    aIndex=layers.size()-1;
  while ( getLayerIndex(aLayer)!=aIndex )
  {
    if ( aIndex<getLayerIndex(aLayer) )
      moveLayerDown(aLayer);
    else
      moveLayerUp(aLayer);
  }
}

int Screen::getLayerIndex(Layer* aLayer)
{
  int result=-1;
  for ( unsigned i=0; i<layers.size(); i++ )
    if ( layers[i]==aLayer )
      result=i;
  return result;
}

void Screen::paint()
{
  Canvas* c=new Canvas(width,height);
  for ( int y=0; y<height; y++ )
    for ( int x=0; x<width; x++ )
      for ( unsigned i=0; i<layers.size(); i++ )
        if ( layers[i]->getEnabled() )
        {
          Layer* l=layers[i];
          int p=l->getCanvas()->readPosition(x-l->getLeft(),y-l->getTop());
          if ( (p!=Canvas::OUT_OF_CANVAS_BOUNDS)&&(p!=l->getTransparent()) )
            c->writePosition(x,y,p);
        }
  c->dumpChar();
  delete c;
}
