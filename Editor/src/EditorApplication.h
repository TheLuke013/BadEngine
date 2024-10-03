#ifndef EDITOR_APPLICATION_H
#define EDITOR_APPLICATION_H

#include <Engine/Engine.h>

namespace Editor
{
    class EditorApplication : public Engine::Application
    {
    public:
        EditorApplication();
        ~EditorApplication();

        void OnReady() override;
        void OnUpdate() override;
    };
}

#endif
