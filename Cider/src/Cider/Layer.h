#pragma once

#include "Cider/Core.h"
#include "Cider/Events/Event.h"

namespace Cider
{
    class CIDER_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& e) {}

        inline const std::string& GetName() const { return debugName; }
    protected:
        std::string debugName;
    };
}

