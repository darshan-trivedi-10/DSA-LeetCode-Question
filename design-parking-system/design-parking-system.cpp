class ParkingSystem {
    private : 
    int parkingCheck[4];

public:
    ParkingSystem(int big, int medium, int small) {
        parkingCheck[1] = big;
        parkingCheck[2] = medium;
        parkingCheck[3] = small; 
    }

    
    bool addCar(int carType) {
        return parkingCheck[carType]-- > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */