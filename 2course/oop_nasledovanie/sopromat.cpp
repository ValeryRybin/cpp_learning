class Material
{
public:
    // Принимает на вход величину деформации.
    // Возвращает величину напряжения, посчитанную с учётом реологии материала.
    virtual float getStress(float strain) = 0;
};

class ElasticMaterial : public Material
{
private:
    float elasticModulus;

public:
    ElasticMaterial(float elasticModulus)
    {
        this->elasticModulus = elasticModulus;
    }
    float getStress(float strain)
    {
        return (this->elasticModulus) * strain;
    }
};

class PlasticMaterial : public Material
{
private:
    float elasticModulus;
    float strainLimit;

public:
    PlasticMaterial(float elasticModulus, float strainLimit)
    {
        this->elasticModulus = elasticModulus;
        this->strainLimit = strainLimit;
    }
    float getStress(float strain)
    {
        if (strain > this->strainLimit)
            return this->elasticModulus * this->strainLimit;
        else
            return this->elasticModulus * strain;
    }
};
