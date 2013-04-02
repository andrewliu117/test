/*
 * http://www.cnblogs.com/08shiyan/archive/2012/03/16/2399617.html
 * 单例模式 Singleton
 *
*/
#include <stdio.h>

class Singleton
{
    public:
        static Singleton * Instance()
        {
            if( 0 == _instance)
            {
                _instance = new Singleton();
            }
            return _instance;
        }
        void print(){
            printf("i is %d\n", i);
        }
        static void initial(){
            if( 0== _instance)
            {
                _instance = new Singleton;
            }
            _instance->i = 5;
        }
        void seti(int si ){
            i = si;
        }
    protected:
        Singleton(void)
        {
        }
        virtual ~Singleton(void)
        {
        }
        static Singleton* _instance;
        int i;
};

Singleton* Singleton::_instance;

int main(void)
{
    //Singleton::Instance()->initial();
    (Singleton::Instance())->print();
    (Singleton::Instance())->seti(6);
    (Singleton::Instance())->print();
}
