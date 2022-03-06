#define JEBP_IMPLEMENTATION
#include "jebp.h"
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define VIEW_TITLE_SIZE 1024
#define VIEW_BLOCK_SIZE 8

static char view_title[VIEW_TITLE_SIZE];

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: jebpview <WebP file>\n");
        return EXIT_FAILURE;
    }

    jebp_image_t image;
    jebp_error_t err = jebp_read(&image, argv[1]);
    if (err != JEBP_OK) {
        fprintf(stderr, "Failed to read image: %s\n", jebp_error_string(err));
        return EXIT_FAILURE;
    }
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        jebp_free_image(&image);
        return EXIT_FAILURE;
    }

    snprintf(view_title, VIEW_TITLE_SIZE, "jebpview - %s", argv[1]);
    SDL_Window *window = SDL_CreateWindow(
        view_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, image.width,
        image.height, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_HIDDEN);
    if (window == NULL) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        jebp_free_image(&image);
        return EXIT_FAILURE;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    Uint32 light = SDL_MapRGB(window_surface->format, 0xaa, 0xaa, 0xaa);
    Uint32 dark = SDL_MapRGB(window_surface->format, 0x55, 0x55, 0x55);
    SDL_FillRect(window_surface, NULL, light);
    for (jebp_int y = 0; y < image.height; y += VIEW_BLOCK_SIZE * 2) {
        for (jebp_int x = 0; x < image.width; x += VIEW_BLOCK_SIZE * 2) {
            SDL_Rect rect = {x + VIEW_BLOCK_SIZE, y, VIEW_BLOCK_SIZE,
                             VIEW_BLOCK_SIZE};
            SDL_FillRect(window_surface, &rect, dark);
            rect.x -= VIEW_BLOCK_SIZE;
            rect.y += VIEW_BLOCK_SIZE;
            SDL_FillRect(window_surface, &rect, dark);
        }
    }

    SDL_Surface *image_surface = SDL_CreateRGBSurfaceWithFormatFrom(
        image.pixels, image.width, image.height, 32, image.width * 4,
        SDL_PIXELFORMAT_RGBA32);
    if (image_surface == NULL) {
        fprintf(stderr, "Failed to create surface: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        jebp_free_image(&image);
        return EXIT_FAILURE;
    }
    SDL_BlitSurface(image_surface, NULL, window_surface, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_ShowWindow(window);

    int ok;
    SDL_Event event;
    do {
        ok = SDL_WaitEvent(&event);
    } while (ok && event.type != SDL_QUIT);
    if (!ok) {
        fprintf(stderr, "Failed to get event: %s\n", SDL_GetError());
    }
    SDL_FreeSurface(image_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    jebp_free_image(&image);
    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
