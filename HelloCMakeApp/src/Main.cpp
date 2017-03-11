/*
 Copyright (C) 2008 Frank Cervenka

 This is free software, licensed under the GNU General Public License v2.
*/
#include "Main.hpp"

int main (int argc, char *argv[])
{
  Hello* hello=new Hello();
  hello->paint();
  delete hello;
  return EXIT_SUCCESS;
}
