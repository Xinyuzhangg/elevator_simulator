#pragma once

#include <SDL.h>
#include "Passenger.h"
#include <stack>
#include <queue>
#include <vector>
#include <map>

extern int ElevatorLoad;
extern int ElevatorSpeed;
extern int DoorTime;
extern int TransitionTime;

enum class ElevatorMove { Idle, Up, Down };
enum class ElevatorStatus { Opened, Opening, Closed, Closing, Moving };
enum Action {PassengerInOut, ElevatorUpDown, ElevatorOpenClose};

class BookedFloor {
private:
	int bookedFloor;
	bool buttonUp;
public:
	BookedFloor(int bookedFloor, bool buttonUp) : bookedFloor(bookedFloor), buttonUp(buttonUp) {};
	friend bool operator == (const BookedFloor& b1, const BookedFloor& b2);
};


class Elevator {

	

private:
	ElevatorStatus curStatus;
	std::deque<int> targetFloor;
	std::map<int, std::stack<Passenger>> passengerInElevator;
	static int capacity;
	int curLoad;
	int internalTimer;
	ElevatorMove curMove;
	int curFloor;

	

public:
	Elevator(int startFloor);
	void MoveElevator(int curTime, std::map<int, std::deque<Passenger>> &waitingPassengers, std::deque<BookedFloor> &bookedFloors);
	int CurFloor();
	ElevatorMove CurMove();
	ElevatorStatus CurStatus();
	int InternalTimer();
	int PassengerInElevator();

private:
	void TakeTime(ElevatorMove move, int curTime, std::map<int, std::deque<Passenger>>& waitingPassengers, std::deque<BookedFloor>& bookedFloors);
	bool Overloaded();
	void TickTimer();
	void SetTimer(Action action);
	bool IsReady();
	bool IfPassengerOut();
	bool IfPassengerIn(std::map<int, std::deque<Passenger>>& waitingPassengers);
	void TakeOutPassenger();
	void LoadPassenger(Passenger& p);
	void TakeInPassenger(std::map<int, std::deque<Passenger>>& waitingPassengers);
	bool IsTarget();
	bool GoingUp();
	void BookFloor(std::map<int, std::deque<Passenger>>& waitingPassengers, std::deque<BookedFloor>& bookedFloors);
	bool IsFloorBooked(BookedFloor& floor, std::deque<BookedFloor>& bookedFloors);
	void RefreshBookedFloor(std::deque<BookedFloor>& bookedFloors);
	void popTarget();
	void loadTarget(int target);
	void SetDirection();
	
};
