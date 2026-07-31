class FizzBuzz {
private:
    int n;
    int current;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        current = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(m);
        while(current <= n) {
            while(current <= n && !(current%3 == 0 && current%5 != 0)){
                cv.wait(lock);
            }
            if(current > n) break;
            printFizz();
            current++;
            cv.notify_all();
        } 
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(m);
        while(current <= n) {
            while(current <= n && !(current%5 == 0 && current%3 != 0)){
                cv.wait(lock);
            }
            if(current > n) break;
            printBuzz();
            current++;
            cv.notify_all();
        } 
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(m);
        while(current <= n) {
            while(current <= n && !(current%3 == 0 && current%5 == 0)){
                cv.wait(lock);
            }
            if(current > n) break;
            printFizzBuzz();
            current++;
            cv.notify_all();
        } 
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        while(current <= n) {
            while(current <= n && (current%3 == 0 || current%5 == 0)){
                cv.wait(lock);
            }
            if(current > n) break;
            printNumber(current);
            current++;
            cv.notify_all();
        } 
    }
};