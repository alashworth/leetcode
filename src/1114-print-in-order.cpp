#include <condition_variable>
#include <functional>
#include <mutex>

using namespace std;

void printFirst(){};
void printSecond(){};
void printThird(){};

class Foo {
   private:
    int cnt = 0;
    mutex mtx;
    condition_variable cv;

   public:
    void first(const function<void()>& printFirst) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this]() { return cnt == 0; });
        printFirst();
        ++cnt;
        cv.notify_all();
    }

    void second(const function<void()>& printSecond) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this]() { return cnt == 1; });
        printSecond();
        ++cnt;
        cv.notify_all();
    }

    void third(const function<void()>& printThird) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this] { return cnt == 2; });
        printThird();
        ++cnt;
        cv.notify_all();
    }
};