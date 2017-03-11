/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#include "Hello.hpp"

Hello::Hello()
{
  screen=new Screen(32,11);

  screen->createLayer("background",32,16);
  screen->createLayer("border",32,16);
  screen->createLayer("box",3,3);
  screen->createLayer("texthello",18,3);
  screen->createLayer("textcmake",19,1);

  screen->getLayerByName("background")->getCanvas()->clear(int('.'));

  screen->getLayerByName("border")->getCanvas()->writeRectangle(1,1,30,9,int('#'));

  screen->getLayerByName("box")->getCanvas()->writeRectangle(0,0,2,2,int('*'));
  screen->getLayerByName("box")->setLeft(29);
  screen->getLayerByName("box")->setTop(8);

  screen->getLayerByName("texthello")->getCanvas()->writeText(2,1,"Hello OpenWRT!");
  screen->getLayerByName("texthello")->setTransparent(int('F'));
  screen->getLayerByName("texthello")->setLeft(7);
  screen->getLayerByName("texthello")->setTop(3);
  
  screen->getLayerByName("textcmake")->getCanvas()->writeText(1,0,"CMake works here");
  screen->getLayerByName("texthello")->setTransparent(int('C'));
  screen->getLayerByName("textcmake")->setTransparent(int(' '));
  screen->getLayerByName("textcmake")->setLeft(7);
  screen->getLayerByName("textcmake")->setTop(7);
}

Hello::~Hello()
{
  delete screen;
}

void Hello::paint()
{
  screen->paint();
}
