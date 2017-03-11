/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#ifndef HELLO_HPP
#define HELLO_HPP

#include <libhellocmakemm/Layer.hpp>
#include <libhellocmakemm/Canvas.hpp>
#include <libhellocmakemm/Screen.hpp>

using namespace std;

class Hello
{
  private:
    Screen* screen;
  public:
    Hello();
    ~Hello();
    void paint();
};

#endif
