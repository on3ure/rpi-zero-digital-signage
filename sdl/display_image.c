#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_image.h"

int main(int argc, char* argv[])
{
  SDL_Surface* screen = NULL;
  SDL_Surface* image = NULL;
  const SDL_VideoInfo* videoInfo = NULL;

  if (argc != 2) {
    fprintf(stderr, "display_image <image>\n");
    return 1;
  }

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "SDL_Init error - %s\n", SDL_GetError());
    return 1;
  }
  videoInfo = SDL_GetVideoInfo();

  if (videoInfo == 0) {
    fprintf(stderr, "SDL_GetVideoInfo error - %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  image = IMG_Load(argv[1]);

  if (!image) {
    fprintf(stderr, "IMG_Load error - %s\n", IMG_GetError());
    SDL_Quit();
    return 1;
  }

  screen = SDL_SetVideoMode(image->w,
      image->h,
      videoInfo->vfmt->BitsPerPixel,
      SDL_HWSURFACE);

  if (!screen) {
    fprintf(stderr, "SetVideoMode error - %s\n", SDL_GetError());
    SDL_FreeSurface(image);
    SDL_Quit();
    return 1;
  }

  SDL_BlitSurface(image, 0, screen, 0);

  exit 0;
  return 0;
}
