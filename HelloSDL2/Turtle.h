#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

class Turtle {
    public:
        // The default constructor
        Turtle();

        // Method to allow the user to specify the renderer
        void SetRenderer(SDL_Renderer *m_pRenderer);

        // Methods to control the pen
        void PenUp();
        void PenDown();
        void SetPenColor(int r, int g, int b, int alpha);

        // Methods to control movement
        void SetAngle(float angle);
        void SetLength(float length);
        void RotateRight(float angle);
        void RotateLeft(float angle);
        void LookAt(float xPos, float yPos);

        // Method to allow the user to specify the starting position
        void MoveTo(float xPos, float yPos);

        // Methods to allow the user to retrieve the current position
        float GetX();
        float GetY();

        // Method to actually make the turtle move
        void Step();

    private:
        SDL_Renderer *m_pRenderer;
        float m_x, m_y;
        float m_angle, m_length;
        int m_r, m_g, m_b, m_alpha;
        bool m_penDown;
};
