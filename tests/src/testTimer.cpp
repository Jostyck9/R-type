/*
** EPITECH PROJECT, 2019
** R-type
** File description:
** testResourceManager.cpp
*/

#include <criterion/criterion.h>
#include "Timer.hpp"

Test(Timer, timer_with_end_time)
{
    ecs::components::Timer timer(1000);
    cr_assert_eq(timer.getEndTime(), 1000);
}

Test(Timer, copy_and_compare)
{
    ecs::components::Timer timer(3000);
    ecs::components::Timer timer1(timer);

    cr_assert_eq(timer1.getEndTime(), 3000);
    cr_assert_eq(timer1 == timer, true);

    ecs::components::Timer timer2;
    cr_assert_eq(timer2 == timer, false);
}

Test(Timer, start_and_stop)
{
    ecs::components::Timer timer(5000);
    timer.start();
    cr_assert_eq(timer.checkEndTimer(), false);
    while (!timer.checkEndTimer());
    timer.stop();
    cr_assert_eq(timer.checkEndTimer(), true);
    cr_assert_eq(timer.getElapsedMilliseconds(), 5000);
}

Test(Timer, restart)
{
    ecs::components::Timer timer;
    cr_assert_eq(timer.isRunning(), false);

    timer.start();
    cr_assert_eq(timer.isRunning(), true);
    timer.stop();

    timer.restart();
    cr_assert_eq(timer.isRunning(), true);
}