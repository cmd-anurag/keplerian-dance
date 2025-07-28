#pragma once

class Body;

class SelectionManager
{
    public:
        SelectionManager();
        SelectionManager(Body* sun);

        void setSelected(Body *body);
        void clearSelection();

        Body* getSelected() const;
        bool hasSelection() const;
    private:
        Body* selectedBody;
};