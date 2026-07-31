class Semaphore {
    mutex m;
    condition_variable cv;
    int count;
public:
    Semaphore(int n = 0): count(n) {}
    void setCount(int n) {
        count = n;
    }
    void wait() {
        unique_lock<mutex> lock(m);
        while(count == 0) {
            cv.wait(lock);
        }
        count--;
    }

    void signal() {
        unique_lock<mutex> lock(m);
        count++;
        cv.notify_one();
    }
};


class DiningPhilosophers {
    mutex fork[5];
    Semaphore room; 
public:
    DiningPhilosophers() {
        room.setCount(4);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int left = philosopher;
        int right = (philosopher+1)%5;

        room.wait();

        fork[left].lock();
        fork[right].lock();

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        fork[left].unlock();
        fork[right].unlock();

        room.signal();
    }
};