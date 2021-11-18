/*********************************************************************************
**                                SAKARYA UNIVERSITY
**                    Faculty of Computer and Information Sciences                       
**
**
**
**
**
**
**
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool searchString(string A[], string answer)
{
    int j;
    int isSame = 0;
    for (j = 0; j < 80; j++) {
        if (A[j].compare(answer) == 0) {
            isSame = 1;
        }
    }
    return isSame;
}

int main()
{
    string provinces[81] =
    { "adana","adiyaman","afyon","agri","amasya","ankara","antalya","artvin","aydin","balikesir",
    "bilecik","bingol","bitlis","bolu","burdur","bursa","canakkale","cankiri","corum","denizli","diyarbakir",
    "edirne","elazig","erzincan","erzurum","eskisehir","gaziantep","giresun","gumushane","hakkari","hatay",
    "isparta","mersin","istanbul","izmir","kars","kastamonu","kayseri","kirklareli","kirsehir","kocaeli",
    "konya","kutahya","malatya","manisa","kahramanmaras","mardin","mugla","mus","nevsehir","nigde","ordu","rize"
    "sakarya","samsun","siirt","sinop","sivas","tekirdag","tokat","trabzon","tunceli","sanliurfa","usak","van",
    "yozgat","zonguldak","aksaray","bayburt","karaman","kirikkale","batman","sirnak","bartin","ardahan","igdir",
    "yalova","karabuk","kilis","osmaniye","duzce"
    };

    int greatestLength = provinces[0].length();
    int smallestLength = provinces[0].length();
    for (int i = 0; provinces[i] != "\0"; i++)
    {
        if (provinces[i].length() > greatestLength)
        {
            greatestLength = provinces[i].length();
        }
        if (provinces[i].length() < smallestLength)
        {
            smallestLength = provinces[i].length();
        }
    }
    cout << "Karakter uzunlugu en fazla:" << greatestLength << "tur." << endl;
    cout << "Karakter uzunlugu en kucuk:" << smallestLength << "tur." << endl;
    cout << "Karakter uzunlugu en kucuk sehirler:" << endl;
    for (int i = 0; provinces[i] != "\0"; i++) {
        if (provinces[i].length() == smallestLength)
        {
            cout << provinces[i] << endl;
        }
    }
    cout << "Karakter uzunlugu en buyuk sehirler:" << endl;
    for (int i = 0; provinces[i] != "\0"; i++) {
        if (provinces[i].length() == greatestLength)
        {
            cout << provinces[i] << endl;
            cout << endl;
        }
    }
    bool isFound = 0;
    srand(time(NULL));
    string randomP[3];
    for (int i = 0; !isFound && i < 100000; i++)
    {
        for (int i = 0; i < 3; i++)
        {
            randomP[i] = provinces[rand() % 81];
        }
        string province = "";
        int smallestProvince = provinces[0].length();
        for (int k = 0; k < 3; k++)
        {
            
            if (smallestProvince > randomP[k].length())
            {
                smallestProvince = randomP[k].length();
            }
           
        }
        for (int j = 0; j < smallestProvince; j++)
        {
            province = "";
            for (int i = 0; i < 3; i++)
            {
                province += randomP[i][j];
            }
            if (searchString(provinces, province) == 1)
            {
                cout << "Rastgele 3 harfli sehir bulundu: " << province << endl;
                cout << "Bu sehirlerin" << j + 1 << "." << "indislerinden olusturulmustur." << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << randomP[i] << endl;
                }
                isFound = 1;
            }
        }
    }
    if (!isFound)
    {
        cout << "Rastgele 3 harfli sehir bulunamadi!\a" << endl;
    }
        bool isFound4 = 0;
        string random4[4];
        for (int i = 0; !isFound4 && i < 100000; i++)
        {
            for (int i = 0; i < 4; i++)
            {
                random4[i] = provinces[rand() % 81];
            }

            string province4 = "";
            for (int j = 0; j < 4; j++)
            {
                province4 += random4[j][0];
            }

            if (searchString(provinces, province4) == 1)
            {
                cout << "Rastgele 4 harfli sehir bulundu: " << province4 << endl;
                isFound4 = 1;
            }
        }
        if (!isFound4)
        {
            cout << "Rastgele 4 harfli sehir bulunamadi!\a" << endl;
        }
        bool isFound5 = 0;
        string random5[5];
        for (int i = 0; !isFound5 && i < 100000; i++)
        {
            for (int i = 0; i < 5; i++)
            {
                random5[i] = provinces[rand() % 81];
            }
            string province5 = "";
            for (int j = 0; j < 5; j++)
            {
                province5 += random5[j][0];
            }

            if (searchString(provinces, province5) == 1)
            {
                cout << "Rastgele 5 harfli sehir bulundu: " << province5 << endl;
                isFound5 = 1;
            }
        }
        if (!isFound5)
        {
            cout << "Rastgele 5 harfli sehir bulunamadi!\a" << endl;
        }

        bool isFound6 = 0;
        string random6[6];
        for (int i = 0; !isFound6 && i < 100000; i++)
        {
            for (int i = 0; i < 6; i++)
            {
                random6[i] = provinces[rand() % 81];
            }
            string province6 = "";
            for (int j = 0; j < 6; j++)
            {
                province6 += random6[j][0];
            }

            if (searchString(provinces, province6) == 1)
            {
                cout << "Rastgele 6 harfli sehir bulundu: " << province6 << endl;
                isFound6 = 1;
            }
        }
        if (!isFound6)
        {
            cout << "Rastgele 6 harfli sehir bulunamadi!\a" << endl;
        }
        bool isFound7 = 0;
        string random7[7];
        for (int i = 0; !isFound7 && i < 100000; i++)
        {
            for (int i = 0; i < 7; i++)
            {
                random7[i] = provinces[rand() % 81];
            }
            string province7 = "";
            int smallestProvince = provinces[0].length();
            for (int k = 0; k < 7; k++)
            {

                if (smallestProvince > random7[k].length())
                {
                    smallestProvince = random7[k].length();
                }

            }
            for (int j = 0; j < smallestProvince; j++)
            {
                province7 = "";
                for (int i = 0; i < 7; i++)
                {
                    province7 += random7[i][j];
                }
                if (searchString(provinces, province7) == 1)
                {
                    cout << "Rastgele 3 harfli sehir bulundu: " << province7 << endl;
                    isFound = 1;
                }
            }
        }
        if (!isFound7)
        {
            cout << "Rastgele 7 harfli sehir bulunamadi!\a" << endl;
        }
        bool isFound8 = 0;
        string random8[8];
        for (int i = 0; !isFound8 && i < 100000; i++)
        {
            for (int i = 0; i < 8; i++)
            {
                random8[i] = provinces[rand() % 81];
            }
            string province8 = "";
            for (int j = 0; j < 8; j++)
            {
                province8 += random8[j][0];
            }
            if (searchString(provinces, province8) == 1)
            {
                cout << "Rastgele 8 harfli sehir bulundu: " << province8 << endl;
                isFound8 = 1;
            }
        }
        if (!isFound8)
        {
            cout << "Rastgele 8 harfli sehir bulunamadi!\a" << endl;
        }
        bool isFound9 = 0;
        string random9[9];
        for (int i = 0; !isFound9 && i < 100000; i++)
        {
            for (int i = 0; i < 9; i++)
            {
                random9[i] = provinces[rand() % 81];
            }
            string province9 = "";
            for (int j = 0; j < 9; j++)
            {
                province9 += random9[j][0];
            }

            if (searchString(provinces, province9) == 1)
            {
                cout << "Rastgele 9 harfli sehir bulundu: " << province9 << endl;
                isFound9 = 1;
            }
        }
        if (!isFound9)
        {
            cout << "Rastgele 9 harfli sehir bulunamadi!\a" << endl;
        }
        bool isFound10 = 0;
        string random10[10];
        for (int i = 0; !isFound10 && i < 100000; i++)
        {
            for (int i = 0; i < 10; i++)
            {
                random10[i] = provinces[rand() % 81];
            }
            string province10 = "";
            for (int j = 0; j < 10; j++)
            {
                province10 += random10[j][0];
            }
            if (searchString(provinces, province10) == 1)
            {
                cout << "Rastgele 10 harfli sehir bulundu: " << province10 << endl;
                isFound10 = 1;
            }
        }
        if (!isFound10)
        {
            cout << "Rastgele 10 harfli sehir bulunamadi!\a" << endl;
        }
        bool isFound11 = 0;
        string random11[11];
        for (int i = 0; !isFound11 && i < 100000; i++)
        {
            for (int i = 0; i < 11; i++)
            {
                random11[i] = provinces[rand() % 81];
            }
            string province11 = "";
            for (int j = 0; j < 11; j++)
            {
                province11 += random11[j][0];
            }

            if (searchString(provinces, province11) == 1)
            {
                cout << "Rastgele 11 harfli sehir bulundu: " << province11 << endl;
                isFound11 = 1;
            }
        }
        if (!isFound11)
        {
            cout << "Rastgele 11 harfli sehir bulunamadi!\a" << endl;
        }
        bool isFound12 = 0;
        string random12[12];
        for (int i = 0; !isFound12 && i < 100000; i++)
        {
            for (int i = 0; i < 12; i++)
            {
                random12[i] = provinces[rand() % 81];
            }
            string province12 = "";
            for (int j = 0; j < 12; j++)
            {
                province12 += random12[j][0];
            }

            if (searchString(provinces, province12) == 1)
            {
                cout << "Rastgele 12 harfli sehir bulundu: " << province12 << endl;
                isFound12 = 1;
            }
        }
        if (!isFound12)
        {
            cout << "Rastgele 12 harfli sehir bulunamadi!\a" << endl;
        }
        bool isFound13 = 0;
        string random13[13];
        for (int i = 0; !isFound13 && i < 100000; i++)
        {
            for (int i = 0; i < 13; i++)
            {
                random13[i] = provinces[rand() % 81];
            }
            string province13 = "";
            for (int j = 0; j < 13; j++)
            {
                province13 += random13[j][0];
            }

            if (searchString(provinces, province13) == 1)
            {
                cout << "Rastgele 13 harfli sehir bulundu: " << province13 << endl;
                isFound13 = 1;
            }
        }
        if (!isFound13)
        {
            cout << "Rastgele 13 harfli sehir bulunamadi!\a" << endl;
        }
        system("pause");
        return 0;
        
    }

