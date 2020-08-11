const int MOTOR_FL = 6;
const int MOTOR_FR = 10;
const int MOTOR_BL = 5;
const int MOTOR_BR = 9;

const int MOTOR_ARRAY[4] = {MOTOR_FL,
                            MOTOR_FR,
                            MOTOR_BL,
                            MOTOR_BR};

const int MOTOR_DUTY_CYCLE = 25;  // 0 ~ 255

const int MOTOR_FL_SUPPLEMENT_MULTIPLIER = 1;
const int MOTOR_FR_SUPPLEMENT_MULTIPLIER = 1;
const int MOTOR_BL_SUPPLEMENT_MULTIPLIER = 1;
const int MOTOR_BR_SUPPLEMENT_MULTIPLIER = 1;

const int MOTOR_FL_SUPPLEMENT_ADDER = 0;
const int MOTOR_FR_SUPPLEMENT_ADDER = 0;
const int MOTOR_BL_SUPPLEMENT_ADDER = 0;
const int MOTOR_BR_SUPPLEMENT_ADDER = 0;
                            
const int MOTOR_SUPPLEMENT_MULTIPLIER_ARRAY[4] = {MOTOR_FL_SUPPLEMENT_MULTIPLIER,
                                                  MOTOR_FR_SUPPLEMENT_MULTIPLIER,
                                                  MOTOR_BL_SUPPLEMENT_MULTIPLIER,
                                                  MOTOR_BR_SUPPLEMENT_MULTIPLIER};
                            
const int MOTOR_SUPPLEMENT_ADDER_ARRAY[4] = {MOTOR_FL_SUPPLEMENT_ADDER,
                                             MOTOR_FR_SUPPLEMENT_ADDER,
                                             MOTOR_BL_SUPPLEMENT_ADDER,
                                             MOTOR_BR_SUPPLEMENT_ADDER};

const int MOTOR_DUTYCYCLE_ARRAY[4] = {MOTOR_DUTY_CYCLE * MOTOR_SUPPLEMENT_MULTIPLIER_ARRAY[0] + MOTOR_SUPPLEMENT_ADDER_ARRAY[0],
                                      MOTOR_DUTY_CYCLE * MOTOR_SUPPLEMENT_MULTIPLIER_ARRAY[1] + MOTOR_SUPPLEMENT_ADDER_ARRAY[1],
                                      MOTOR_DUTY_CYCLE * MOTOR_SUPPLEMENT_MULTIPLIER_ARRAY[2] + MOTOR_SUPPLEMENT_ADDER_ARRAY[2],
                                      MOTOR_DUTY_CYCLE * MOTOR_SUPPLEMENT_MULTIPLIER_ARRAY[3] + MOTOR_SUPPLEMENT_ADDER_ARRAY[3]};

void setup() {
    for (int i = 0; i < 4; ++i) {
        analogWrite(MOTOR_ARRAY[i], MOTOR_DUTYCYCLE_ARRAY[i]);.
        ....0
        
    }
}

void loop() {
}
