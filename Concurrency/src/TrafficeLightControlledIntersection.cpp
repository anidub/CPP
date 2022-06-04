#include <iostream>
/*
class TrafficLight {
std::mutex mtx;
int greenRoad;

public:
TrafficLight() {
	greenRoad = 1;
}
//https://leetcode.com/problems/traffic-light-controlled-intersection/discuss/1548247/C%2B%2B-Mutex-and-lock_guard
// THIS SOLUTION IS FOR ONE CAR AT A TIME!
void carArrived(
    int carId,                   // ID of the car
    int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
    int direction,               // Direction of the car
    function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
    function<void()> crossCar    // Use crossCar() to make car cross the intersection
) {
	{ //begin of critical section
		std::unique_lock lk(mtx);
		if(greenRoad != roadId) {
			turnGreen();
			greenRoad = roadId;
		}
		crossCar();
	} //end of critical section
}
};

//https://leetcode.com/problems/traffic-light-controlled-intersection/discuss/1865131/C%2B%2B-Easy-solution-allows-multiple-cars-at-the-same-time
class TrafficLightMultiple {//
//THIS SOLUTION IS AS MANY CAR ON CURRENT ROAD DIRECTION
	std::mutex mtx;
	std::conditional_variable cv;
	volatile int cur_cnt = 0, cur_road = 1;

public:

void carArrived(
    int carId,                   // ID of the car
    int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
    int direction,               // Direction of the car
    function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
    function<void()> crossCar    // Use crossCar() to make car cross the intersection
) {

	{
		std::unique_lock<std::mutex> lk(mtx);

		if(cur_road != roadId) {
			while(cur_road != roadId && cur_cnt > 0) {
				cv.wait(lk);
			}
			if(cur_road != roadId) {
				cur_road = roadId;
				turnGreen();
			}
		}
	}
	crossCar();

	{
		std::unique_lock<std::mutex> lk(mtx);
		--cur_cnt;
		if(cur_cnt == 0){
			cv.notify_all();
		}
	}
}

};*/
