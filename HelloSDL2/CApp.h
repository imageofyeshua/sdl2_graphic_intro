#include "Turtle.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_log.h>
#include <vector>

class CApp {
    public:
        CApp();

        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event *event);
        void OnLoop();
        void OnRender();
        void OnExit();

    private:
        bool isRunning;
        SDL_Window *pWindow;
        SDL_Renderer *pRenderer;

        Turtle m_turtle;
        std::vector<int> m_redList;
        std::vector<int> m_greenList;
        std::vector<int> m_blueList;
};
