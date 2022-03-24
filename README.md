# C++RampUp

## 1.Strings 
- `string` in cpp ends with '\0', much easier to check the end of a string,.
- `s.find(t)` will return the start index of the first found substring;
- `s.find(t, i)` will do the find action starting from index of i (inclusive)
- `s.substr(startI, n)` return the substring starting at startI, of length of n
- `getline(inStream, s)` to read in one line from inStream, and put data into s;
- 

## 2.Numbers 
- c++ offers autocasting, `int x = 5.5` will result in x = 5; `double x = 5` will result in x = 5.0
- `pow(x, y)` returns x ^ y;
- `round(x)` will return the closest int, `round(4.5)` will result in 5;
- `floor(x)` and `ceil(x)` will result in lower int and upper int respectively;
- `fmax(a,b)` and `fmin(a,b)`, find max and min among a and b;
- `int nums[20] = {1,2,3,4,5}` can instantiate a int array with literals;

## 3. Class and Objects
```c++
#include <iostream>
#include <cmath>
using namespace std;

class Book {
    public:
        string title;
        string author;
        int pages;

    Book(string title, string author, int pages){
        this->title = title;
        this->author = author;
        this->pages = pages;
    }
    string toString(void){
        string out = "title: " + title;
        return out;
    }
};
int main(){
    Book newBook("tryout","troyPeng", 500);
    cout << newBook.toString();
    return 0;
}
```
- can define declared function outside the class:
```c++
class Book {
    public:
        string title;
        string author;
        int pages;

    Book(string title, string author, int pages){
        this->title = title;
        this->author = author;
        this->pages = pages;
    }
    string toString(void){
        string out = "title: " + title;
        return out;
    }

    int getPages(void);
};

int Book::getPages(void){
    return pages;
}

```

## Inheritance
```c++
class chef {
public:
    void makeChicken();
    void makeBeef();
};

class ItalianChef : public chef {
    
};
```


