/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#include "Canvas.hpp"

const int Canvas::OUT_OF_CANVAS_BOUNDS=-1;
const int Canvas::COLOR_BLACK=32;
const int Canvas::COLOR_WHITE=35;

Canvas::Canvas(int aWidth, int aHeight)
{
  width=aWidth;
  height=aHeight;

  vector<int> v;
  for (int x=0; x<width; x++)
    v.push_back(COLOR_BLACK);
  for (int y=0; y<height; y++)    
    canvas.push_back(v);
}

Canvas::~Canvas()
{
}

void Canvas::writePosition(int aXPos, int aYPos, int aValue)
{
  if ( (aXPos>=0)&&(aXPos<width)&&(aYPos>=0)&&(aYPos<height) )
    canvas[aYPos][aXPos]=aValue;
}

int Canvas::readPosition(int aXPos, int aYPos)
{
  int result=OUT_OF_CANVAS_BOUNDS;
  if ( (aXPos>=0)&&(aXPos<width)&&(aYPos>=0)&&(aYPos<height) )
    result=canvas[aYPos][aXPos];
  return result;
}

void Canvas::writeText(int aXPos, int aYPos, string aText)
{
  for ( unsigned i=0; i<aText.size(); i++ )
    writePosition(aXPos+i,aYPos,aText[i]);
}

void Canvas::clear(int aValue)
{
  for (int y=0; y<height; y++)
    for (int x=0; x<width; x++)
      writePosition(x,y,aValue);
}

void Canvas::writeRectangle(int aXStartPos, int aYStartPos, int aXEndPos, int aYEndPos, int aValue)
{
  int x1=aXStartPos;
  int y1=aYStartPos;
  int x2=aXEndPos;
  int y2=aYEndPos;

  if ( aXStartPos>aXEndPos )
  {
    x1=aXEndPos;
    x2=aXStartPos;
  }
  if ( aYStartPos>aYEndPos )
  {
    y1=aYEndPos;
    y2=aYStartPos;
  }

  for (int y=y1; y<=y2; y++)
  {
    writePosition(x1,y,aValue);
    writePosition(x2,y,aValue);
  }
  for (int x=x1+1; x<x2; x++)
  {
    writePosition(x,y1,aValue);
    writePosition(x,y2,aValue);
  }
}

void Canvas::writeBox(int aXStartPos, int aYStartPos, int aXEndPos, int aYEndPos, int aValue)
{
  int x1=aXStartPos;
  int y1=aYStartPos;
  int x2=aXEndPos;
  int y2=aYEndPos;

  if ( aXStartPos>aXEndPos )
  {
    x1=aXEndPos;
    x2=aXStartPos;
  }
  if ( aYStartPos>aYEndPos )
  {
    y1=aYEndPos;
    y2=aYStartPos;
  }

  for (int y=y1; y<=y2; y++)
    for (int x=x1; x<=x2; x++)
      writePosition(x,y,aValue);
}

void Canvas::writeLine(int aXStartPos, int aYStartPos, int aXEndPos, int aYEndPos, int aValue)
{
  int lx=abs(aXEndPos-aXStartPos);
  int ly=abs(aYEndPos-aYStartPos);
  int sx=1, sy=1;
  if ( aXEndPos<aXStartPos ) sx=-1;
  if ( aYEndPos<aYStartPos ) sy=-1;

  int px=0;
  int py=sy;
  int dx=sx;
  int dy=sy;
  int ef=lx;
  int es=ly;

  if ( lx>ly )
  {
    px=sx;
    py=0;
    dx=sx;
    dy=sy;
    ef=ly;
    es=lx;
  }

  int x=aXStartPos;
  int y=aYStartPos;
  writePosition(x,y,aValue);
  float e=es/2;
  for ( int i=0; i<es; i++ )
  {
    e=e-ef;
    if ( e<0 )
    {
      e=e+es;
      x+=dx;
      y+=dy;
    }
    else
    {
      x+=px;
      y+=py;
    }
    writePosition(x,y,aValue);
  }  
}

void Canvas::copy(Canvas* aCanvas)
{
  for (int y=0; y<height; y++)
    for (int x=0; x<width; x++)
      aCanvas->writePosition(x,y,canvas[y][x]);
}

void Canvas::dumpHex()
{
  for (int y=0; y<height; y++)
  {
    for (int x=0; x<width; x++)
      cout << hex << setw(2) << canvas[y][x];
    cout << endl;
  }  
}

void Canvas::dumpChar()
{
  for (int y=0; y<height; y++)
  {
    for (int x=0; x<width; x++)
      cout << (char)canvas[y][x];
    cout << endl;
  }  
}
