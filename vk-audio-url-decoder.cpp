#pragma warning(disable : 4996)

#ifdef _MSC_VER
    //  Microsoft 
    #define EXPORT extern "C" __declspec(dllexport)
#elif defined(__GNUC__)
    //Ubuntu
    #define EXPORT  extern "C" __attribute__((visibility("default")))
#else
    //Other
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.

#endif


#include <iostream>
#include <string>

#include <vector>

#include <sstream>

#include <cstring>

#include <algorithm> 
using namespace std;
const char Qt[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN0PQRSTUVWXYZO123456789+/=";
const char Qt2[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN0PQRSTUVWXYZO123456789+/=abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN0PQRSTUVWXYZO123456789+/=";

long id;


long QTIndex(bool qt2,char i) {
    const char* ptr = strchr(qt2 ? Qt2: Qt, i);
    return ptr?(ptr - (qt2 ? Qt2 : Qt)):-1;
}

string Ytv(string e) {
    std::reverse(e.begin(), e.end());
    return e;
}

string Ytr(string e1, long t) {
    long n;
    const long size = e1.length();
    std:vector<char> i = std::vector<char>(e1.length());
    strcpy(i.data(), e1.c_str());
    for (long a = size; a--; )
        if (~(n = QTIndex(true,i[a])))
            (i[a] = Qt2[n - t]);
    string return_ = string(i.data());
    return return_;
}

long* function_i(string e, long t) {
    long n = e.length();
    long* i = new long[(long long)n + 1];
    if (n) {
        long a = n;
        for (t = abs(t); a--; ) {
            t = (n * (a + 1) ^ t + a) % n;
            i[a] = t;
        }
    }
    return i;
}
string Yts(string e1, long t) {
    const long n = e1.length();
    if (n) {
        long* i = function_i(e1, t);
        char* e = new char[(long long)n + 1];
        strcpy(e, e1.data());
        for (long a = 0;++a < n; ) {
            //swap e[] items 
            char item = e[a];
            e[a] = e[i[n - 1 - a]];
            e[i[n - 1 - a]] = item;
        }
        delete[]i;
        e1 = string(e);
        delete[]e;
    }
    return e1;
}

string Yti(string e, long t) {
    return Yts(e, t ^ id);
}
void get_splited(string* a, string find) {

    const long extra_find = find.find("?extra=");
    string finds = find.substr(extra_find + 7);

    const long index = finds.find("#");
    a[0] = finds.substr(0, index);
    a[1] = finds.substr(index + 1);
}
std::vector<string>* get_splited_from_char_to_array(string e, long& length, char sym) {
    std::vector<string> *answer = new vector<string> { "" };
    length = 1;
    for (long i = 0;i < e.length();i++) {
        char it = e.at(i);
        if (it == sym) {
            answer->insert(answer->end(), "");
            length++;
            continue;
        }
        answer->at(length - 1) += it;
    }
    return answer;
}

string Kt(string e) {
    if (e.empty() || e.length() % 4 == 1)
        return "";
    stringstream answer;
    char n;
    long t, n_int, i = 0, a = 0;
    for (; a < e.length() && (n = e.at(a++)); )
        if((n_int = QTIndex(false, n)) != -1){
            if(t = i % 4 ? 64 * t + n_int : n_int, i++ % 4)
                answer << (char)(255 & t >> (-2 * i & 6));
        }
    return answer.str();
}

string Gt(string e) {
    if (~e.find("audio_api_unavailable")) {

        string i[2];

        string n[2];

        get_splited(i, e);

        if (i[1] != "") i[1] = Kt(i[1]);

        if (i[0] = Kt(i[0]), i[1].empty() || i[0].empty()) return e;

        long o;

        //delete after using

        vector<string> *a = get_splited_from_char_to_array(i[1], o, 9);

        for (;o--;) {
            string ch = a->at(o);
            bool b = false;
            for (long _ = 0;_ < ch.length();_++) {
                char item = ch.at(_);
                if (item == (char)11) {
                    b = true;
                    continue;
                }
                n[b] += ch.at(_);
            }
            char t = n[0].at(0);
            n[0] = i[0];
            switch (t)
            {
                case 'i':i[0] = Yti(n[0], std::stol(n[1]));break;
                case 's':i[0] = Yts(n[0], std::stol(n[1]));break;
                case 'v':i[0] = Yts(n[0], std::stol(n[1]));break;
                case 'r':i[0] = Ytr(n[0], std::stol(n[1]));break;
                default:
                    delete a;
                    return e;

            }

        }
        if (i[0] != "" && "http" == i[0].substr(0, 4)) {
            delete a;
            return i[0];
        }
        delete a;
    }
    return e;
}

void m3u8ToMp3(string& url) {

    bool b = false;

    long m3u8 = url.find("/index.m3u8");

    if (m3u8 != -1) {

        url = url.replace(m3u8, 11, ".mp3");

        for (long to = -1, i = m3u8;i >= 0;i--) {

            if (url.at(i) == '/') {

                if (to == -1)

                    to = i;

                else {

                    url.erase(i + 1, to - i);

                    break;

                }

            }

        }

    }

}

#ifdef _DEBUG

int main(void) {
    long size = sizeof(__argv) / sizeof(*__argv);
    string url;
    if (size != 2) {
        //getting url and id
        cout << "Please enter url to decode:\n";
        cin >> url;

        cout << "Please enter user-id: ";
        cin >> id;
    }
    else {
        url = __argv[0];
        try {
            id = stoi(__argv[1]);
        }catch (std::out_of_range ex) {
            cout << "Second parametr have to be a number";
            exit(-1);
        }
    }
    string answer = Gt(url);
    m3u8ToMp3(answer);

    cout << answer;

    return 0;
}

#else
EXPORT const char* decode(const char* url, const bool need_mp3 = true) {
    string answer;
    try {
        answer = string(url);
        answer = Gt(answer);
    }
    catch (exception e) {}
    if (need_mp3)m3u8ToMp3(answer);
    char* e = new char[answer.length()];
    strcpy(e, answer.c_str());
    return e;
}
EXPORT void setUserId(long i) {
    id = i;
}
EXPORT char* toMP3(const char* url) {
    string ans = string(url);
    //char* answ = new char[ans.length()];
    //strcpy( answ,ans.data());
    //return answ;
    m3u8ToMp3(ans);
    char* e = new char[ans.length()];
    strcpy(e, ans.c_str());
    return e;
}

#endif

//compile - g++ -shared -fPIC vk-audio-url-decoder.cpp -o lib.so -rdynamic 

