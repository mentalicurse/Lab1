#include <iostream>
#include <typeinfo>
#include <memory>
using namespace std;
class AbstractEntity {
public:
    virtual ~AbstractEntity() = default;  // Виртуальный деструктор для полиморфизма
};

class AccountEntity : public AbstractEntity {};

class RoleEntity : public AbstractEntity {};

class Repository {

};

class IRepository {
public:
    virtual ~IRepository() = default;
    virtual void Save(AbstractEntity* entity) = 0;
}
;

class AccountRepository :public IRepository {
    void Save(AbstractEntity* entity) override {
        cout << "специфические действия для AccountEntity" << endl;
    }
};

class RoleRepository :public IRepository {
    void Save(AbstractEntity* entity) override {
        cout << "специфические действия для RoleEntity" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    AccountEntity entity;
    RoleEntity ent;
    IRepository* rep_acc = new AccountRepository();
    IRepository* rep_role = new RoleRepository();
    rep_acc->Save(&entity);
    rep_role->Save(&ent);
    delete rep_acc;
    delete rep_role;
    return 0;
}
