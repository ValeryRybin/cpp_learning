class GasHolder
{
private:
    float P_;
    float nu_;
    float temperature_;
    float V_;
    const float R_ = 8.31;

public:
    GasHolder(float v) : P_(0), nu_(0), temperature_(273), V_(v) {}

    // ~GasHolder();

    void inject(float m, float M)
    {
        nu_ += m / M;
        P_ = nu_ * temperature_ * R_ / V_;
    }

    void heat(float dT)
    {
        temperature_ += dT;
        P_ = nu_ * temperature_ * R_ / V_;
    }

    void cool(float dT)
    {
        temperature_ -= dT;
        if (temperature_ < 0)
            temperature_ = 0;
        P_ = nu_ * temperature_ * R_ / V_;
    }

    float getPressure()
    {
        return P_;
    }
};