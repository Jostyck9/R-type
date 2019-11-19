#ifndef __TASK_HPP__
# define __TASK_HPP__

template<typename T>
class Data
{
private:

public:
    Data();
    ~Data();
};

template<typename T>
class Task {
private:
    T (*job)(...) task;
    Data _data;
public:
    Task();
    ~Task();



};

#endif // !__TASK_HPP__
