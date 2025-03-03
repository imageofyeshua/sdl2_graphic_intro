#include "CApp.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

CApp::CApp() {
    isRunning = true;
    pWindow = NULL;
    pRenderer = NULL;

    // Configure the standard colors we want to use
    m_redList.push_back(51);
    m_greenList.push_back(128);
    m_blueList.push_back(204);
    m_redList.push_back(255);
    m_greenList.push_back(128);
    m_blueList.push_back(0);
    m_redList.push_back(255);
    m_greenList.push_back(191);
    m_blueList.push_back(0);
}

bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    pWindow =
        SDL_CreateWindow("Turtle Adventure", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if (pWindow != NULL) {
        pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    } else {
        return false;
    }

    // Initialize our turtle
    Turtle m_turtle;
    m_turtle.MoveTo(320, 240);

    // Set the background color to black
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(pRenderer);

    // Do stuff with our turtle
    m_turtle.SetRenderer(pRenderer);
    m_turtle.PenDown();
    m_turtle.SetLength(75);

    for (int i = 0; i < 18; i++) {
        m_turtle.SetPenColor(m_redList[i % 3], m_greenList[i % 3],
                             m_blueList[i % 3], 255);
        for (int j = 0; j < 8; j++) {
            m_turtle.RotateRight(45);
            m_turtle.Step();
        }
        m_turtle.RotateLeft(20);
    }

    return true;
}

int CApp::OnExecute() {
    SDL_Event event;

    if (OnInit() == false) {
        return -1;
    }

    while (isRunning) {
        while (SDL_PollEvent(&event) != 0) {
            OnEvent(&event);
        }

        OnLoop();
        OnRender();
    }

    OnExit();

    return 0;
}

void CApp::OnEvent(SDL_Event *event) {
    if (event->type == SDL_QUIT) {
        isRunning = false;
    }
}

void CApp::OnLoop() {}

void CApp::OnRender() {
    /*
    // Set the background color to white
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

    // Draw a red rectangle
    SDL_Rect fillRect = {150, 120, 300, 200};
    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
    SDL_RenderFillRect(pRenderer, &fillRect);
    */

    // Show the result
    SDL_RenderPresent(pRenderer);
}

void CApp::OnExit() {
    SDL_DestroyWindow(pWindow);
    pWindow = NULL;
    SDL_Quit();
}
