#include "xtimer.h"

XTimer::XTimer(callBack function, TiMER_TYPE type/* = SINGLE*/)
{
    this->function_ = function;

    this->type_ = type;

    this->thread_ = NULL;

    this->privateTimer_ = new boost::asio::deadline_timer(io);
}

XTimer::~XTimer()
{

}

void XTimer::start(int iMsec)
{
    if(!this->thread_)
    {
        this->iMsec_ = iMsec;

        this->thread_ = new std::thread(std::bind(&XTimer::circle, this));
    }

    startPrivateTimer();
}

void XTimer::startPrivateTimer()
{
    privateTimer_->expires_from_now(boost::posix_time::millisec(iMsec_));

    privateTimer_->async_wait(std::bind(&XTimer::handle_wait, this));
}

void XTimer::circle()
{
    boost::asio::io_service::work work(io);

    io.run();
}

void XTimer::handle_wait()
{
    this->function_();

    if(this->type_ == CONTINUDE)
    {
        startPrivateTimer();
    }
}
