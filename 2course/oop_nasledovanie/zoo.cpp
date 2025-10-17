#include <string>

using std::string;

class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class ZooKeeper {
private:
    int n_dangerous_;

public:
    // Создаём смотрителя зоопарка
    ZooKeeper() {
        n_dangerous_ = 0;
    }

    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal* a) {
        if (a->isDangerous()) {
            n_dangerous_++;
        }
    }

    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount() {
        return n_dangerous_;
    }
};
