#define JEBP_IMPLEMENTATION
#include "jebp.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define VIEW_TITLE_SIZE 1024
#define VIEW_BLOCK_SIZE 8

static jebp_image_t view_image;
static char view_title[VIEW_TITLE_SIZE];
static SDL_Window *view_window;
static SDL_Surface *view_surface;

static void view_destroy(void) {
    jebp_free_image(&view_image);
    if (view_window != NULL) {
        SDL_DestroyWindow(view_window);
    }
    if (view_surface != NULL) {
        SDL_FreeSurface(view_surface);
    }
    SDL_Quit();
}

static void view_error(const char *error) {
    view_destroy();
    fprintf(stderr, "%s\n", error);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        view_error("Usage: jebpview <WebP file>");
    }
    jebp_error_t err = jebp_read(&view_image, argv[1]);
    if (err != JEBP_OK) {
        view_error(jebp_error_string(err));
    }
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        view_error(SDL_GetError());
    }

    snprintf(view_title, VIEW_TITLE_SIZE, "jebpview - %s", argv[1]);
    view_window = SDL_CreateWindow(
        view_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        (int)view_image.width, (int)view_image.height,
        SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_HIDDEN);
    if (view_window == NULL) {
        view_error(SDL_GetError());
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(view_window);
    Uint32 light = SDL_MapRGB(window_surface->format, 0xaa, 0xaa, 0xaa);
    Uint32 dark = SDL_MapRGB(window_surface->format, 0x55, 0x55, 0x55);
    SDL_FillRect(window_surface, NULL, light);
    for (jebp_int y = 0; y < view_image.height; y += VIEW_BLOCK_SIZE * 2) {
        for (jebp_int x = 0; x < view_image.width; x += VIEW_BLOCK_SIZE * 2) {
            SDL_Rect rect = {x + VIEW_BLOCK_SIZE, y, VIEW_BLOCK_SIZE,
                             VIEW_BLOCK_SIZE};
            SDL_FillRect(window_surface, &rect, dark);
            rect.x -= VIEW_BLOCK_SIZE;
            rect.y += VIEW_BLOCK_SIZE;
            SDL_FillRect(window_surface, &rect, dark);
        }
    }

    view_surface = SDL_CreateRGBSurfaceWithFormatFrom(
        view_image.pixels, view_image.width, view_image.height, 32,
        view_image.width * 4, SDL_PIXELFORMAT_RGBA32);
    if (view_surface == NULL) {
        view_error(SDL_GetError());
    }
    SDL_BlitSurface(view_surface, NULL, window_surface, NULL);
    SDL_UpdateWindowSurface(view_window);
    SDL_ShowWindow(view_window);

    for (;;) {
        SDL_Event event;
        if (!SDL_WaitEvent(&event)) {
            view_error(SDL_GetError());
        }
        if (event.type == SDL_QUIT) {
            view_destroy();
            return EXIT_SUCCESS;
        }
    }
}
