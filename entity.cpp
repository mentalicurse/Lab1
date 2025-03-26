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
    if (typeid(*entity) == typeid(AccountEntity))
        cout << "специфические действия для AccountEntity" << endl;
    else cout << "неверный входной параметр, нужен тип AccountEntity,а используется " << typeid(*entity).name() <<endl;
}
};

class RoleRepository :public IRepository {
    void Save(AbstractEntity* entity) override {
    if (typeid(*entity) == typeid(RoleEntity))
        cout << "специфические действия для RoleEntity" << endl;
    else cout << "неверный входной параметр, нужен тип RoleEntity,а используется "<< typeid(*entity).name() <<endl;
}
};

int main() {
    setlocale(LC_ALL, "Rus");
    AccountEntity entity;    
    RoleEntity role;
    IRepository* rep_acc = new AccountRepository();
    IRepository* rep_role = new RoleRepository();
    rep_acc->Save(&role);
    rep_acc->Save(&entity);
    rep_role->Save(&role);
    delete rep_acc;
    delete rep_role;
    return 0;
}
