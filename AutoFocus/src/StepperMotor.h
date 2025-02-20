#include <wiringPi.h>

namespace Autofocus
{
    struct StepperPins
    {
        unsigned int step;
        unsigned int en;
        unsigned int dir;
        bool ms1;
        bool ms2;
    };
    
    class StepperMotor
    {
    public:
        StepperMotor(StepperPins pins);
        void SetGPIOPins(StepperPins pins);
        void RunMotor(int direction, unsigned int angle, unsigned int speed);
        inline StepperPins GetGPIO() { return m_pins; }
    private:
        void SetupPins();
        float SpeedTransition(float delay, int currentStep, int totalStep); 
    private:
        StepperPins m_pins;
        float m_stepFactor;
    };
}