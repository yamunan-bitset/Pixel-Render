#include "window.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdlib.h>
#include <time.h>

struct Window window =
  {
    .title = "Pixel Engine",
    .width = 500,
    .height = 500
  };

int sprite[] =
  {
#include "art.inc"
  };

void render()
{
  struct Colour colour1 = { .r=1,.g=1,.b=1 };
  struct Colour colour2 = { .r=0,.g=0,.b=0 };
  srand(time(0));
  render_init(&window);

/*
  for (unsigned w = 0; w < window.width; w+=10)
    for (unsigned h = 0; h < window.height; h+=10)
      pixel(w, h, 10, (1 + (rand() % 10)) / 10, 
      (1 + (rand() % 10)) / 10, (1 + (rand() % 10)) / 10);
*/
  for (unsigned x = 0; x < window.width; x+=10)
    for (unsigned y = 0; y < window.height; y+=10)
      {
	if (sprite[y * 5 + x] == 1) pixel(x, y, 10, &colour1);
	else                        pixel(x, y, 10, &colour2);
      }
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  init(&window);
  glutDisplayFunc(render);
  glutMainLoop();
  return 0;
}
