/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Canvas
{
  private:
    vector< vector<int> > canvas;
    int width;
    int height;
  public:
    static const int OUT_OF_CANVAS_BOUNDS;
    static const int COLOR_BLACK;
    static const int COLOR_WHITE;
    Canvas(int aWidth, int aHeight);
    ~Canvas();
    void writePosition(int aXPos, int aYPos, int aValue);
    int readPosition(int aXPos, int aYPos);
    void writeText(int aXPos, int aYPos, string aText);
    void clear(int aValue);
    void writeRectangle(int aXStartPos, int aYStartPos, int aXEndPos, int aYEndPos, int aValue);
    void writeBox(int aXStartPos, int aYStartPos, int aXEndPos, int aYEndPos, int aValue);
    void writeLine(int aXStartPos, int aYStartPos, int aXEndPos, int aYEndPos, int aValue);
    void copy(Canvas* aCanvas);
    void dumpHex();
    void dumpChar();
};

#endif
