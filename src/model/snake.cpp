#include "snake.h"

snake::snake(snake::direction _direction) :
    m_direction(_direction)
{
}

void snake::move()
{
    // order matters in case the next element is our own tail
    pop_back();
    push_front(next_element());
}

void snake::eat()
{
    push_front(next_element());
}

position snake::head() const
{
    return m_snake.front();
}

position snake::tail() const
{
    return m_snake.back();
}

void snake::push_front(const position& pos)
{
    m_snake.push_front(pos);
}

std::list<position> snake::elements() const
{
    return m_snake;
}

void snake::set_direction(snake::direction _direction)
{
    if (_direction == m_direction)
        return;

    if (m_direction == direction::left && _direction == direction::right)
        return;

    if (m_direction == direction::right && _direction == direction::left)
        return;

    if (m_direction == direction::up && _direction == direction::down)
        return;

    if (m_direction == direction::down && _direction == direction::up)
        return;

    m_direction = _direction;
}

void snake::clear()
{
    m_snake.clear();
}

void snake::push_back(const position& pos)
{
    m_snake.push_back(pos);
}

void snake::pop_front()
{
    m_snake.pop_front();
}

void snake::pop_back()
{
    m_snake.pop_back();
}

position snake::next_element() const
{
    auto _head = head();

    switch (m_direction)
    {
    case direction::left:
        _head.x--;
        break;

    case direction::right:
        _head.x++;
        break;

    case direction::up:
        _head.y--;
        break;

    case direction::down:
        _head.y++;
        break;
    }

    return _head;
}
