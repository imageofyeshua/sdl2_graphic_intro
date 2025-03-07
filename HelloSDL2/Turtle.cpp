#include "Turtle.h"
#include <SDL2/SDL_render.h>
#include <math.h>

Turtle::Turtle() {
    m_pRenderer = NULL;
    m_x = 0.0f;
    m_y = 0.0f;
    m_r = 255;
    m_g = 255;
    m_b = 255;
    m_alpha = 255;
    m_angle = 0.0f;
    m_length = 1.0f;
    m_penDown = false;
}

void Turtle::SetRenderer(SDL_Renderer *pRenderer) { m_pRenderer = pRenderer; }

void Turtle::PenUp() { m_penDown = false; }

void Turtle::PenDown() { m_penDown = true; }

void Turtle::SetPenColor(int r, int g, int b, int alpha) {
    m_r = r;
    m_g = g;
    m_b = b;
    m_alpha = alpha;
}

void Turtle::SetAngle(float angle) { m_angle = angle; }

void Turtle::SetLength(float length) { m_length = length; }

void Turtle::MoveTo(float xPos, float yPos) {
    m_x = xPos;
    m_y = yPos;
}

void Turtle::RotateRight(float angle) { m_angle += angle * (M_PI / 180.0); }

void Turtle::RotateLeft(float angle) { m_angle -= angle * (M_PI / 180.0); }

void Turtle::LookAt(float xPos, float yPos) {
    float dx = xPos - m_x;
    float dy = yPos - m_y;

    if (dx == 0.0) {
        if (dy > 0.0)
            m_angle = M_PI / 2.0;
        else
            m_angle = M_PI + (M_PI / 2.0);
    } else {
        m_angle = atan(dy / dx);
    }

    if (dx < 0.0)
        m_angle += M_PI;
}

void Turtle::Step() {
    // Compute where the turtle will end up.
    float startX = m_x;
    float startY = m_y;
    float endX = startX + (cos(m_angle) * m_length);
    float endY = startY + (sin(m_angle) * m_length);

    // Move the turtle to the new position
    m_x = endX;
    m_y = endY;

    // If a renderer has been specified and pen is down, the draw stuff
    if ((m_pRenderer != NULL) && m_penDown) {
        // We need to draw stuff
        SDL_SetRenderDrawColor(m_pRenderer, m_r, m_g, m_b, m_alpha);
        SDL_RenderDrawLine(m_pRenderer, static_cast<int>(round(startX)),
                           static_cast<int>(round(startY)),
                           static_cast<int>(round(endX)),
                           static_cast<int>(round(endY)));
    }
}

float Turtle::GetX() { return m_x; }

float Turtle::GetY() { return m_y; }
