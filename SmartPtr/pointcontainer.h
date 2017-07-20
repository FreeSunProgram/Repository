#ifndef POINTCONTAINER_H
#define POINTCONTAINER_H


class PointContainer
{
public:
    PointContainer();

    // 递增计数，并且返回计数
    int Increase(long address)
    {
        int count = 0;

        if(addressContainer_.find(address) != addressContainer_.end())
        {
            count = ++addressContainer_[address];
        }
        else
        {
            addressContainer_[address] = 1;

            count = 1;
        }
#ifdef PTR_DEBUG
        std::cout << "address:" << address << " count:" << count << std::endl;
        std::cout << "addressContainer count:" << addressContainer_.size() << std::endl;
#endif

        return count;
    }


    // 递减计数，并且返回计数
    int Degression(long address)
    {
        int count = 0;

        if(addressContainer_.find(address) != addressContainer_.end())
        {
            count = --addressContainer_[address];

            if(count <= 0)
            {
                addressContainer_.erase(address);
            }

#ifdef PTR_DEBUG
        std::cout << "address:" << address << " count:" << count << std::endl;
#endif
        }

        return count;
    }
};

#endif // POINTCONTAINER_H
