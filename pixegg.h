// pixegg.h
#include <Servo.h>
#include <NewPing.h>

class Pixegg
{
public:
    Pixegg();

    void Start();

    void Loop();

    struct Params
    {
        int m_servoPwmPin = 3;
        int m_urfTrigPwmPin = 2;
        int m_urfEchoPwmPin = 4;
        int m_maxDistanceCm = 200;
        int m_torque = 120;
    } m_params;

private:
    void Close();
    void Open();
    void ResetServo();

    Servo m_servo;
    NewPing m_ping;
    
};
