// Renderer.h

#ifndef RENDERER_H
#define RENDERER_H

#include <d2d1.h>
#include "GameObject.h"
#include <sstream>
#include <iostream>


class Renderer {
public:
    Renderer(ID2D1HwndRenderTarget* pRenderTarget);
    ~Renderer();

    ID2D1HwndRenderTarget* GetRenderTarget() const { return pRenderTarget; }
    void RenderBackground();
    void RenderGameObject(const GameObject& gameObject);
    void RenderHealthBar(float currentHealth, float maxHealth, float x, float y, float width, float height);




private:
    ID2D1HwndRenderTarget* pRenderTarget;
    ID2D1SolidColorBrush* pBrush;
};

#endif // RENDERER_H
