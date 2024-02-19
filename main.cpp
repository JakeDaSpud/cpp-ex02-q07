#include <iostream>
#include <random>
#include <ctime>

//Write a function sumRandom(start, end) that will generate 100 random integers in the
//range start -> end, (e.g. 20->200) and return the sum of the numbers.
//https://en.cppreference.com/w/cpp/numeric/random/rand

int sumRandom(int start, int end) {
    int num = 0, sum = 0;

    //std::rand() only pseudo-random, i want more random, so i set the rand() seed using ctime and getting the current
    //time, then seeding with srand()
    std::srand((int) std::time(0));

    for (int i = 0; i < 100; i++) {
        //reset num so it will work on next loop
        num = start - 1;

        //num is more than or equal to high end range
        //OR
        //num is less than the start range
        while (!(num < end && num >= start)) {
            //std::rand() only pseudo-random, i want more random, so i set the rand() seed using ctime and getting the
            //current time, then seeding with srand()
            num = std::rand();
        }

        //uncomment this to see all printout
        //std::cout << sum << ": +" << num << std::endl;
        sum = sum + num;

    }

    return sum;
}

int main() {
    int start, end, sum;

    std::cout << "Enter start range: " << std::endl;
    std::cin >> start;
    std::cout << "Enter end range: " << std::endl;
    std::cin >> end;

    sum = sumRandom(start, end);
    std::cout << "Final Sum: " << sum << std::endl;

    return 0;
}
