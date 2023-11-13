#include "EventManager.h"

EventManager* EventManager::eInstance = nullptr;

void EventManager::AddComponent(sf::Event::EventType eventType, sf::Mouse::Button mouseEvent, func event)
{
    m_cMap[eventType][mouseEvent] = *event;
}

EventManager::EventManager()
{

}

void EventManager::Update(sf::RenderWindow* oWindow)
{ 
    //EVENT
    sf::Event oEvent;
    while (oWindow->pollEvent(oEvent))
    {
        if (oEvent.type == sf::Event::Closed)
            oWindow->close();

        ManageEvent(oEvent.type, oEvent.mouseButton.button);
    }
}

EventManager::EventManager(func* event)
{
    AddComponent(sf::Event::EventType::MouseButtonPressed, sf::Mouse::Left, *event);
}

void EventManager::ManageEvent(sf::Event::EventType eType, sf::Mouse::Button mousePressed)
{
    auto itType = m_cMap.find(eType);
    if (itType == m_cMap.end())
        return;

    auto itMouse = itType->second.find(mousePressed);
    if (itMouse == itType->second.end())
        return;

    itMouse->second();
}
