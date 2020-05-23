#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

  char buffer[250];
  SDL_Surface* screen = NULL;
  SDL_Surface* image = NULL;
  const SDL_VideoInfo* videoInfo = NULL;

  if (argc != 3) {
    fprintf(stderr, "display_image <ip> <image>\n");
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
  sprintf(buffer, "curl http://%s:1234/%s  --output %s --silent", argv[1], argv[2], argv[2]);
  system(buffer);

  image = IMG_Load(argv[2]);

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

  while (1) {
    SDL_Delay(36000);
    SDL_FreeSurface(image);

    sprintf(buffer, "curl http://%s:1234/%s  --output %s --silent", argv[1], argv[2], argv[2]);
    system(buffer);
    image = IMG_Load(argv[2]);

    if (!image) {
      fprintf(stderr, "IMG_Load error - %s\n", IMG_GetError());
      SDL_Quit();
      return 1;
    }
    SDL_BlitSurface(image, 0, screen, 0);
  }

  SDL_Quit();

  return 0;
}
