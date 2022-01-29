// pixegg.cpp

#include "Pixegg.h"

Pixegg::Pixegg()
    : m_ping(m_params.m_urfTrigPwmPin,
        m_params.m_urfEchoPwmPin,
        m_params.m_maxDistanceCm)
{
}

void Pixegg::Start()
{
    ResetServo();
}

void Pixegg::Loop()
{
    const auto closedCm = m_ping.ping_cm();
    if (closedCm > 10 && closedCm < 30)
    {
        Open();
        int openCm = -1;
        do
        {
            openCm = m_ping.ping_cm();
            delay(1000);
        } while (openCm != 0 && openCm < 30);
        Close();
    }
}

void Pixegg::Close()
{
    ResetServo();
}

void Pixegg::Open()
{
    m_servo.attach(m_params.m_servoPwmPin);
    m_servo.write(m_params.m_torque);
    delay(2000);
    m_servo.detach();
    delay(2000);
}

void Pixegg::ResetServo()
{
    m_servo.attach(m_params.m_servoPwmPin);
    m_servo.write(0);
    delay(2000);
    m_servo.detach();
    delay(2000);
}
