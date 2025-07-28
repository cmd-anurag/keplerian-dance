#include "core/SelectionManager.hpp"
#include "core/Body.hpp"

SelectionManager::SelectionManager()
{
    selectedBody = nullptr;
}


void SelectionManager::setSelected(Body *body)
{
    selectedBody = body;
}

void SelectionManager::clearSelection()
{
    selectedBody = nullptr;
}

Body *SelectionManager::getSelected() const
{
    return selectedBody;
}

bool SelectionManager::hasSelection() const
{
    return selectedBody != nullptr;
}