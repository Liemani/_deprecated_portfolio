#include "Mission_CrossMove.h"

#define CALI_FINISH_LINE 0.01
#define DEADLINE 0.1
#define LINEARSPEED 0.3
#define HEIGHT_DIFFERENCE 0.5

Mission_CrossMove::Mission_CrossMove(double targetAltitude) {
    target_altitude = targetAltitude;
}

// return value:
//  true: end this mission
//  false: on going
// description:
//  drone[0] is left
//  drone[1] is center
//  drone[2] is right
bool Mission_CrossMove::perform(std::vector<Drone*>& pDrone_vector) {
    // if drone number is not 3, end mission
    if (pDrone_vector.size() != 3) return true;
    // if is there a drone not yet ready, return false
    for (int i = 0; i < 3; ++i) if (!pDrone_vector[i]->isReady()) return false;

    static bool arrivedTargetAltitude_left = false;
    static bool arrivedTargetAltitude_center = false;
    static bool arrivedTargetAltitude_right = false;

    static bool arrivedTop_left = false;
    static bool arrivedBottom_right = false;

    static bool waiting_left = false;
    static bool waiting_right = false;



    if (waiting_left && waiting_right) {
        waiting_left = false;
        waiting_right = false;
    }



    static double altitude = pDrone_vector[0]->getAltitude();
    static double gap = target_altitude - altitude;
    if(arrivedTargetAltitude_left == false) {
        if (abs(gap) > DEADLINE) {
            if (gap > 0) {
                pDrone_vector[0]->fly(0.0, 0.0, +LINEARSPEED, 0.0);
            } else {
                pDrone_vector[0]->fly(0.0, 0.0, -LINEARSPEED, 0.0);
            }
        } else if (abs(gap) > CALI_FINISH_LINE) {
            pDrone_vector[0]->fly(0.0, 0.0, target_altitude - altitude, 0.0);
        } else {
            pDrone_vector[0]->hover();
            arrivedTargetAltitude_left = true;
        }
    } else if(arrivedTargetAltitude_left
        && arrivedTargetAltitude_center
        && arrivedTargetAltitude_right
        && (!arrivedTop_left && !waiting_left))
    {
        gap = gap + 0.5;

        if (abs(gap) > DEADLINE) {
            if (gap > 0) {
                pDrone_vector[0]->fly(0.0, 0.0, +LINEARSPEED, 0.0);
            } else {
                pDrone_vector[0]->fly(0.0, 0.0, -LINEARSPEED, 0.0);
            }
        } else if (abs(gap) > CALI_FINISH_LINE) {
            pDrone_vector[0]->fly(0.0, 0.0, gap, 0.0);
        } else {
            pDrone_vector[0]->hover();
            arrivedTargetAltitude_left = true;
            waiting_left = true;
        }
    } else if(arrivedTargetAltitude_left
        && arrivedTargetAltitude_center
        && arrivedTargetAltitude_right
        && (arrivedTop_left && !waiting_left))
    {
        gap = gap - 0.5;

        if (abs(gap) > DEADLINE) {
            if (gap > 0) {
                pDrone_vector[0]->fly(0.0, 0.0, +LINEARSPEED, 0.0);
            } else {
                pDrone_vector[0]->fly(0.0, 0.0, -LINEARSPEED, 0.0);
            }
        } else if (abs(gap) > CALI_FINISH_LINE) {
            pDrone_vector[0]->fly(0.0, 0.0, gap, 0.0);
        } else {
            pDrone_vector[0]->hover();
            arrivedTargetAltitude_left = true;
            waiting_left = true;
        }
    }



    altitude = pDrone_vector[1]->getAltitude();
    gap = target_altitude - altitude;
    if (arrivedTargetAltitude_center == false) {
        if (abs(gap) > DEADLINE) {
            if (gap > 0) {
                pDrone_vector[1]->fly(0.0, 0.0, +LINEARSPEED, 0.0);
            } else {
                pDrone_vector[1]->fly(0.0, 0.0, -LINEARSPEED, 0.0);
            }
        } else if (abs(gap) > CALI_FINISH_LINE) {
            pDrone_vector[1]->fly(0.0, 0.0, target_altitude - altitude, 0.0);
        } else {
            pDrone_vector[1]->hover();
            arrivedTargetAltitude_left = true;
        }
    }



    altitude = pDrone_vector[2]->getAltitude();
    gap = target_altitude - altitude;
    if(arrivedTargetAltitude_right == false) {
        if (abs(gap) > DEADLINE) {
            if (gap > 0) {
                pDrone_vector[2]->fly(0.0, 0.0, +LINEARSPEED, 0.0);
            } else {
                pDrone_vector[2]->fly(0.0, 0.0, -LINEARSPEED, 0.0);
            }
        } else if (abs(gap) > CALI_FINISH_LINE) {
            pDrone_vector[2]->fly(0.0, 0.0, target_altitude - altitude, 0.0);
        } else {
            pDrone_vector[2]->hover();
            arrivedTargetAltitude_left = true;
        }
    } else if(arrivedTargetAltitude_left
        && arrivedTargetAltitude_center
        && arrivedTargetAltitude_right
        && (!arrivedBottom_right && !waiting_right))
    {
        gap = gap + 0.5;

        if (abs(gap) > DEADLINE) {
            if (gap > 0) {
                pDrone_vector[2]->fly(0.0, 0.0, +LINEARSPEED, 0.0);
            } else {
                pDrone_vector[2]->fly(0.0, 0.0, -LINEARSPEED, 0.0);
            }
        } else if (abs(gap) > CALI_FINISH_LINE) {
            pDrone_vector[2]->fly(0.0, 0.0, gap, 0.0);
        } else {
            pDrone_vector[2]->hover();
            arrivedTargetAltitude_left = true;
            waiting_right = true;
        }
    } else if(arrivedTargetAltitude_left
        && arrivedTargetAltitude_center
        && arrivedTargetAltitude_right
        && (arrivedBottom_right && !waiting_right))
    {
        gap = gap - 0.5;

        if (abs(gap) > DEADLINE) {
            if (gap > 0) {
                pDrone_vector[2]->fly(0.0, 0.0, +LINEARSPEED, 0.0);
            } else {
                pDrone_vector[2]->fly(0.0, 0.0, -LINEARSPEED, 0.0);
            }
        } else if (abs(gap) > CALI_FINISH_LINE) {
            pDrone_vector[2]->fly(0.0, 0.0, gap, 0.0);
        } else {
            pDrone_vector[2]->hover();
            arrivedBottom_right = true;
            waiting_right = true;
        }
    }
}