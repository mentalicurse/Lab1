#include <iostream>
#include <locale.h>
using namespace std;

class Image {
public:
    Image() { //cout << "Constructor Image" << endl;
    };
    ~Image() { //cout << "Destructor Image" << endl; 
    };
};

class Account {
public:
    Account() { //cout << "Constructor Account" << endl; 
    };
    ~Account() { //cout << "Destructor Account" << endl; 
    };
};

class Url {
public:
    Url() { //cout << "Constructor Url" << endl; 
    };
    ~Url() { //cout << "Destructor Url" << endl; 
    };
};

class ImageManage {
public:
    static void Save(Image& image) {
        cout << " сохранение изображение в файловой системе " << endl;
    }
    static int DeleteDuplicates() {
        cout << " удалить из файловой системы все дублирующиеся изображения и вернуть количество удаленных " << endl;
        return 0;
    }
};

class ImageSet {
public:
    static Image SetImageAsAccountPicture(Image& image, Account& account) {
        cout << " запрос к базе данных для сохранения ссылки на это изображение для пользователя " << endl;
        return image;
    }
};

class ImageChange {
public:
    static Image Resize(Image image, int height, int width) {
        cout << " изменение размеров изображения " << endl;
        return image;
    }
    static Image InvertColors(Image image) {
        cout << " изменить цвета на изображении " << endl;
        return image;
    }
};

class ImageDownload {
public:
    static  byte* Download(Url& imageUrl) {
        static byte* mass;
        cout << " загрузка битового массива с изображением с помощью HTTP запроса " << endl;
        return mass;
    }
};



int main() {
    setlocale(LC_ALL, "Rus");
    Image image;
    Url imUrl;
    Account account;
    int height = 0; int width = 0;
    ImageManage::Save(image);
    ImageManage::DeleteDuplicates();
    ImageSet::SetImageAsAccountPicture(image, account);
    ImageChange::Resize(image, height, width);
    ImageChange::InvertColors(image);
    ImageDownload::Download(imUrl);
    return 0;
}
