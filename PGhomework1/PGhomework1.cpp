/******************************************************************************************
**                                SAKARYA UNIVERSITY
**                    FACULTY OF COMPUTER AND INFORMATION SCIENCES
**                               COMPUTER ENGINEERING
**                           INTRODUCTION TO PROGRAMMING
**
**                          HOMEWORK NUMBER : 1
**                          STUDENT'S NAMES : İSMAİL METE UÇAR
**                          STUDENT'S NUMBERS : G201210051
**                          LESSON GROUP : 2C
*******************************************************************************************/

//Added necessary library.
#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Created a function for check the words that created randomly if they are city or not.
bool searchString(string A[], string answer) 
{
    int j;
    int isSame = 0;
    //A loop for check each city.
    for (j = 0; j < 80; j++)
    {
        if (A[j].compare(answer) == 0)
        {
            isSame = 1;
        }
    }
    return isSame;
}

int main()
{
    //Created an array for all the cities.
    string provinces[81] =
    { "adana","adiyaman","afyonkarahisar","agri","amasya","ankara","antalya","artvin","aydin","balikesir",
    "bilecik","bingol","bitlis","bolu","burdur","bursa","canakkale","cankiri","corum","denizli","diyarbakir",
    "edirne","elazig","erzincan","erzurum","eskisehir","gaziantep","giresun","gumushane","hakkari","hatay",
    "isparta","mersin","istanbul","izmir","kars","kastamonu","kayseri","kirklareli","kirsehir","kocaeli",
    "konya","kutahya","malatya","manisa","kahramanmaras","mardin","mugla","mus","nevsehir","nigde","ordu","rize",
    "sakarya","samsun","siirt","sinop","sivas","tekirdag","tokat","trabzon","tunceli","sanliurfa","usak","van",
    "yozgat","zonguldak","aksaray","bayburt","karaman","kirikkale","batman","sirnak","bartin","ardahan","igdir",
    "yalova","karabuk","kilis","osmaniye","duzce"
    };

    //Created variables for shortest and longest city names.
    int greatestLength = provinces[0].length();
    int smallestLength = provinces[0].length();

    //A loop for check the cities if they are the shortest or the longest city names.
    for (int i = 0; i < 81; i++)
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

    cout << "The longest character length is:" << greatestLength << endl;
    cout << "The shortest character length is:" << smallestLength  << endl;
    cout << "Character length smallest cities:" << endl;

    //A loop for print the shortest city name to the console.
    for (int i = 0; i < 81; i++) {
        if (provinces[i].length() == smallestLength)
        {
            cout << provinces[i] << endl;
        }
    }

    cout << "Character length biggest cities:" << endl;

    //A loop for print the longest city name to the console.
    for (int i = 0; i < 81; i++) {
        if (provinces[i].length() == greatestLength)
        {
            cout << provinces[i] << endl;
            cout << endl;
        }
    }

    srand(time(NULL));

    bool isFound = false;   //Created a bool for if the random word is a city or not.
    string randomP[14];     //Created an array for random words.

    //A loop for use the program for length of each cities.
    for (int characterNumber = smallestLength; characterNumber <= greatestLength; characterNumber++)
    {
        isFound = false;

        //A loop for try all the possibilities for 100000 times. If loop found a city name, loop will be broken.
        for (int i = 0; !isFound && i < 100000; i++)
        {
            //A loop for pick random province.
            for (int i = 0; i < characterNumber; i++)
            {
                randomP[i] = provinces[rand() % 81];
            }
            //Created a string for keep random words.
            string province = "";
            int smallestProvince = provinces[0].length();
            //A loop for find the shortest random province (So that we can look indexes of all cities) . // sehirlerin butun indislerine bakabilmemiz icin  So that we can look cities of all index
            for (int k = 0; k < characterNumber; k++)
            {

                if (smallestProvince > randomP[k].length())
                {
                    smallestProvince = randomP[k].length();
                }

            }
            for (int j = 0; j < smallestProvince; j++)
            {
                province = "";
                //A loop for created city from index of random cities
                for (int i = 0; i < characterNumber; i++)
                {
                    province += randomP[i][j];
                }

                if (searchString(provinces, province) == 1)
                {
                    cout << "A random city with " << characterNumber << " letters has been found. " << "The cities is found : " << province << endl;
                    //A loop for print the cities that we used it to pick indexes.
                    for (int i = 0; i < characterNumber; i++)
                    {
                        cout << randomP[i] << endl;
                    }
                    cout << "the random city is created from " << j + 1 << "th" << " index of random " << characterNumber << " cities." << endl;
                    cout << endl;
                    isFound = 1;
                }
            }
        }
        if (!isFound)
        {
            cout << "Couldn't found random city with " << characterNumber << " letters!\a" << endl;
        }
    }

    system("pause");
    return 0;
}