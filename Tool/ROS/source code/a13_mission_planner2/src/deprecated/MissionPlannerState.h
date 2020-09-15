#ifndef MISSIONPLANNERSTATE_H
#define MISSIONPLANNERSTATE_H

enum MissionPlannerState: uint8_t {
    state_landed,
    state_takingOff,
    state_hovering,
    state_flying,
    state_landing,
    state_emergency,
    state_userTakeOff,
    state_motorRamping,
    state_emergencyLanding
};

#endif