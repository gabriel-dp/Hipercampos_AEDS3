#define PLOT_SIZE 500.0f  // 1:1 Aspect Ratio

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/pointlib.h"

// Adjust an coordinate position due to plot and graph sizes difference
int adjust(Coordinate coord, int graphSize) {
    const float adjust = PLOT_SIZE / graphSize;
    return (int)coord * adjust;
}

// Draw a point with some adjusts
void drawPoint(Point p, SDL_Renderer* renderer, int graphSize) {
    SDL_RenderDrawPoint(renderer, adjust(p.x, graphSize), adjust((graphSize - p.y), graphSize));
}

// Draw a line with some adjusts
void drawLine(Point p, Point q, SDL_Renderer* renderer, int graphSize) {
    SDL_RenderDrawLine(renderer, adjust(p.x, graphSize), adjust((graphSize - p.y), graphSize), adjust(q.x, graphSize), adjust((graphSize - q.y), graphSize));
}

// Function to plot the graph of all points and the lines created from the longest path
void plotGraph(Point a, Point b, PointsArray* allPoints, PointsArray* longestPath, int graphSize) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Longest Path", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, PLOT_SIZE, PLOT_SIZE, SDL_WINDOW_SHOWN);

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Set render color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Draw all points
    drawPoint(a, renderer, graphSize);
    drawPoint(b, renderer, graphSize);
    for (int i = 0; i < allPoints->length; i++) {
        drawPoint(allPoints->data[i], renderer, graphSize);
    }

    // Draw lines between the valid points and the anchors
    for (int i = 0; i < longestPath->length; i++) {
        drawLine(longestPath->data[i], a, renderer, graphSize);
        drawLine(longestPath->data[i], b, renderer, graphSize);
    }

    // Render to screen
    SDL_RenderPresent(renderer);

    printf("\nGraph Plotted!\n");

    // Wait until user closes window
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        SDL_Delay(250);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}