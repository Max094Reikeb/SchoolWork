// Packages
#include <stdlib.h>
#include <stdio.h>
#include "SDL2/SDL.h"
#include <iostream>

using namespace std;

int main() {

    SDL_Window *window = nullptr;                                // Declare a pointer for the window

    SDL_Surface *window_surface = nullptr;                       // Declare a pointer for the surface
    SDL_Surface *image_surface = nullptr;                        // Declare a pointer for the image

    SDL_Init(SDL_INIT_VIDEO);                                    // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Counter",                                               // window title
        0,                                                       // initial x position
        0,                                                       // initial y position
        256,                                                     // width, in pixels
        256,                                                     // height, in pixels
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // Initializing the window surface
    window_surface = SDL_GetWindowSurface(window);

    // We enter a loop until the user quits the window
    int c = 0;
    bool quit = false;
    SDL_Event event;

    while (!quit) {

        // We initialize the image according to the counter
        if (c == 0) {
            image_surface = SDL_LoadBMP("0.bmp");
        } else if (c == 1) {
            image_surface = SDL_LoadBMP("1.bmp");
        } else if (c == 2) {
            image_surface = SDL_LoadBMP("2.bmp");
        } else if (c == 3) {
            image_surface = SDL_LoadBMP("3.bmp");
        } else if (c == 4) {
            image_surface = SDL_LoadBMP("4.bmp");
        } else if (c == 5) {
            image_surface = SDL_LoadBMP("5.bmp");
        } else if (c == 6) {
            image_surface = SDL_LoadBMP("6.bmp");
        } else if (c == 7) {
            image_surface = SDL_LoadBMP("7.bmp");
        } else if (c == 8) {
            image_surface = SDL_LoadBMP("8.bmp");
        } else if (c == 9) {
            image_surface = SDL_LoadBMP("9.bmp");
        } else {
            image_surface = SDL_LoadBMP("10.bmp");
        }
        //int myInt = 9;
        //std::stringstream ss;
        //ss << myInt << ".bmp";
        //std::cout << ss.str();

        // We check that the image is successfuly loaded (if not, we display the error and we quit)
        if (image_surface == NULL) {
            printf("Could not load the image : %s\n", SDL_GetError());
            return 1;
        }

        SDL_BlitSurface(image_surface, NULL, window_surface, NULL);  // We show the image on the screen
        SDL_FreeSurface(image_surface);                              // We free the space
        SDL_UpdateWindowSurface(window);                             // We update the screen

        // We watch the events
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_DOWN:
                            if (c >= 1) {
                                c--;
                                printf("Removed 1 from counter\n");
                            }
                            break;

                        case SDLK_UP:
                            c++;
                            printf("Added 1 to counter\n");
                            break;

                        default:
                            break;
                    }
                    break;
                case SDL_QUIT:
                    quit = true;
                    break;
            }
        }
    }

    // Quit and return OK
    printf("%d\n", c);
    SDL_Quit();
    return 0;
}
