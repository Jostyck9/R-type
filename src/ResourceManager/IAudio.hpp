//
// Created by romane on 19/11/2019.
//

#ifndef R_TYPE_IAUDIO_HPP
#define R_TYPE_IAUDIO_HPP

class IAudio {
public:

    virtual const std::string &getName() = 0;
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void pause() = 0;
    virtual void loop(bool state) = 0;
};


#endif //R_TYPE_IAUDIO_HPP