#ifndef XTIMER_H
#define XTIMER_H

#include <functional>
#include <thread>
#include <boost/asio/deadline_timer.hpp>

typedef std::function<void()> callBack;

/**
* @brief 摘要
* @author 程序猿某人
* @date 2017/02/08
*/
class XTimer
{
public:

    // 定时器种类
    enum TiMER_TYPE
    {
        CONTINUDE = 0,
        SINGLE
    };

    XTimer(callBack function, TiMER_TYPE type = SINGLE);

    ~XTimer();

    // 开始定时
    void start(int iMsec);

    // 结束定时
    void stop();

    // 重启定时
    void restart();

private:

    void circle();

    void handle_wait();

    void startPrivateTimer();

private:

    std::thread *thread_;

    callBack function_;

    TiMER_TYPE type_;

    boost::asio::io_service io;

    boost::asio::deadline_timer *privateTimer_;

    int iMsec_;
};

#endif // XTIMER_H
