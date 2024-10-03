#include "EditorApplication.h"

namespace Editor
{
    EditorApplication::EditorApplication()
    {
        
    }

    EditorApplication::~EditorApplication()
    {
    }

    void EditorApplication::OnReady()
    {
        
    }

    void EditorApplication::OnUpdate()
    {

    }
}

Engine::Application* Engine::CreateApplication()
{
    return new Editor::EditorApplication();
}
